// calculator_gui.c
#include <windows.h>
#include <stdio.h>

#define BTN_ADD 1
#define BTN_SUB 2
#define BTN_MUL 3
#define BTN_DIV 4

HWND inputA, inputB, resultLabel;

void calculate(HWND hwnd, int operation) {
    char textA[100];
    char textB[100];
    char output[100];

    double a, b, result;

    GetWindowText(inputA, textA, sizeof(textA));
    GetWindowText(inputB, textB, sizeof(textB));

    a = atof(textA);
    b = atof(textB);

    switch (operation) {
        case BTN_ADD:
            result = a + b;
            break;
        case BTN_SUB:
            result = a - b;
            break;
        case BTN_MUL:
            result = a * b;
            break;
        case BTN_DIV:
            if (b == 0) {
                SetWindowText(resultLabel, "Error: Division by zero");
                return;
            }
            result = a / b;
            break;
        default:
            return;
    }

    sprintf(output, "Result: %.2f", result);
    SetWindowText(resultLabel, output);
}

LRESULT CALLBACK WindowProcedure(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam
) {
    switch (msg) {
        case WM_CREATE:
            CreateWindow(
                "STATIC",
                "First number:",
                WS_VISIBLE | WS_CHILD,
                20, 20, 120, 25,
                hwnd, NULL, NULL, NULL
            );

            inputA = CreateWindow(
                "EDIT",
                "",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                140, 20, 150, 25,
                hwnd, NULL, NULL, NULL
            );

            CreateWindow(
                "STATIC",
                "Second number:",
                WS_VISIBLE | WS_CHILD,
                20, 60, 120, 25,
                hwnd, NULL, NULL, NULL
            );

            inputB = CreateWindow(
                "EDIT",
                "",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                140, 60, 150, 25,
                hwnd, NULL, NULL, NULL
            );

            CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD, 20, 110, 60, 30, hwnd, (HMENU)BTN_ADD, NULL, NULL);
            CreateWindow("BUTTON", "-", WS_VISIBLE | WS_CHILD, 90, 110, 60, 30, hwnd, (HMENU)BTN_SUB, NULL, NULL);
            CreateWindow("BUTTON", "*", WS_VISIBLE | WS_CHILD, 160, 110, 60, 30, hwnd, (HMENU)BTN_MUL, NULL, NULL);
            CreateWindow("BUTTON", "/", WS_VISIBLE | WS_CHILD, 230, 110, 60, 30, hwnd, (HMENU)BTN_DIV, NULL, NULL);

            resultLabel = CreateWindow(
                "STATIC",
                "Result:",
                WS_VISIBLE | WS_CHILD,
                20, 160, 270, 25,
                hwnd, NULL, NULL, NULL
            );

            break;

        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case BTN_ADD:
                case BTN_SUB:
                case BTN_MUL:
                case BTN_DIV:
                    calculate(hwnd, LOWORD(wParam));
                    break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
    WNDCLASS wc = {0};

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = "CalculatorWindowClass";

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
        "CalculatorWindowClass",
        "C GUI Calculator",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        340,
        260,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}