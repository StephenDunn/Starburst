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
	std::vector<Model> modelVec;

	TriforceModel triforce;

	modelVec.push_back(triforce);

	float scale = 0.0f;
	float rotation = 0.0f;
	bool forward = true;
	double previousTime = glfwGetTime();
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		if (currentTime - previousTime >= 1/60) {
			
			rotation += 0.5f;

			if (forward) {
				if (scale >= 1.0f) {
					forward = false;
				}

				scale += currentTime - previousTime * 0.1f;
			}
			else {
				if (scale <= 0.0f) {
					forward = true;
				}

				scale -= (currentTime - previousTime) * 0.1f;
			}
		}
		previousTime = currentTime;

		// Specify the color of the background
		glClearColor(0.10f, 0.26f, 0.34f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)(Width / Height), 0.1f, 100.0f);

		GLuint modelID = glGetUniformLocation(triforce.GetShader().ID, "model");
		glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model));

		GLuint viewID = glGetUniformLocation(triforce.GetShader().ID, "view");
		glUniformMatrix4fv(viewID, 1, GL_FALSE, glm::value_ptr(view));

		GLuint projectionID = glGetUniformLocation(triforce.GetShader().ID, "perspective");
		glUniformMatrix4fv(projectionID, 1, GL_FALSE, glm::value_ptr(projection));

		GLuint uniID = glGetUniformLocation(triforce.GetShader().ID, "scale");
		glUniform1f(uniID, scale);

		for (Model model : modelVec) {


		}

		

		renderer.Draw(triforce.GetVertexArray(), triforce.GetElementArray(), triforce.GetShader());

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