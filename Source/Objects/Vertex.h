#ifndef VERTEX_STRUCT_H
#define VERTEX_STRUCT_H

#include<glm/glm.hpp>

// Structure to standardize the vertices used in the meshes
struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};

#endif