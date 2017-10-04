#ifndef DLGUTILITY_H
#define DLGUTILITY_H

void OKCANCELFUNCTION(HWND hwnd, WPARAM wParam) {
	switch(LOWORD(wParam)) {
		case IDOK:
			EndDialog(hwnd, IDOK);
			break;
		case IDCANCEL:
			EndDialog(hwnd, IDCANCEL);
			break;
	}
}


#endif