#ifndef Renderer_CLASS_H
#define Renderer_CLASS_H


#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementArray.h"
#include "Shader.h"
#include "Models/Model.h"

class Renderer
{
private:
public:
	Renderer();
	void const Clear();
	void const Draw(const VertexArray& va, const ElementArray& ea, const Shader& shader);
	void DrawModel(Model& model);
};

#endif