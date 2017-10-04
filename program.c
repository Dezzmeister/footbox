#include <windows.h>
#include <stdio.h>
#include "consts.h"
#include "dmath.h"
#include "println.h"
#include "CREATEWINDOW.h"
//#include "dgraphics/RESOURCE.h"

EssentialWinData paramData;

int initialized = FALSE;

char windowTitle[] = "A Windows Program";

void preInit() {
	if (!initialized) {
		//Methods that only run once belong in here
		
		LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_DONBOSCO));
		
		createWindow(paramData,	500, 500, windowTitle);
		
		initialized = TRUE;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	MSG Msg;
	HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FACEICON));
	
	//Update paramData
	paramData.hInstance = hInstance;
	paramData.hPrevInstance = hPrevInstance;
	paramData.lpCmdLine = lpCmdLine;
	paramData.nCmdShow = nCmdShow;
	
	preInit();
	
	
	
	/* Message Loop Below - DO NOT TOUCH */
	
	while (GetMessage(&Msg, NULL, 0, 0) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	
	/* Message Loop Above - DO NOT TOUCH */
	
	return Msg.wParam;
}