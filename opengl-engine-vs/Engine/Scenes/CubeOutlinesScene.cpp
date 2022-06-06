#include "CubeOutlinesScene.h"

CubeOutlinesScene::~CubeOutlinesScene()
{
	delete cubeShader;
	delete outlineShader;
}

void CubeOutlinesScene::init()
{
	BaseScene::init();

	cubeShader = new Shader("res/shaders/default.vert", "res/shaders/default.frag");
	outlineShader = new Shader("res/shaders/default.vert", "res/shaders/outline.frag");
}

void CubeOutlinesScene::update(float dt)
{
	BaseScene::update(dt);

	float outlineScale = 1.1f;

	cubeShader->setMatrix4f("projection", camera->getProjectionMatrix());
	cubeShader->setMatrix4f("view", camera->getViewMatrix());
	outlineShader->setMatrix4f("projection", camera->getProjectionMatrix());
	outlineShader->setMatrix4f("view", camera->getViewMatrix());

	// Render cube 1
	glm::mat4 modelMat = glm::mat4(1.f);
	modelMat = glm::translate(modelMat, glm::vec3(-10, 0, 0));
	modelMat = glm::scale(modelMat, glm::vec3(1, 1, 1));
	cubeShader->setMatrix4f("model", modelMat);

	cube.Render(*cubeShader);
	
	// Render cube 2
	modelMat = glm::mat4(1.f);
	modelMat = glm::translate(modelMat, glm::vec3(-4, 0, -4));
	modelMat = glm::scale(modelMat, glm::vec3(1, 1, 2));
	cubeShader->setMatrix4f("model", modelMat);

	cube.Render(*cubeShader);

	// Render cube 3
	modelMat = glm::mat4(1.f);
	modelMat = glm::translate(modelMat, glm::vec3(4, 0, -1));
	modelMat = glm::scale(modelMat, glm::vec3(2, 0.5, 1));
	cubeShader->setMatrix4f("model", modelMat);

	// Write on the stencil mask
	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilMask(0xFF);
	cube.Render(*cubeShader);

	// Render the outline
	glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
	glStencilMask(0x00); // We don't want to write on the stencil mask with the outlines
	glDisable(GL_DEPTH_TEST);
	modelMat = glm::scale(modelMat, glm::vec3(1) * outlineScale);
	outlineShader->setMatrix4f("model", modelMat);
	cube.Render(*outlineShader);

	// Reset the stencil mask and function, enable the depth test
	glStencilMask(0xFF);
	glStencilFunc(GL_ALWAYS, 0, 0xFF);
	glEnable(GL_DEPTH_TEST);
}