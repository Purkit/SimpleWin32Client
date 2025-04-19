#include <Windows.h>

// Window procedure function prototype
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Entry point of the application
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine, int nCmdShow) {
    // Register the window class
    const char CLASS_NAME[] = "SampleWindowClass";

    WNDCLASS wc = {0};

    wc.lpfnWndProc   = WindowProc;                  // Window procedure
    wc.hInstance     = hInstance;                   // Handle to the instance
    wc.lpszClassName = CLASS_NAME;                  // Class name
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW); // Cursor type

    if (RegisterClass(&wc) == 0) {
        return 0; // Registration failed
    }

    // Create the window
    HWND hwnd = CreateWindowEx(0,                     // Extended styles
                               CLASS_NAME,            // Window class
                               "Simple Win32 Window", // Window title
                               WS_OVERLAPPEDWINDOW,   // Window style
                               CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                               CW_USEDEFAULT, // Size and position
                               NULL,          // Parent window
                               NULL,          // Menu
                               hInstance,     // Instance handle
                               NULL           // Additional data
    );

    if (hwnd == NULL) {
        return 0; // Window creation failed
    }

    // Show the window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// Window procedure function
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY: PostQuitMessage(0); return 0;

    default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}
