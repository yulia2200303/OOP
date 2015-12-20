#pragma once
#include "stdafx.h"
#include <string>
#include "Win32API.h"

class WinController{
	int size_;
	int capacity_ = 50;
	HWND* windows_;
	HWND main_;
	HINSTANCE hInstance_;

	std::wstring ConvertStrToWstr(const std::string& str)
	{
		int len;
		int slength = (int)str.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, 0, 0);
		std::wstring r(len, L'\0');
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, &r[0], len);
		return r;
	}

	void InitInstance(HINSTANCE hInstance){
		this->hInstance_ = hInstance;

		WNDCLASS chWnd;
		memset(&chWnd, 0, sizeof(WNDCLASS));
		chWnd.style = CS_HREDRAW | CS_VREDRAW;
		chWnd.lpfnWndProc = ChildWndProc;
		chWnd.hInstance = hInstance;
		chWnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		chWnd.lpszClassName = TEXT("ChildWindow");
		RegisterClass(&chWnd);
	}

	void UpdateWindowText(){
		std::string name = "Windows: ";
		name += std::to_string(this->size_);
		std::wstring stemp = ConvertStrToWstr(name);
		LPCWSTR lName = stemp.c_str();
		SetWindowText(this->main_, lName);
	}

public:

	WinController(HWND main, HINSTANCE hInstance){
		InitInstance(hInstance);
		this->main_ = main;

		this->windows_ = new HWND[this->capacity_];
		for (int i = 0; i < this->capacity_; i++){
			windows_[i] = NULL;
		}
	}

	bool Create(){
		if (size_ >= capacity_) return false;

		std::string name = "Hello world ";
		name += std::to_string(this->size_ + 1);
		std::wstring stemp = ConvertStrToWstr(name);
		LPCWSTR lName = stemp.c_str();

		HWND hWnd = CreateWindow(TEXT("ChildWindow"), lName, WS_OVERLAPPEDWINDOW, 200 + 25 * size_, 200 + 25 * size_, 300, 300, this->main_, NULL, this->hInstance_, NULL);
		if (hWnd == NULL){
			return false;
		}

		ShowWindow(hWnd, 1);
		UpdateWindow(hWnd);
		this->windows_[this->size_++] = hWnd;
		UpdateWindowText();
		return true;
	}

	BOOL Destroy(){
		if (this->size_ > 0){
			BOOL result = DestroyWindow(this->windows_[size_ - 1]);
			if (result){
				this->size_--;
				UpdateWindowText();
			}

			return result;
		}

		return 0;
	}

	static LRESULT CALLBACK ChildWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
		HDC     hdc;
		PAINTSTRUCT ps;

		switch (message)
		{
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
			return 0;

		case WM_DESTROY:
			return 0;
		}
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
};
