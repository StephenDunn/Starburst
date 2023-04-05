#include"VertexBuffer.h"

// Constructor that generates a Vertex Buffer Object and links it to vertices
VertexBuffer::VertexBuffer(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

// Binds the VertexBuffer
void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbinds the VertexBuffer
void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VertexBuffer
void VertexBuffer::Delete() const
{
	glDeleteBuffers(1, &ID);
}