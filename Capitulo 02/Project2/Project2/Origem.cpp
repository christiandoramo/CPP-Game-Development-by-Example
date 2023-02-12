#include <iostream>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext.hpp>
#include <glew/include/GL/glew.h>

int main() {
	//To define a 2D point in space,
	//we will do the following :
	glm::vec2 p1 = glm::vec2(2.0f, 10.0f);
	//Where the 2 arguments passed in are the x and y position.
	//To define a 3D point, we will specify the following :
	glm::vec3 p2 = glm::vec3(10.0f, 5.0f, 2.0f);
	//A 4 x 4 matrix is created using glm, in the as following code.A 4 x 4 matrix is
	//of the mat4 type and is created like this:
	glm::mat4 matrix = glm::mat4(1.0f);
	/*Here the 1.0f parameter passed in shows that the matrix is
	initialized as a identity matrix.
	For translation and rotation, of this matrix you will need to include GLM
	extensions, as shown in the following code :
	#include <glm/ext.hpp>*/
	glm::mat4 translation = glm::translate(glm::mat4(1.0f),
		glm::vec3(3.0f, 4.0f, 8.0f));
	//To now translate the object to(3.0, 4.0, 8.0) from its current position, as
	//follows :
	glm::mat4 scale = glm::scale(glm::mat4(1.0f),
		glm::vec3(2.0f, 2.0f, 2.0f));
	//We can also scale the value to double its size in the x, y, and z directions :
	glm::mat4 rxMatrix = glm::rotate(glm::mat4(), glm::radians(45.0f),
		glm::vec3(1.0, 0.0, 0.0));
	glm::mat4 ryMatrix = glm::rotate(glm::mat4(), glm::radians(25.0f),
		glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 rzMatrix = glm::rotate(glm::mat4(), glm::radians(10.0f),
		glm::vec3(0.0, 0.0, 1.0));
	//This above code block rotate the object by 45 degrees along the x axis, 25.0f degrees along
	//the y axis, and 10.0f degrees along the z axis.
	//Note that we use glm::radians().This glm function converts degrees into radians.More
	//GLM functions will be introduced as we progress throughout this chapter.

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 200.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	GLfloat FOV = 45.0f;
	GLfloat width = 1280.0f;
	GLfloat height = 720.0f;
	GLfloat nearPlane = 0.1f;
	GLfloat farPlane = 1000.0f;
	glm::mat4 projectionMatrix = glm::perspective(FOV, width / height,
		nearPlane, farPlane);
	//Note that the nearPlane always needs to be greater than 0.0f to create the start of the
	//	frustum in form of the camera.
	//	The glm::perspective function takes four parameters.
	//	The first is the FOV,
	//	The second is the aspect ratio,
	//	The third is the distance to the near plane,
	//	The fourth is the distance to the far plane.
	//	So, after obtaining the projection matrix, we can finally perform

	//VAOs are used to define what data each vertex has
	//	and VBOs have the actual vertex data.
	//say that we have an array of three points.Let's see how we would create the
	//	VAO and the VBO :
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f
	};
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
		GL_STATIC_DRAW);
	//The first parameter is a type of buffer data, which is the GL_ARRAY_BUFFER type.
	//	The second parameter is the size of the data type that is passed in.The sizeof()
	//	is a C++ keyword that gets the size of the data in bytes.
	//	The next parameter is the data itselfand the last parameter is used to specify
	//	whether this data will change.The GL_STATIC_DRAW means that the data will not
	//	be modified once the values are stored.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 *sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	return 0;
}
