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
