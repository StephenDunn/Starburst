#include "TriforceModel.h"

GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     1.0f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     1.0f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.1f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.1f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.0f, 0.3f,  1.0f  // Inner down
};
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};

TriforceModel::TriforceModel()
{
	va = new VertexArray();
	va->Bind();
	vb = new VertexBuffer(vertices, sizeof(vertices));
	ea = new ElementArray(indices, sizeof(indices));
	shader = new Shader("Shaders/default.vert", "Shaders/default.frag");

	va->LinkAttribute(*vb, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	va->LinkAttribute(*vb, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	va->Unbind();
	vb->Unbind();
	ea->Unbind();
}

TriforceModel::~TriforceModel()
{
	va->Delete();
	ea->Delete();
	shader->Delete();
}

VertexArray TriforceModel::GetVertexArray()
{
	return *va;
}

ElementArray TriforceModel::GetElementArray()
{
	return *ea;
}

Shader TriforceModel::GetShader()
{
	return *shader;
}
