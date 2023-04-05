#ifndef TriforceModel_CLASS_H
#define TriforceModel_CLASS_H

#include "Model.h"

class TriforceModel : public Model
{
private:
	VertexArray* va;
	VertexBuffer* vb;
	ElementArray* ea;
	Shader* shader;
public:
	TriforceModel();
	~TriforceModel();
	VertexArray GetVertexArray();
	ElementArray GetElementArray();
	Shader GetShader();
};


#endif