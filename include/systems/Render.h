#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/vec3.hpp>   // glm::vec3
#include <glm/vec4.hpp>   // glm::vec4
#include "../../external/cyCodeBase/cyGL.h"
#include "../TransformComponent.h"
#include "cyTriMesh.h"
#include <unordered_map>


// inline const float positions[] = {
//   -0.5f, 0.5f, 0.0f, 0.5f, 0.5f,  0.0f, 0.5f,  -0.5f, 0.0f,
//   -0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f,
// };

class Render
{
 public:
  GLuint buffer;
  GLuint models_buffer;
  GLuint VAO;
  cy::GLSLProgram program;

	Render(const char* obj);
	~Render();

  void update( std::unordered_map<unsigned int, TransformComponent> &transformComponent);

 private:

int object_count;

  cy::TriMesh mesh;

  glm::mat4 get_model(glm::vec3 pos);
  void draw();
};
