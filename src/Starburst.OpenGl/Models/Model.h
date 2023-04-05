#ifndef Model_CLASS_H
#define Model_CLASS_H

#include "..\VertexArray.h"
#include "..\VertexBuffer.h"
#include "..\ElementArray.h"
#include "..\Shader.h"

class Model
{
public:
	virtual VertexArray GetVertexArray();
	virtual ElementArray GetElementArray();
	virtual Shader GetShader();
};

#endif