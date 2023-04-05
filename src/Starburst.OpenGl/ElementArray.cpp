#include"ElementArray.h"

ElementArray::ElementArray()
{
}

// Constructor that generates a Elements Buffer Object and links it to indices
ElementArray::ElementArray(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	Count = size;
}

// Binds the ElementArray
void ElementArray::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

// Unbinds the ElementArray
void ElementArray::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Deletes the ElementArray
void ElementArray::Delete() const
{
	glDeleteBuffers(1, &ID);
}