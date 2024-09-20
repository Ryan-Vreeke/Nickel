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
#include "Components.h"
#include <unordered_map>
#include "Camera.h"

inline float cubeVertices[] = {
    // Front face
    -0.5f, -0.5f, 0.5f, // Bottom-left
    0.5f, -0.5f, 0.5f,  // Bottom-right
    0.5f, 0.5f, 0.5f,   // Top-right
    -0.5f, 0.5f, 0.5f,  // Top-left

    // Back face
    -0.5f, -0.5f, -0.5f, // Bottom-left
    0.5f, -0.5f, -0.5f,  // Bottom-right
    0.5f, 0.5f, -0.5f,   // Top-right
    -0.5f, 0.5f, -0.5f,  // Top-left

    // Left face
    -0.5f, -0.5f, -0.5f, // Bottom-left
    -0.5f, -0.5f, 0.5f,  // Bottom-right
    -0.5f, 0.5f, 0.5f,   // Top-right
    -0.5f, 0.5f, -0.5f,  // Top-left

    // Right face
    0.5f, -0.5f, -0.5f, // Bottom-left
    0.5f, -0.5f, 0.5f,  // Bottom-right
    0.5f, 0.5f, 0.5f,   // Top-right
    0.5f, 0.5f, -0.5f,  // Top-left

    // Top face
    -0.5f, 0.5f, -0.5f, // Bottom-left
    0.5f, 0.5f, -0.5f,  // Bottom-right
    0.5f, 0.5f, 0.5f,   // Top-right
    -0.5f, 0.5f, 0.5f,  // Top-left

    // Bottom face
    -0.5f, -0.5f, -0.5f, // Bottom-left
    0.5f, -0.5f, -0.5f,  // Bottom-right
    0.5f, -0.5f, 0.5f,   // Top-right
    -0.5f, -0.5f, 0.5f   // Top-left
};

inline unsigned int cubeIndices[] = {
    // Front face
    0, 1, 2, 2, 3, 0,
    // Back face
    4, 5, 6, 6, 7, 4,
    // Left face
    8, 9, 10, 10, 11, 8,
    // Right face
    12, 13, 14, 14, 15, 12,
    // Top face
    16, 17, 18, 18, 19, 16,
    // Bottom face
    20, 21, 22, 22, 23, 20};

class Render {
public:
  GLuint buffer;
  GLuint models_buffer;
  GLuint VAO;
  GLuint EBO;
  cy::GLSLProgram program;
  glm::mat4 projection;
  Camera &camera;

  Render(Camera &camera);
  ~Render();

  void update(std::unordered_map<unsigned int, TransformComponent> &transformComponent);

private:
  glm::mat4 view;
  int object_count;


  glm::mat4 get_model(glm::vec3 pos);
  void draw();
};
