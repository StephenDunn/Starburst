#ifndef Renderer_CLASS_H
#define Renderer_CLASS_H

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementArray.h"
#include "Shader.h"

class Renderer
{
public:
	Renderer();

	void const Draw(const VertexArray& va, const ElementArray& ea, const Shader& shader);
};

#endif