/*
* C++ 3D graphics engine under Direct3D 11. Developed in a Planet Chili video tutorial series that can be found on YouTube. https://youtu.be/_4FArgOX1I4
* 
* This program was developed to study Hardware 3D DirectX Programming.
* All of this was learned from "planetchili", and the copyright belongs to him.
* 
* Some comments may seem stupid to senior programmers.
* But that's what I wrote down to learn programming.
*/

#include <Windows.h>

LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch ( msg )
	{
	case WM_CLOSE:
		PostQuitMessage( 69 );
		break;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam );
}


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow )
{
	/*
	* To make windows, need to
	* 1) register window class
	* 2) create window instance
	*/

	// 1) register window class

	const auto pClassName = "hw3dThings";

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof( wc );
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc; // DefWindowProc -> WndProc
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	/*
	* RegisterClassEX register window classand it's a ex ver.
	* It takes pointer of WNDCLASSEX
	*/
	RegisterClassEx( &wc );	

	// create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);

	// show the window
	ShowWindow( hWnd, SW_SHOW );

	// Message pump
	MSG msg;
	BOOL gResult;
	while ( (gResult = GetMessage( &msg, nullptr, 0, 0 )) > 0  )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	if ( gResult == -1 )
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
	return 0;
}