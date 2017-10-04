#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "UTILITYINFO.h"
#include "RESOURCE.h"
#include "USERDEF.h"
#include "DLGHANDLER.h"

//These functions contain code that will execute when the user provides the corresponding input - when the user presses the left mouse button, the code in LeftMouseButtonDown() will execute
void LeftMouseButtonDown();
void RightMouseButtonDown();
void createMenus();
void handleMenuCommands();

//Create menus (obviously)
void createMenus(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
}

//Bring some life to your menus
void handleMenuCommands(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(LOWORD(wParam)) {
		case ID_FILE_EXIT:
			
			closeWindow(hwnd);
			
			break;
			
		case ID_JUNK_YEE:
			
			break;
		case ID_HELP_ABOUT:
				{
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUT), hwnd, (DLGPROC)AboutDlgProc);
					if(ret == IDOK){
						MessageBox(hwnd, "Dialog exited with IDOK.", "Notice",
							MB_OK | MB_ICONINFORMATION);
					}
					else if(ret == IDCANCEL){
						MessageBox(hwnd, "Dialog exited with IDCANCEL.", "Notice",
							MB_OK | MB_ICONINFORMATION);
					}
					else if(ret == -1){
						MessageBox(hwnd, "Dialog failed!", "Error",
							MB_OK | MB_ICONINFORMATION);
					}
				}
			break;
	}
}

//What will happen if the Left Mouse Button is pressed
void LeftMouseButtonDown(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	showPath(hwnd);
}

//What will happen if the Right Mouse Button is pressed
void RightMouseButtonDown(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
}

#endif