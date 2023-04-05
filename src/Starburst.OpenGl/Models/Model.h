#ifndef Model_CLASS_H
#define Model_CLASS_H

#include "..\VertexArray.h"
#include "..\VertexBuffer.h"
#include "..\ElementArray.h"
#include "..\Shader.h"

class Model
{
private:
	glm::mat4 rotation = glm::mat4(1.0f);
	glm::mat4 translation = glm::mat4(1.0f);
	glm::mat4 perspective = glm::mat4(1.0f);
protected:
	VertexArray* va;
	VertexBuffer* vb;
	ElementArray* ea;
	Shader* shader;
public:
	virtual VertexArray GetVertexArray();
	virtual ElementArray GetElementArray();
	virtual Shader GetShader();

	glm::mat4 GetTranslation();
	glm::mat4 GetRotation();
	glm::mat4 GetPerspective();

	void ResetMatrices();

	void SetRotation(glm::mat4);
	void SetTranslation(glm::mat4);
	void SetPerspective(glm::mat4);

	void Rotate(float radians, glm::vec3 applicationMatrix);
	void Translate(glm::vec3 translationMatrix);
	void Perspective(float radians, float aspect, float near, float far);
};

#endif