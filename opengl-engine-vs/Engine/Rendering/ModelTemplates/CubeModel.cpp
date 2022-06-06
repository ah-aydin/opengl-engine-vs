#include "CubeModel.h"


CubeModel::CubeModel()
{
    std::vector<Vertex> verticies = {
		{{-1, -1, 1}, {0, 0, 0}, {0, 0}},	// left bottom front
		{{-1, 1, 1}, {0, 0, 0}, {0, 1}},	// left top front
		{{1, 1, 1}, {0, 0, 0}, {1, 1}},		// right top front
		{{1, -1, 1}, {0, 0, 0}, {1, 0}},	// right bottom front
		{{-1, -1, -1}, {0, 0, 0}, {0, 0}},	// left bottom back
		{{-1, 1, -1}, {0, 0, 0}, {0, 1}},	// left top back
		{{1, 1, -1}, {0, 0, 0}, {1, 1}},	// right top back
		{{1, -1, -1}, {0, 0, 0}, {0, 1}}	// right bottom back
	};
	std::vector<unsigned int> indicies = {
		0, 1, 3,
		2, 1, 3,
		2, 3, 7,
		2, 7, 6,
		1, 2, 5,
		5, 2, 6,
		4, 7, 6,
		6, 4, 5,
		0, 1, 4,
		1, 4, 5,
		0, 4, 3,
		3, 7, 4
	};
	std::vector<Texture> textures = {};

	Mesh cubeMesh(verticies, indicies, textures);
	meshes.push_back(cubeMesh);
}