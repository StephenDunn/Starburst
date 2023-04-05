#include"VertexArray.h"

// Constructor that generates a VertexArray ID
VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}

// Links a VertexBuffer to the VertexArray using a certain layout
void VertexArray::LinkAttribute(VertexBuffer& vb, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	vb.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vb.Unbind();
}

// Binds the VertexArray
void VertexArray::Bind() const
{
	glBindVertexArray(ID);
}

// Unbinds the VertexArray
void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

// Deletes the VertexArray
void VertexArray::Delete() const
{
	glDeleteVertexArrays(1, &ID);
}