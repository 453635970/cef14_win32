// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
#define NOMINMAX

#include "simple_app.h"

#include <string>

#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/views/cef_browser_view.h"
#include "include/views/cef_window.h"
#include "include/wrapper/cef_helpers.h"
#include "simple_handler.h"

namespace {

// When using the Views framework this object provides the delegate
// implementation for the CefWindow that hosts the Views-based browser.
class SimpleWindowDelegate : public CefWindowDelegate
{
 public:
  SimpleWindowDelegate(CefRefPtr<CefBrowserView> browser_view,
                       cef_runtime_style_t runtime_style,
                       cef_show_state_t initial_show_state)
      : browser_view_(browser_view),
        runtime_style_(runtime_style),
        initial_show_state_(initial_show_state) {}

  void OnWindowCreated(CefRefPtr<CefWindow> window) override 
  {
    // Add the browser view and show the window.
    window->AddChildView(browser_view_);

    if (initial_show_state_ != CEF_SHOW_STATE_HIDDEN) 
    {
      window->Show();
    }
  }

  void OnWindowDestroyed(CefRefPtr<CefWindow> window) override
  {
    browser_view_ = nullptr;
  }

  bool CanClose(CefRefPtr<CefWindow> window) override 
  {
    // Allow the window to close if the browser says it's OK.
    CefRefPtr<CefBrowser> browser = browser_view_->GetBrowser();
    if (browser) {
      return browser->GetHost()->TryCloseBrowser();
    }
    return true;
  }

  CefSize GetPreferredSize(CefRefPtr<CefView> view) override 
  {
    return CefSize(1000, 1000);
  }

  cef_show_state_t GetInitialShowState(CefRefPtr<CefWindow> window) override
  {
    return initial_show_state_;
  }

  cef_runtime_style_t GetWindowRuntimeStyle() override 
  {
    return runtime_style_;
  }

 private:
  CefRefPtr<CefBrowserView> browser_view_;// 关联的浏览器视图
  const cef_runtime_style_t runtime_style_;// 窗口运行时样式
  const cef_show_state_t initial_show_state_;//窗口初始显示状态

  IMPLEMENT_REFCOUNTING(SimpleWindowDelegate);
  DISALLOW_COPY_AND_ASSIGN(SimpleWindowDelegate);
};

class SimpleBrowserViewDelegate : public CefBrowserViewDelegate 
{
     public:
      explicit SimpleBrowserViewDelegate(cef_runtime_style_t runtime_style)
          : runtime_style_(runtime_style) {}

      bool OnPopupBrowserViewCreated(CefRefPtr<CefBrowserView> browser_view,
                                     CefRefPtr<CefBrowserView> popup_browser_view,
                                     bool is_devtools) override 
      {
          // 1. 为弹出窗口创建“顶级窗口”，并绑定 SimpleWindowDelegate 管理其行为
        CefWindow::CreateTopLevelWindow(new SimpleWindowDelegate(
            popup_browser_view, runtime_style_, CEF_SHOW_STATE_NORMAL));

        // 若返回 false，CEF 会使用默认的弹出窗口逻辑
        return true;
      }

      cef_runtime_style_t GetBrowserRuntimeStyle() override 
      {
        return runtime_style_;
      }

     private:
      const cef_runtime_style_t runtime_style_;

      IMPLEMENT_REFCOUNTING(SimpleBrowserViewDelegate);
      DISALLOW_COPY_AND_ASSIGN(SimpleBrowserViewDelegate);
};

}

SimpleApp::SimpleApp() = default;
//--use-native --use-alloy-style --url=https://www.baidu.com
void SimpleApp::OnContextInitialized() 
{
  CEF_REQUIRE_UI_THREAD();

  //获取全局命令行参数对象，用于读取启动时传入的参数（如--url、--use-alloy-style等）
  CefRefPtr<CefCommandLine> command_line = CefCommandLine::GetGlobalCommandLine();
    
  // 运行时风格配置
  cef_runtime_style_t runtime_style = CEF_RUNTIME_STYLE_DEFAULT;
  bool use_alloy_style = command_line->HasSwitch("use-alloy-style");
  if (use_alloy_style) {
    runtime_style = CEF_RUNTIME_STYLE_ALLOY;
  }

  //浏览器回调处理器
  CefRefPtr<SimpleHandler> handler(new SimpleHandler(use_alloy_style));

  // Specify CEF browser settings here.
  CefBrowserSettings browser_settings;

  std::string url;

  //浏览器设置与初始 URL
  url = command_line->GetSwitchValue("url");
  if (url.empty()) {
    url = "https://www.baidu.com";
  }


  // UI 框架选择（Views vs 原生） (add `--use-native` to disable).
  //--use - native参数控制：若存在该参数则使用原生框架，否则默认使用 Views 框架。
  const bool use_views = !command_line->HasSwitch("use-native");

  // 使用 Views 框架
  if (use_views) 
  {
    // // 创建BrowserView（浏览器视图组件）
    CefRefPtr<CefBrowserView> browser_view = CefBrowserView::CreateBrowserView(
        handler, url, browser_settings, nullptr, nullptr,
        new SimpleBrowserViewDelegate(runtime_style));

    // 配置初始窗口显示状态（正常/最小化/最大化，Mac支持隐藏）
    cef_show_state_t initial_show_state = CEF_SHOW_STATE_NORMAL;
    const std::string& show_state_value =
        command_line->GetSwitchValue("initial-show-state");
    if (show_state_value == "minimized") {
      initial_show_state = CEF_SHOW_STATE_MINIMIZED;
    } else if (show_state_value == "maximized") {
      initial_show_state = CEF_SHOW_STATE_MAXIMIZED;
    }
#if defined(OS_MAC)
    // Hidden show state is only supported on MacOS.
    else if (show_state_value == "hidden") {
      initial_show_state = CEF_SHOW_STATE_HIDDEN;
    }
#endif

    //创建顶级窗口并显示
    CefWindow::CreateTopLevelWindow(new SimpleWindowDelegate(
        browser_view, runtime_style, initial_show_state));
  } 
  else
  { //使用原生框架创建窗口
     
    CefWindowInfo window_info;

#if defined(OS_WIN)
    // On Windows we need to specify certain flags that will be passed to
    // CreateWindowEx().
    window_info.SetAsPopup(nullptr, "cefsimple");
#endif

    // Alloy style will create a basic native window. Chrome style will create a
    // fully styled Chrome UI window.
    window_info.runtime_style = runtime_style;

    // Create the first browser window.
    CefBrowserHost::CreateBrowser(window_info, handler, url, browser_settings,  nullptr, nullptr);                            
  }
}

CefRefPtr<CefClient> SimpleApp::GetDefaultClient() 
{
  // Called when a new browser window is created via Chrome style UI.
  return SimpleHandler::GetInstance();
}
