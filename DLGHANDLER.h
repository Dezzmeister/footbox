#ifndef DLGHANDLER_H
#define DLGHANDLER_H
#include <windows.h>
#include "DLGUTILITY.h"

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	
	switch (Message) {
		case WM_INITDIALOG:
		
			return TRUE;
		case WM_COMMAND:
			OKCANCELFUNCTION(hwnd, wParam);
			break;
		default:
			return FALSE;
	}
	return TRUE;
}

#endif