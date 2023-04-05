#ifndef TriforceModel_CLASS_H
#define TriforceModel_CLASS_H

#include "Model.h"

class TriforceModel : public Model
{
private:
	
public:
	TriforceModel();
	~TriforceModel();
	VertexArray GetVertexArray();
	ElementArray GetElementArray();
	Shader GetShader();
};


#endif