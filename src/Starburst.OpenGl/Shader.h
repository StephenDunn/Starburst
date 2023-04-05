#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include <unordered_map>
#include <string>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

std::string get_file_contents(const char* filename);

class Shader
{
private:
	std::unordered_map<std::string, int> uniformCache;
public:
	// Reference ID of the Shader Program
	GLuint ID;
	Shader();
	// Constructor that build the Shader Program from 2 different shaders
	Shader(const char* vertexFile, const char* fragmentFile);

	// Activates the Shader Program
	void Bind() const;
	// Deletes the Shader Program
	void Delete() const;

	void const SetUniform1f(const std::string& name, float v);
	void const SetUniform4f(const std::string& name, float v0, float v1, float v2, float v4);
	void const SetUniformMatrix4f(const std::string& name, float v0, float v1, const glm::f32* v2);
	GLuint GetUniformLocation(const std::string& name);
};
#endif