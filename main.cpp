
#define NOMINMAX

#include "framework.h"
#include "cef14.h"
#include "include/cef_command_line.h"
#include "include/cef_sandbox_win.h"
#include "include/cef_version_info.h"
#include "SDK/simple_app.h"


#if defined(_DEBUG)
// Debug模式：链接Debug版本的库
#pragma comment(lib, "cef_binary_140.1.14/lib/libcef_dll_wrapper.lib")  // Debug版包装库
#pragma comment(lib, "cef_binary_140.1.14/lib/libcef.lib")              // Debug版CEF核心库
#else
// Release模式：链接Release版本的库
#pragma comment(lib, "cef_binary_140.1.14/lib/libcef_dll_wrapper.lib")  // Release版包装库
#pragma comment(lib, "cef_binary_140.1.14/lib/libcef.lib")              // Release版CEF核心库
#endif



int RunMain(HINSTANCE hInstance,
	LPTSTR lpCmdLine,
	int nCmdShow,
	void* sandbox_info)
{
	int exit_code;

	// Provide CEF with command-line arguments.
	CefMainArgs main_args(hInstance);

	// CEF applications have multiple sub-processes (render, GPU, etc) that share
	// the same executable. This function checks the command-line and, if this is
	// a sub-process, executes the appropriate logic.
	exit_code = CefExecuteProcess(main_args, nullptr, sandbox_info);
	if (exit_code >= 0) {
		// The sub-process has completed so return here.
		return exit_code;
	}

	// Parse command-line arguments for use in this method.
	CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
	command_line->InitFromString(::GetCommandLineW());

	// Specify CEF global settings here.
	CefSettings settings;

	if (!sandbox_info) {
		settings.no_sandbox = true;
	}

	// SimpleApp implements application-level callbacks for the browser process.
	// It will create the first browser instance in OnContextInitialized() after
	// CEF has initialized.
	CefRefPtr<SimpleApp> app(new SimpleApp);

	// Initialize the CEF browser process. May return false if initialization
	// fails or if early exit is desired (for example, due to process singleton
	// relaunch behavior).
	if (!CefInitialize(main_args, settings, app.get(), sandbox_info)) {
		return CefGetExitCode();
	}

	// Run the CEF message loop. This will block until CefQuitMessageLoop() is
	// called.
	CefRunMessageLoop();

	// Shut down CEF.
	CefShutdown();

	return 0;
}



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	// 32位CEF优化
	int exit_code = CefRunWinMainWithPreferredStackSize(wWinMain, hInstance, lpCmdLine, nCmdShow);
	if (exit_code >= 0)
		return exit_code;

	void* sandbox_info = nullptr;
	//沙箱
	//CefScopedSandboxInfo scoped_sandbox;
	//sandbox_info = scoped_sandbox.sandbox_info();


	return ::RunMain(hInstance, lpCmdLine, nCmdShow, sandbox_info);
}


