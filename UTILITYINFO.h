#ifndef UTILITYINFO_H
#define UTILITYINFO_H

//Opens a Message Box containing the EXE path.
void showPath(HWND hwnd) {
	char szFileName[MAX_PATH];
	HINSTANCE hInstance = GetModuleHandle(NULL);
	
	GetModuleFileName(hInstance, szFileName, MAX_PATH);
	MessageBox(hwnd, szFileName, "Program Path: ", MB_OK | MB_ICONINFORMATION);
}

//Closes the window whose handler is passed through hwnd
void closeWindow(HWND hwnd) {
	PostMessage(hwnd, WM_CLOSE, 0, 0);
}

#endif