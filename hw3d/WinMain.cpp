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
	wc.lpfnWndProc = DefWindowProc;
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

	while (true);

	return 0;
}