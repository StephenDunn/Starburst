#include "StarburstCharacter.h"

GLfloat starburstVertices[] =
{	// Outer
	-1.0f,	1.0f,	0.0f,		0.0f, 0.0f,  0.5f, // Top left		0
	1.0f,	1.0f,	0.0f,		0.0f, 0.0f,  0.5f, // Top right		1
	1.0f,	-1.0f,	0.0f,		0.0f, 0.0f,  0.5f, // Bottom Right	2
	-1.0f,	-1.0f,	0.0f,		0.0f, 0.0f, 0.5f, // Bottom Left	3
	// Outer inner
	-0.9f,	0.9f,	0.1f,		0.0f, 0.0f,  0.8f, // Top left		4
	0.9f,	0.9f,	0.1f,		0.0f, 0.0f,  0.8f, // Top right		5
	0.9f,	-0.9f,	0.1f,		0.0f, 0.0f,  0.8f, // Bottom Right	6
	-0.9f,	-0.9f,	0.1f,		0.0f, 0.0f, 0.8f, // Bottom Left	7
	// Inner
	-0.1f,	0.1f,	0.2f,		0.2f, 0.2f,  1.0f, // Top left		8
	0.1f,	0.1f,	0.2f,		0.2f, 0.2f,  1.0f, // Top right		9
	0.1f,	-0.1f,	0.2f,		0.2f, 0.2f,  1.0f, // Bottom Right	10
	-0.1f,	-0.1f,	0.2f,		0.2f, 0.2f, 1.0f, // Bottom Left	11
	// Centre
	0.0f,	0.0f,	0.5f,		0.5f, 0.5f, 1.0f,			//		12
};
GLuint starburstIndices[] =
{
	// Outer lines
	0, 1, 4,
	1, 4, 5,
	
	1, 2, 6,
	1, 5, 6,

	2, 6, 3,
	3, 7, 6,

	3, 7, 0,
	0, 4, 7,

	8, 12, 9,
	9, 12, 10,
	10, 12, 11,
	11, 12, 8,

	10, 3, 8,
	11, 0, 9,
	8, 1, 10,
	11, 9, 2

};

StarburstCharacter::StarburstCharacter()
{
	va = new VertexArray();
	va->Bind();
	vb = new VertexBuffer(starburstVertices, sizeof(starburstVertices));
	ea = new ElementArray(starburstIndices, sizeof(starburstIndices));
	shader = new Shader("Shaders/default.vert", "Shaders/default.frag");

	// Define format of verticies for shader
	// Shaders only read bytes, how the vertex is defined needs to be defined as though the shader is only reading bytes.
	// First shader variable is 3 elements, its floats, the whole vertex is 6 floats long, it starts at the 0 position
	// This attribute is Vertex position
	va->LinkAttribute(*vb, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	// Second shader variable is 3 elements, its floats, the whole vertex is 6 floats long, it starts at position 3.
	va->LinkAttribute(*vb, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	va->Unbind();
	vb->Unbind();
	ea->Unbind();
}

StarburstCharacter::~StarburstCharacter()
{
	va->Delete();
	ea->Delete();
	shader->Delete();
}

VertexArray StarburstCharacter::GetVertexArray()
{
	return *va;
}

ElementArray StarburstCharacter::GetElementArray()
{
	return *ea;
}

Shader StarburstCharacter::GetShader()
{
	return *shader;
}
