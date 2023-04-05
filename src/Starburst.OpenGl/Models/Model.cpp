#include "Model.h"

VertexArray Model::GetVertexArray()
{
    return VertexArray();
}

ElementArray Model::GetElementArray()
{
    return ElementArray();
}

Shader Model::GetShader()
{
    return Shader();
}

glm::mat4 Model::GetRotation()
{
    return rotation;
}

glm::mat4 Model::GetTranslation()
{
    return translation;
}

glm::mat4 Model::GetPerspective()
{
    return perspective;
}

void Model::ResetMatrices()
{
    rotation = glm::mat4(1.0f);
    translation = glm::mat4(1.0f);
    perspective = glm::mat4(1.0f);
}

void Model::SetRotation(glm::mat4 matRotation)
{
    rotation = matRotation;
}

void Model::SetTranslation(glm::mat4 matTranslation)
{
    translation = matTranslation;
}

void Model::SetPerspective(glm::mat4 matPerspective)
{
    perspective = matPerspective;
}

void Model::Rotate(float radians, glm::vec3 applicationMatrix)
{
    rotation = glm::rotate(rotation, radians, applicationMatrix);
    shader->SetUniformMatrix4f("model", 1, GL_FALSE, glm::value_ptr(rotation));
}

void Model::Translate(glm::vec3 translationMatrix)
{
    translation = glm::translate(translation, translationMatrix);
    shader->SetUniformMatrix4f("view", 1, GL_FALSE, glm::value_ptr(translation));
}

void Model::Perspective(float radians, float aspect, float near, float far)
{
    perspective = glm::perspective(radians, aspect, near, far);
    shader->SetUniformMatrix4f("perspective", 1, GL_FALSE, glm::value_ptr(perspective));
}
