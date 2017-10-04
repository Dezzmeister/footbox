#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H
#include <windows.h>
#include "MSGHANDLER.h"
#include "RESOURCE.h"

const char g_szClassName[] = "myWindowClass";

int screenWidth;
int screenHeight;

int windowX = CW_USEDEFAULT;
int windowY = CW_USEDEFAULT;
int windowWidth = 500;
int windowHeight = 500;

typedef struct {
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPSTR lpCmdLine;
	int nCmdShow;
} EssentialWinData;

int createWindow(EssentialWinData instances, int width, int height, const char title[]) {
	
	//Read necessary data from the EssentialWinData typedef
	HINSTANCE hInstance = instances.hInstance;
	HINSTANCE hPrevInstance = instances.hPrevInstance;
	LPSTR lpCmdLine = instances.lpCmdLine;
	int nCmdShow = instances.nCmdShow;
	
	//Get the window size and location
	
	windowWidth 	= width;
	windowHeight 	= height;
	
	//Get the screen size
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	//Center the window
	windowX 		= (screenWidth/2)-(width/2);
	windowY			= (screenHeight/2)-(height/2);
	
	WNDCLASSEX wc;
	HWND hwnd;
	
	//Register size of Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_FACEICON));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_TESTMENU);
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDI_FACEICON), IMAGE_ICON, 32, 32, 0);
	
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	
	//Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		title,
		(WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_HSCROLL | WS_VSCROLL),
		windowX, windowY, windowWidth, windowHeight,
		NULL, NULL, hInstance, NULL
	);
	
	if (hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed! Oh No!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
}

#endif