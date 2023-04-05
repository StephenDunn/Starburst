#include "TriforceModel.h"

GLfloat vertices[] =
{
	-0.5f, 0.0f, 0.5f,		0.0f, 1.0f,  0.02f,
	-0.5f, 0.0f, -0.5f,		1.0f, 1.0f,  0.02f,
	0.5f, 0.0f, -0.5f,		1.0f, 0.0f,  0.0f,
	0.5f, 0.0f, 0.5f,		0.9f, 1.0f, 0.17f,
	0.0f, 0.8f, 0.0f,		0.0f, 0.3f,  1.0f,    
};
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
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
