#pragma once
#include<windows.h>
struct RenderState {
	void* Memory;
	int Width;
	int Height;
	BITMAPINFO BitmapInfo;
};
