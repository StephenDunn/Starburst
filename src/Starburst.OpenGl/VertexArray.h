#ifndef VertexArray_CLASS_H
#define VertexArray_CLASS_H

#include<glad/glad.h>
#include"VertexBuffer.h"

class VertexArray
{
public:
	// ID reference for the Vertex Array Object
	GLuint ID;
	// Constructor that generates a VertexArray ID
	VertexArray();

	// Links a VertexBuffer to the VertexArray using a certain layout
	void LinkAttribute(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	// Binds the VertexArray
	void Bind() const;
	// Unbinds the VertexArray
	void Unbind() const;
	// Deletes the VertexArray
	void Delete() const;
};
#endif