#ifndef VertexBuffer_CLASS_H
#define VertexBuffer_CLASS_H

#include<glad/glad.h>

class VertexBuffer
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VertexBuffer(GLfloat* vertices, GLsizeiptr size);

	// Binds the VertexBuffer
	void Bind() const;
	// Unbinds the VertexBuffer
	void Unbind() const;
	// Deletes the VertexBuffer
	void Delete() const;
};

#endif