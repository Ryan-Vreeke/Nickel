#include "Render.h"
#include "cyTriMesh.h"

Render::Render(const char *obj)
{
  CY_GL_REGISTER_DEBUG_CALLBACK;

	printf("%d\n", program.BuildFiles("../shaders/vert.vert", "../shaders/shader.frag"));
  if(!mesh.LoadFromFileObj(obj)){
    std::cerr << "couldn't load " << obj << std::endl;
    return; }

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// create a VBO
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cy::Vec3f)*mesh.NV(), &mesh.V(0), GL_STATIC_DRAW);	 // copy data in position array in to buffer
  
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
			0, 3, GL_FLOAT, GL_FALSE, 0,
			(GLvoid *)0);	 // this position is going to be using the buffer

	glBindVertexArray(0);
}

Render::~Render() {}

void Render::update( std::unordered_map<unsigned int, TransformComponent> &transformComponent)
{
	std::vector<glm::mat4> blocks;

	for (std::pair<unsigned int, TransformComponent> entity : transformComponent)
	{
		blocks.push_back(get_model(entity.second.pos));
	}

	object_count = blocks.size();
	glBindVertexArray(VAO);

	glGenBuffers(1, &models_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, models_buffer);
	glBufferData(GL_ARRAY_BUFFER, blocks.size() * sizeof(glm::mat4), &blocks[0],
							 GL_STATIC_DRAW);	 // copy data in position array in to buffer

	for (int i = 0; i < 4; i++)
	{
		glEnableVertexAttribArray(1 + i);
		glVertexAttribPointer( 1 + i, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid *)(sizeof(GLfloat) * i * 4));	 // this position is going to be using the buffer
		glVertexAttribDivisor(1 + i, 1);
	}


	glBindVertexArray(0);

	draw();
}

void Render::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.Bind();
	glBindVertexArray(VAO);

	// rendering
	glDrawArraysInstanced(GL_TRIANGLES, 0, mesh.NV(), object_count);
	glBindVertexArray(0);
}

glm::mat4 Render::get_model(glm::vec3 pos)
{
	glm::mat4 translated = translate(glm::mat4(1.0f), pos);
	return scale(translated, glm::vec3(1.0f, 1.0f, 1.0f));
}
