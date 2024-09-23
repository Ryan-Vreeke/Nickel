#pragma once

#include "Camera.h"
#include "Components.h"
#include <GL/glew.h>
#include "cyGL.h"
#include <cstdint>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/vec3.hpp>   // glm::vec3
#include <glm/vec4.hpp>   // glm::vec4
#include <unordered_map>

inline float cubeVertices[] = {
    // Front face
    -0.5f, -0.5f, 0.5f, 
    0.5f, -0.5f, 0.5f,  
    0.5f, 0.5f, 0.5f,   
    -0.5f, 0.5f, 0.5f,  

    // Back face
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f, 
    0.5f, 0.5f, -0.5f,  
    -0.5f, 0.5f, -0.5f, 

    // Left face
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, 0.5f, 
    -0.5f, 0.5f, 0.5f,  
    -0.5f, 0.5f, -0.5f, 

    // Right face
    0.5f, -0.5f, -0.5f, 
    0.5f, -0.5f, 0.5f,  
    0.5f, 0.5f, 0.5f,   
    0.5f, 0.5f, -0.5f,  

    // Top face
    -0.5f, 0.5f, -0.5f, 
    0.5f, 0.5f, -0.5f,  
    0.5f, 0.5f, 0.5f,   
    -0.5f, 0.5f, 0.5f,  

    // Bottom face
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f, 
    0.5f, -0.5f, 0.5f,  
    -0.5f, -0.5f, 0.5f  
};

inline unsigned int cubeIndices[] = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    8, 9, 10, 10, 11, 8,
    12, 13, 14, 14, 15, 12,
    16, 17, 18, 18, 19, 16,
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

  void
  update(std::unordered_map<uint32_t, PositionComponent> &transformComponent);

private:
  glm::mat4 view;
  int object_count;

  glm::mat4 get_model(glm::vec3 pos, glm::vec3 scale);
  void draw();
};
