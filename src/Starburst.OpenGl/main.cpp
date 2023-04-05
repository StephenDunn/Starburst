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

const unsigned int Width = 800;
const unsigned int Height = 800;

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(Width, Height, "Starburst GL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, Width, Height);

	Renderer renderer;

	TriforceModel triforce;
	TriforceModel triforce2;


	glEnable(GL_DEPTH_TEST);

	float scale = 0.0f;
	float rotation = 0.0f;
	bool forward = true;
	double previousTime = glfwGetTime();
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
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

		triforce.ResetMatrices();
		triforce.Rotate(glm::radians(rotation), glm::vec3(0.5f, 1.0f, 1.0f));
		triforce.Translate(glm::vec3(-0.0f, -0.0f, -5.0f));
		triforce.Perspective(glm::radians(45.0f), (float)(Width / Height), 0.1f, 100.0f);
		triforce.GetShader().SetUniform1f("scale", scale);
		renderer.DrawModel(triforce);

		triforce2.ResetMatrices();
		triforce2.Rotate(glm::radians(rotation * 0.5f), glm::vec3(0.5f, 1.0f, 1.0f));
		triforce2.Translate(glm::vec3(-0.0f, 1.0f, -5.0f));
		triforce2.Perspective(glm::radians(45.0f), (float)(Width / Height), 0.1f, 100.0f);
		triforce2.GetShader().SetUniform1f("scale", scale * -0.5f);
		renderer.DrawModel(triforce2);

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}


	triforce.~TriforceModel();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}