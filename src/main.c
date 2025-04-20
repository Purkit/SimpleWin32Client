#if defined (_MSC_VER)
#include <Windows.h>
#endif
#if defined (__MINGW32__)
#include <windows.h>
#endif

LRESULT CALLBACK WindowProc(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam) {

    switch (message) {
        case WM_SIZE: {
        } break;

        case WM_DESTROY:{
            PostQuitMessage(0);
            return 0;
        } break;

        case WM_CLOSE: {
            // when x button is clicked
        } break;

        default: return DefWindowProc(window_handle, message, wParam, lParam);
    }

    return 0;
}


int APIENTRY WinMain(HINSTANCE Instance, HINSTANCE PrevInstance,
                     LPSTR CommandLineArgsStr, int CmdShow) {
    const char CLASS_NAME[] = "SampleWindowClass";

    WNDCLASSEX wc = {0};

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc   = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance     = Instance;
    wc.lpszClassName = CLASS_NAME;
    wc.hIcon = NULL;
    wc.hCursor       = NULL;
    wc.hbrBackground = NULL;
    wc.lpszMenuName = NULL;

    if (!RegisterClassEx(&wc)) {
        return 0; // Registration failed
    }

    HWND hwnd = CreateWindowEx(0,                     // Extended styles
                               CLASS_NAME,            // Window class
                               "Simple Win32 Window", // Window title
                               WS_OVERLAPPEDWINDOW,   // Window style
                               CW_USEDEFAULT, CW_USEDEFAULT,
                               1000, 800,
                               NULL,          // Parent window
                               NULL,          // Menu
                               Instance,     // Instance handle
                               NULL           // Additional data
    );

    if (hwnd == NULL) {
        return 0; // Window creation failed
    }

    // Show the window
    ShowWindow(hwnd, CmdShow);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
