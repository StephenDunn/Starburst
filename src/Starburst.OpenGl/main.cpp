#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include <vector>

#include"Shader.h"
#include"VertexArray.h"
#include"VertexBuffer.h"
#include"ElementArray.h"
#include"Renderer.h"
#include"Models\TriforceModel.h"
#include"Models\StarburstCharacter.h"

unsigned int Width = 800;
unsigned int Height = 800;

void ResizeViewportToWindow(GLFWwindow* window) {
	int* w = new int();
	int* h = new int();
	glfwGetWindowSize(window, w, h);
	Width = *w;
	Height = *h;

	glViewport(0, 0, Width, Height);
}

int main()
{
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(Width, Height, "Starburst GL", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, Width, Height);

	Renderer renderer;

	TriforceModel triforce;
	TriforceModel triforce2;
	StarburstCharacter character;

	glEnable(GL_DEPTH_TEST);

	float scale = 0.0f;
	float rotation = 0.0f;
	bool forward = true;
	double previousTime = glfwGetTime();

	while (!glfwWindowShouldClose(window))
	{
		ResizeViewportToWindow(window);
		
		renderer.Clear();
		double currentTime = glfwGetTime();
		if (currentTime - previousTime >= 1/60) {
			
			rotation += 0.5f;

			if (forward) {
				if (scale >= 1.0f) {
					forward = false;
				}

				scale += (currentTime - previousTime) * 0.5f;
			}
			else {
				if (scale <= 0.0f) {
					forward = true;
				}

				scale -= (currentTime - previousTime) * 0.5f;
			}
		}
		previousTime = currentTime;

		//triforce.ResetMatrices();
		//triforce.Rotate(glm::radians(rotation), glm::vec3(0.5f, 1.0f, 1.0f));
		//triforce.Translate(glm::vec3(-0.0f, -0.0f, -5.0f));
		//triforce.Perspective(glm::radians(45.0f), (float)(Width / Height), 0.1f, 100.0f);
		//triforce.GetShader().SetUniform1f("scale", scale);
		//renderer.DrawModel(triforce);

		//triforce2.ResetMatrices();
		//triforce2.Rotate(glm::radians(rotation * 0.5f), glm::vec3(0.5f, 1.0f, 1.0f));
		//triforce2.Translate(glm::vec3(-0.0f, 1.0f, -5.0f));
		//triforce2.Perspective(glm::radians(45.0f), (float)(Width / Height), 0.1f, 100.0f);
		//triforce2.GetShader().SetUniform1f("scale", scale * -0.5f);
		//renderer.DrawModel(triforce2);


		character.ResetMatrices();
		character.Rotate(glm::radians(rotation * 0.5f), glm::vec3(0.5f, 1.0f, 1.0f));
		character.Translate(glm::vec3(-0.0f, 0.0f, -5.0f));
		character.Perspective(glm::radians(45.0f), (float)(Width / Height), 0.1f, 100.0f);
		character.GetShader().SetUniform1f("scale", scale * -0.5f);
		renderer.DrawModel(character);

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

