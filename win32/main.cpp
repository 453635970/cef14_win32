#define NOMINMAX

#include <windows.h>
#include <tchar.h>
#include "include/cef_app.h"
#include "include/cef_browser.h"
#include "include/cef_client.h"
#include "include/wrapper/cef_helpers.h"

#if defined(_DEBUG)
// Debug模式：链接Debug版本的库
#pragma comment(lib, "lib/libcef_dll_wrapper.lib")  // Debug版包装库
#pragma comment(lib, "lib/libcef.lib")              // Debug版CEF核心库
#else
// Release模式：链接Release版本的库
#pragma comment(lib, "lib/libcef_dll_wrapper.lib")  // Release版包装库
#pragma comment(lib, "lib/libcef.lib")              // Release版CEF核心库
#endif

// 调试输出宏
#define DEBUG_LOG(message) OutputDebugStringA(message); OutputDebugStringA("\n")
#define DEBUG_LOG_ID(id, message) { \
    char buf[256]; \
    sprintf_s(buf, "%d: %s", id, message); \
    OutputDebugStringA(buf); \
    OutputDebugStringA("\n"); \
}


// 客户端处理类：实现浏览器生命周期、加载事件等回调
class EmbeddedClient : public CefClient,
	public CefLifeSpanHandler,
	public CefLoadHandler,
	public CefDisplayHandler
{
public:
	EmbeddedClient() : m_browser(nullptr) {}

	// 重写CefClient的回调处理器
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override
	{
		return this;
	}
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override
	{
		return this;
	}
	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override
	{
		return this;
	}

	// 浏览器创建后回调
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) override
	{
		CEF_REQUIRE_UI_THREAD();

		int browser_id = browser->GetIdentifier(); // 获取浏览器唯一ID
		DEBUG_LOG_ID(browser_id, "OnAfterCreated: Adding browser to list");
		auto it = std::find(m_browsers.begin(), m_browsers.end(), browser);
		if (it == m_browsers.end())
		{
			m_browsers.push_back(browser);

			//m_browser = browser->GetHost();
			m_browser = browser; 
			DEBUG_LOG_ID(browser_id, "Browser added to list successfully");
		}
	}

	// 浏览器即将关闭时回调（子进程清理完成后触发）
	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) override
	{
		CEF_REQUIRE_UI_THREAD();

		std::vector<CefRefPtr<CefBrowser>>::iterator it;
		for (it = m_browsers.begin(); it != m_browsers.end(); ++it)
		{
			CefRefPtr<CefBrowser> br1 = *it;
			if (br1->IsValid() && br1->IsSame(browser))
			{
				m_browsers.erase(it);
				break;
			}
		}
		//所有的浏览器都关闭了 
		if (m_browsers.empty())
			CefQuitMessageLoop();
	}

	// 浏览器关闭回调
	virtual bool DoClose(CefRefPtr<CefBrowser> browser) override
	{
		CEF_REQUIRE_UI_THREAD();
		// 如果这是最后一个浏览器实例，允许关闭
		return !m_browsers.empty() && m_browsers.size() > 1;
	}

	// 页面加载完成回调
	virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, int httpStatusCode) override
	{
		CEF_REQUIRE_UI_THREAD();
		if (frame->IsMain())
		{
			// 主框架加载完成，可执行JS注入等操作
			frame->ExecuteJavaScript("console.log('Chromium 140 embedded successfully!');",
				frame->GetURL(), 0);
		}
	}

	// 标题变化回调
	virtual void OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title) override
	{
		CEF_REQUIRE_UI_THREAD();
		// 更新窗口标题
		HWND hWnd = browser->GetHost()->GetWindowHandle();
		if (hWnd) {
			//SetWindowText(hWnd, title.c_str());
		}
	}

	void CloseAllBrowsers(bool force_close)
	{
		CEF_REQUIRE_UI_THREAD();
		for (auto& tbrowser : m_browsers)
		{
			//	if (browser->IsValid() && browser->GetHost())
			tbrowser->GetHost()->CloseBrowser(force_close);
		}

	}
	// 获取当前浏览器实例
	CefRefPtr<CefBrowser> GetBrowser() const
	{
		return m_browser;
	}

	// 跟踪所有浏览器实例
	std::vector<CefRefPtr<CefBrowser>> m_browsers;

	HWND m_main_hwnd;

