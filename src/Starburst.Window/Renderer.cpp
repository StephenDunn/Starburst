#include "Renderer.h"
#include "Utils.h"

Renderer::Renderer(RenderState* renderState)
{
	RState = renderState;
}

void Renderer::RenderBackground()
{
	unsigned int* pixel = (unsigned int*)RState->Memory;
	for (int y = 0; y < RState->Height; y++) {
		for (int x = 0; x < RState->Width; x++) {
			*pixel++ = ((y * 0.33) * (x + 1 * x + 1 * 0.2) + 0xf0f0f0) * (0.2 * RState->Width);
		}
	}
}

void Renderer::ClearScreen(unsigned int colour)
{
	unsigned int* pixel = (unsigned int*)RState->Memory;
	for (int y = 0; y < RState->Height; y++) {
		for (int x = 0; x < RState->Width; x++) {
			*pixel++ = colour;
		}
	}
}



void Renderer::DrawRectanglePixels(int x0, int y0, int x1, int y1, unsigned int colour)
{
	x0 = clamp(0, x0, RState->Width);
	x1 = clamp(0, x1, RState->Width);
	y0 = clamp(0, y0, RState->Height);
	y1 = clamp(0, y1, RState->Height);
	for (int y = y0; y < y1; y++) {
		unsigned int* pixel = (unsigned int*)RState->Memory + x0 + y * RState->Width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = colour;
		}
	}
}

void Renderer::DrawRectangle(float x, float y, float halfSizeX, float halfSizeY, unsigned int colour)
{
	x *= RState->Height * scale;
		;
	y *= RState->Height * scale;
	halfSizeX *= RState->Height * scale;
	halfSizeY *= RState->Height * scale;

	x += RState->Width / 2.0f;
	y += RState->Height / 2.0f;

	int x0 = x - halfSizeX;
	int x1 = x + halfSizeX;
	int y0 = y - halfSizeY;
	int y1 = y + halfSizeY;

	DrawRectanglePixels(x0, y0, x1, y1, colour);
}
