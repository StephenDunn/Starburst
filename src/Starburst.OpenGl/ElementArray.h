#ifndef ElementArray_CLASS_H
#define ElementArray_CLASS_H

#include<glad/glad.h>

class ElementArray
{
public:
	// ID reference of Elements Buffer Object
	GLuint ID;
	unsigned int Count;
	ElementArray();
	// Constructor that generates a Elements Buffer Object and links it to indices
	ElementArray(GLuint* indices, GLsizeiptr size);

	// Binds the ElementArray
	void Bind() const;
	// Unbinds the ElementArray
	void Unbind() const;
	// Deletes the ElementArray
	void Delete() const;
};

#endif