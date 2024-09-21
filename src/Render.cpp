#include "Render.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <cstdint>
#include <glm/ext/quaternion_transform.hpp>
#include <glm/fwd.hpp>
#include <glm/gtc/type_ptr.hpp>

Render::Render(Camera &camera) : camera(camera) {
  printf("%d\n",
         program.BuildFiles("../shaders/vert.vert", "../shaders/shader.frag"));
  glEnable(GL_DEPTH_TEST);

  projection = glm::perspective(glm::radians(80.0f), // Field of view
                                800.0f / 800.0f,     // Aspect ratio
                                0.1f, 100.0f         // Near and far planes
  );

  glClearColor(0.43f, 0.69f, 1.0f, 1.0f);
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // create a VBO
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices,
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *)0);

  // generate and bind EBO
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices,
               GL_STATIC_DRAW);

  glBindVertexArray(0);
}

Render::~Render() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &buffer);
  glDeleteBuffers(1, &EBO);
}

void Render::update( std::unordered_map<uint32_t, PositionComponent> &posEntities) {
  std::vector<glm::mat4> blocks;

  for (std::pair<uint32_t, PositionComponent> entity : posEntities) {
    blocks.push_back(get_model(entity.second.pos, entity.second.scale));
  }

  object_count = blocks.size();
  glBindVertexArray(VAO);

  glGenBuffers(1, &models_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, models_buffer);
  glBufferData(GL_ARRAY_BUFFER, blocks.size() * sizeof(glm::mat4), &blocks[0],
               GL_STATIC_DRAW); // copy data in position array in to buffer

  for (int i = 0; i < 4; i++) {
    glEnableVertexAttribArray(1 + i);
    glVertexAttribPointer(1 + i, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4),
                          (GLvoid *)(sizeof(GLfloat) * i * 4));
    glVertexAttribDivisor(1 + i, 1);
  }

  glBindVertexArray(0);
  draw();
}

void Render::draw() {
  program.Bind();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  GLuint viewLoc = glGetUniformLocation(program.GetID(), "view");
  GLuint projLoc = glGetUniformLocation(program.GetID(), "projection");

  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.getView()));
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // rendering
  glBindVertexArray(VAO);
  glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, object_count);
  glBindVertexArray(0);
}

glm::mat4 Render::get_model(glm::vec3 pos, glm::vec3 scaleVec) {
  glm::mat4 translated = translate(glm::mat4(1.0f), pos);
  return glm::scale(translated, scaleVec);
}
