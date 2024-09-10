#version 430 core
layout(location=0) in vec3 pos;

layout(location = 1) in vec4 modelMatrix1;
layout(location = 2) in vec4 modelMatrix2;
layout(location = 3) in vec4 modelMatrix3;
layout(location = 4) in vec4 modelMatrix4;

void main(){
  mat4 model = mat4(modelMatrix1, modelMatrix2, modelMatrix3, modelMatrix4);
  gl_Position = model * vec4(pos, 1.0);
}
