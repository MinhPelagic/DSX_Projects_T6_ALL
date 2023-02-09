/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2017  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.44 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to STMicroelectronics International
N.V. a Dutch company with a Swiss branch and its headquarters in Plan-
les-Ouates, Geneva, 39 Chemin du Champ des Filles, Switzerland for the
purposes of creating libraries for ARM Cortex-M-based 32-bit microcon_
troller products commercialized by Licensee only, sublicensed and dis_
tributed under the terms and conditions of the End User License Agree_
ment supplied by STMicroelectronics International N.V.
Full source code is available at: www.segger.com

----------------------------------------------------------------------
File        : WinMain.c
---------------------------END-OF-HEADER------------------------------
*/
/**
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license SLA0044,
  * the "License"; You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *                      http://www.st.com/SLA0044
  *
  ******************************************************************************
  */
#include <windows.h>
#include <winuser.h>
#include <stdint.h>

#include "GUI_SIM_Win32.h"
#include "L4X9_includes.h"
extern uint8_t OpTestVal_u8;
/*********************************************************************
*
*       Public data
*
**********************************************************************
*/

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       WinMain
*/
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,  LPSTR lpCmdLine, int nCmdShow) {
//  return SIM_GUI_App(hInstance, hPrevInstance,  lpCmdLine, nCmdShow);
//}

/*Button*/
// The main window class name.
static TCHAR szWindowClass[] = "DSX";

// The string that appears in the application's title bar.
static TCHAR szTitle[] = "Control Value";

HINSTANCE hInst;
HWND hWnd;
// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	 
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			"Call to RegisterClassEx failed!",
			"Win32 Guided Tour",
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		1200, 800,
		500, 150,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			"Call to CreateWindow failed!",
			"Win32 Guided Tour",
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);
	SIM_GUI_App(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = "DSX";
	TCHAR strNumber[50] = "00";
	RECT rc;
	HDC dc;
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, World!"
		// in the top left corner.
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.

		EndPaint(hWnd, &ps);
		break;
	case WM_SYSKEYDOWN:
		/*Long press > 2s*/
		switch (wParam)
		{
		case VK_UP:
			/*Long press > 2s*/
			Key_L.Timer = 0;
			Key_L.DataType = long_press;
			Key_L.Key_Rolling = KeyStatus_Idle;
			Key_M.DataType = short_press;
			Key_U.DataType = short_press;
			Key_D.DataType = short_press;
			DSX_GenerateLogic();
			/*----------------------*/
			/*End Button handle*/
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "   %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  UP LONG PRESS                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;
		case VK_DOWN:
			/*Long press > 2s*/
			Key_M.Timer = 0;
			Key_L.DataType = nothing;
			Key_M.DataType = nothing;
			Key_R.DataType = long_press;
			Key_M.Key_Rolling = KeyStatus_Idle;
			DSX_GenerateLogic();
			/*----------------------*/
			/*End Button handle*/
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "   %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  DOWN LONG PRESS                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;		
		case VK_LEFT:
			/*Long press > 2s*/
			Key_U.Timer = 0;
			Key_U.DataType = long_press;
			Key_U.Key_Rolling = KeyStatus_Idle;
			Key_M.DataType = short_press;
			Key_L.DataType = short_press;
			Key_D.DataType = short_press;
			DSX_GenerateLogic();
			/*----------------------*/
			/*End Button handle*/
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "   %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  LEFT LONG PRESS                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;		
		case VK_RIGHT:
			/*Long press > 2s*/
			Key_R.Timer = 0;
			Key_R.DataType = long_press;
			Key_R.Key_Rolling = KeyStatus_Idle;
			Key_M.DataType = short_press;
			Key_U.DataType = short_press;
			Key_D.DataType = short_press;
			DSX_GenerateLogic();
			/*----------------------*/
			/*End Button handle*/
			DSX_GenerateLogic();
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "   %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  RIGHT LONG PRESS                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;
		}
		break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_SPACE:
			/*TEST Opcode*/
			DSX_OPCODE = DEVICE_BLUETOOTH_DOWNLOAD_DATA;
			DSX_Opcode = DSX_OPCODE;
			DSX_GenerateLogic();
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "   %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  TEST                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;			
		case VK_HOME:
			/*Reset to Surface*/
			DSX_OPCODE = DIVE_GSM_MAIN;
			DSX_Opcode = DSX_OPCODE;
			DSX_GenerateLogic();
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "   %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  HOME                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;
		case VK_UP:
			/*Short press*/
			Key_L.Key_Status = KeyStatus_Idle;
			Key_L.DataType = short_press;
			Key_M.DataType = nothing;
			Key_U.DataType = nothing;
			Key_D.DataType = nothing;
			Key_R.DataType = nothing;
			DSX_GenerateLogic();
			/*----------------------*/
			/*End Button handle*/
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "   %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  UP                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;
		case VK_DOWN:
			/*Short press*/
			Key_M.Key_Status = KeyStatus_Idle;
			Key_M.DataType = short_press;
			Key_L.DataType = nothing;
			Key_U.DataType = nothing;
			Key_D.DataType = nothing;
			Key_R.DataType = nothing;
			DSX_GenerateLogic();
			/*----------------------*/
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "    %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  DOWN                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;
		case VK_LEFT:
			/*Short press*/
			Key_U.Key_Status = KeyStatus_Idle;
			Key_U.DataType = short_press;
			Key_M.DataType = nothing;
			Key_L.DataType = nothing;
			Key_D.DataType = nothing;
			Key_R.DataType = nothing;
			DSX_GenerateLogic();
			/*----------------------*/
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "    %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  LEFT                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;
		case VK_RIGHT:
			/*Short press*/
			Key_R.Key_Status = KeyStatus_Idle;
			Key_R.DataType = short_press;
			Key_M.DataType = nothing;
			Key_U.DataType = nothing;
			Key_D.DataType = nothing;
			Key_L.DataType = nothing;
			DSX_GenerateLogic();
			/*----------------------*/
			dc = GetDC(hWnd);
			GetClientRect(hWnd, &rc);
			sprintf(strNumber, "    %d   ", DSX_OPCODE);
			DrawText(dc, strNumber, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			DrawText(dc, "                  RIGHT                  ", -1, &rc, DT_CENTER | DT_TOP | DT_SINGLELINE);
			ReleaseDC(hWnd, dc);
			break;
		}

		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

		break;
	}

	return 0;
}
//#ifndef UNICODE
//#define UNICODE
//#endif 
//
//#include <windows.h>
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
//{
//	// Register the window class.
//	const wchar_t CLASS_NAME[] = L"Sample Window Class";
//
//	WNDCLASS wc = { };
//
//	wc.lpfnWndProc = WindowProc;
//	wc.hInstance = hInstance;
//	wc.lpszClassName = CLASS_NAME;
//
//	RegisterClass(&wc);
//
//	// Create the window.
//
//	HWND hwnd = CreateWindowEx(
//		0,                              // Optional window styles.
//		CLASS_NAME,                     // Window class
//		L"Learn to Program Windows",    // Window text
//		WS_OVERLAPPEDWINDOW,            // Window style
//
//		// Size and position
//		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//
//		NULL,       // Parent window    
//		NULL,       // Menu
//		hInstance,  // Instance handle
//		NULL        // Additional application data
//	);
//
//	if (hwnd == NULL)
//	{
//		return 0;
//	}
//
//	ShowWindow(hwnd, nCmdShow);
//
//	// Run the message loop.
//
//	MSG msg = { };
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//
//	return 0;
//}
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//
//	case WM_PAINT:
//	{
//		PAINTSTRUCT ps;
//		HDC hdc = BeginPaint(hwnd, &ps);
//
//
//
//		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
//
//		EndPaint(hwnd, &ps);
//	}
//	return 0;
//
//	}
//	return DefWindowProc(hwnd, uMsg, wParam, lParam);
//}
/*************************** End of file ****************************/
