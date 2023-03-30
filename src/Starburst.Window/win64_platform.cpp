#include<windows.h>
#include "Renderer.h"
#include "RenderState.h"
#include "ButtonState.h"

bool running = true;

RenderState renderState;
Input inputs;

LRESULT window_callback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_CLOSE:
	case WM_DESTROY:
		running = false;
		break;
	case WM_SIZE: {
		RECT rectangle;
		GetClientRect(hwnd, &rectangle);
		renderState.Width = rectangle.right - rectangle.left;
		renderState.Height = rectangle.bottom - rectangle.top;

		int bufferSize = renderState.Width * renderState.Height * sizeof(unsigned int);

		if (renderState.Memory) {
			VirtualFree(renderState.Memory, 0, MEM_RELEASE);
		}
		renderState.Memory = VirtualAlloc(0, bufferSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		renderState.BitmapInfo.bmiHeader.biSize = sizeof(renderState.BitmapInfo.bmiHeader);
		renderState.BitmapInfo.bmiHeader.biWidth = renderState.Width;
		renderState.BitmapInfo.bmiHeader.biHeight = renderState.Height;
		renderState.BitmapInfo.bmiHeader.biPlanes = 1;
		renderState.BitmapInfo.bmiHeader.biBitCount = 32;
		renderState.BitmapInfo.bmiHeader.biCompression = BI_RGB;
	}
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}	
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Window";
	window_class.lpfnWndProc = window_callback;

	RegisterClass(&window_class);

	HWND window = CreateWindow(window_class.lpszClassName, window_class.lpszClassName, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
	HDC hdc = GetDC(window);

	Renderer renderer(&renderState);

	while (running) {
		MSG message;
		for (int i = 0; i < ButtonCount; i++) {
			inputs.Buttons[i].Changed = false;
		}
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {

			switch (message.message) {
			case WM_KEYUP:
			case WM_KEYDOWN: {
				unsigned int vkCode = (unsigned int)message.wParam;
				bool isDown = ((message.lParam & (1 << 31)) == 0);

				switch (vkCode) {
				case VK_UP: {
					inputs.Buttons[ButtonUp].IsDown = isDown;
					inputs.Buttons[ButtonUp].Changed = true;
				}break;
				}
			}break;
			default:
				TranslateMessage(&message);
				DispatchMessage(&message);
			}			
		}

		renderer.ClearScreen(0x000000);
		if (inputs.Buttons[ButtonUp].IsDown) {
			renderer.DrawRectangle(-5, 10, 10, 10, 0x11ff22);
		}
		
		renderer.DrawRectangle(-25, -30, 10, 5, 0xff0022);
		renderer.DrawRectangle(70, 7, 10, 4, 0xffff00);
		//renderer.DrawRectanglePixels(100, 100, 252, 340, 0x00ff22);

		StretchDIBits(hdc, 0, 0, renderState.Width, renderState.Height, 0, 0, renderState.Width, renderState.Height, renderState.Memory, &renderState.BitmapInfo, DIB_RGB_COLORS, SRCCOPY);

	}
}