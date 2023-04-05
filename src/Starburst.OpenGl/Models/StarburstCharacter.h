#ifndef StarburstCharacterModel_CLASS_H
#define StarburstCharacterModel_CLASS_H

#include "Model.h"

class StarburstCharacter : public Model
{
private:

public:
	StarburstCharacter();
	~StarburstCharacter();
	VertexArray GetVertexArray();
	ElementArray GetElementArray();
	Shader GetShader();
};


#endif