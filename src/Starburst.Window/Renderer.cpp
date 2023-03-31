#include "Renderer.h"
#include "Utilities.h"

Renderer::Renderer(RenderState* renderState)
{
	RState = renderState;
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

void Renderer::DrawGrid(int xSize, int ySize, unsigned int colour)
{
	int xPositions;
	int yPositions;
	int limit;
	int limitDifference;
	bool xLimitOffset = false;
	bool yLimitOffset = false;

	// Find whether height or width is the limiting size. Set the limit based on max axis.
	// Set flag to define which is max.
	if (RState->Width < RState->Height) {
		xPositions = RState->Width / xSize;
		yPositions = RState->Width / ySize;
		limitDifference = (RState->Height - RState->Width) / 2;
		limit = RState->Width + limitDifference + lineScale;
		yLimitOffset = true;
	}
	else {
		xPositions = RState->Height / xSize;
		yPositions = RState->Height / ySize;
		limitDifference = (RState->Width - RState->Height) / 2;
		limit = RState->Height + limitDifference + lineScale;
		xLimitOffset = true;
	}

	int xOffset;
	int yOffset;
	unsigned int* pixel = (unsigned int*)RState->Memory;

	// Offset the x or y axis by half the difference of the difference between the axis
	if (xLimitOffset) {
		xOffset = limitDifference;
		yOffset = 0;
	}
	else {
		xOffset = 0;
		yOffset = limitDifference - 1;

		// If y axis is larger progress the pixel pointer to the start position.
		pixel = pixel + (RState->Width * limitDifference);
	}

	for (int y = yOffset; y < RState->Height; y++) {

		// If x axis is larger on each itteration through offset the pixel pointer by width offset.
		if (xLimitOffset) { pixel = pixel + xOffset; }

		for (int x = xOffset; x < RState->Width; x++) {
			int xOffset;
			int yOffset;
			if (xLimitOffset) {
				xOffset = x - limitDifference;
				yOffset = y;
			}
			else {
				xOffset = x;
				yOffset = y - limitDifference;
			}
			if (x < limit && y < limit) {

				if ((xLimitOffset && x > limitDifference) || (yLimitOffset && y > limitDifference)) {
					int modX = xOffset % xPositions;
					if (modX > 0 && modX < lineScale) {
						*pixel = colour;
					}

					int modY = yOffset % yPositions;
					if (modY > 0 && modY < lineScale) {
						*pixel = colour;
					}
				}
			}

			*pixel++;			
		}
	}
}
