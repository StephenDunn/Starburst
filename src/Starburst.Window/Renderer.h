#pragma once
#include "RenderState.h"
class Renderer
{
private:
	RenderState *RState;
	float scale = 0.01f;
public:
	Renderer(RenderState *renderState);
	void RenderBackground();

	void ClearScreen(unsigned int colour);

	void DrawRectanglePixels(int x0, int y0, int x1, int x2, unsigned int colour);

	void DrawRectangle(float x, float y, float halfSizeX, float halfSizeY, unsigned int colour);
};

