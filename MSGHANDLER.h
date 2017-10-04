#ifndef MSGHANDLER_H
#define MSG_HANDLER_H
#include <windows.h>
#include "INPUTHANDLER.h"
#include "RESOURCE.h"

char mouseButton;

//Handle user input. The function WndProc is ESSENTIAL to all Windows Applications.
//Please do not screw around with this. Handle each case in the INPUTHANDLER header, not here.
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		
		case WM_CREATE:
			createMenus(hwnd, msg, wParam, lParam);
			break;	
		case WM_COMMAND:
			handleMenuCommands(hwnd, msg, wParam, lParam);
		case WM_LBUTTONDOWN:
			LeftMouseButtonDown(hwnd, msg, wParam, lParam);
			mouseButton = 'l';
			break;
		case WM_RBUTTONDOWN:
			RightMouseButtonDown(hwnd, msg, wParam, lParam);
			mouseButton = 'r';
			break;
		case WM_MBUTTONDOWN:
			mouseButton = 'm';
			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

#endif