private:
	CefRefPtr<CefBrowser> m_browser; // 浏览器实例

	IMPLEMENT_REFCOUNTING(EmbeddedClient); // CEF引用计数宏
};

// 全局客户端实例
CefRefPtr<EmbeddedClient> g_client;

// Win32窗口过程
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		RECT rect;
		GetClientRect(hWnd, &rect);
		// 正确计算宽高：右边界-左边界=宽度，下边界-上边界=高度
		CefRect cefRect(
			rect.left,
			rect.top,
			rect.right - rect.left,  // 宽度
			rect.bottom - rect.top   // 高度
		);
		CefWindowInfo windowInfo;
		windowInfo.SetAsChild(hWnd, cefRect); // 绑定到正确的客户区尺寸
		windowInfo.runtime_style = CEF_RUNTIME_STYLE_DEFAULT;

		CefBrowserSettings browserSettings;
		CefBrowserHost::CreateBrowser(windowInfo, g_client, "https://baidu.com",
			browserSettings, nullptr, nullptr);
	}

	case WM_SIZE:
	{
		if (g_client && g_client->GetBrowser())
		{
			CefRefPtr<CefBrowserHost> host = g_client->GetBrowser()->GetHost();
			if (host)
			{
				host->WasResized(); // 通知CEF尺寸变化
				host->Invalidate(CefBrowserHost::PaintElementType::PET_VIEW); // 重绘整个视图
			}
		}
		return 0;
	}

	case WM_CLOSE:
		if (g_client)
		{
			g_client->CloseAllBrowsers(true);
		}
		//	DestroyWindow(hWnd);
		return 0;


	case WM_DESTROY:
		// 释放全局客户端引用
		g_client = nullptr;
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

// CEF应用程序类
class EmbeddedApp : public CefApp, public CefBrowserProcessHandler
{
public:
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override
	{
		return this;
	}

	// CEF初始化完成后创建主窗口
	virtual void OnContextInitialized() override
	{
		CEF_REQUIRE_UI_THREAD();

		// 注册窗口类
		WNDCLASSEX wc = {
			sizeof(WNDCLASSEX), CS_CLASSDC, MainWndProc,
			0L, 0L, GetModuleHandle(nullptr), nullptr,
			nullptr, nullptr, nullptr,
			_T("ChromiumEmbedClass"), nullptr
		};
		RegisterClassEx(&wc);

		HWND hWnd = CreateWindowEx(
			0, _T("ChromiumEmbedClass"), _T("Chromium140"),
			WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN, 100, 100, 1000, 800,
			nullptr, nullptr, wc.hInstance, nullptr);

		if (hWnd) 
		{
			ShowWindow(hWnd, SW_SHOWDEFAULT);
			UpdateWindow(hWnd);
		}
	}

private:
	IMPLEMENT_REFCOUNTING(EmbeddedApp);
};










// 程序入口
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// 初始化CEF参数
	CefMainArgs mainArgs(hInstance);
	CefRefPtr<EmbeddedApp> app(new EmbeddedApp);
	g_client = new EmbeddedClient();

	// 检查CEF子进程
	int exitCode = CefExecuteProcess(mainArgs, app.get(), nullptr);
	if (exitCode >= 0) {
		return exitCode;
	}

	// 配置CEF全局设置
	CefSettings settings;
	settings.no_sandbox = true; // 开发环境禁用沙箱（生产环境需启用）
	settings.multi_threaded_message_loop = false; // 启用多线程消息循环
	TCHAR exePath[MAX_PATH];
	GetModuleFileName(nullptr, exePath, MAX_PATH);
	CefString(&settings.browser_subprocess_path) = exePath;

	//CEF_RUNTIME_STYLE_DEFAULT
	// 
	// 初始化CEF
	if (!CefInitialize(mainArgs, settings, app.get(), nullptr))
	{
		MessageBox(nullptr, L"CEF initialization failed!", L"Fatal Error", MB_ICONSTOP);
		return 1;
	}

	CefRunMessageLoop();
	CefShutdown();
	return 0;
}
