#include "Renderer.h"

Renderer::Renderer()
{
}

void const Renderer::Draw(const VertexArray& va, const ElementArray& ea, const Shader& shader)
{
	shader.Bind();
	ea.Bind();
	va.Bind();
	glDrawElements(GL_TRIANGLES, ea.Count, GL_UNSIGNED_INT, 0);
}

void Renderer::DrawModel(Model& model)
{
	Draw(model.GetVertexArray(), model.GetElementArray(), model.GetShader());
}

void const Renderer::Clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

