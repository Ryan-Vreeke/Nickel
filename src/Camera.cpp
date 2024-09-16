#include "Camera.h"
#include <algorithm>
#include <cmath>
#include <glm/ext/matrix_transform.hpp>

Camera::Camera()
    : pos(0.0f, 0.0f, 5.0f), target(0.0f, 0.0f, 0.0f), up(0.0f, 1.0f, 0.0f) {}

Camera::~Camera() {}

void Camera::move(glm::vec3 movement) { pos += movement * scalar; }

void Camera::look(float lookX, float lookY){
    target.x -= lookX;
    target.x = std::fmod(target.x, 360.0f);

    target.y = std::min(89.0f, std::max(-89.0f, target.y + lookY));
}

glm::mat4 Camera::getView() { return glm::lookAt(pos, target, up); }
