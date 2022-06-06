#include "ModelLoadingScene.h"

ModelLoadingScene::ModelLoadingScene()
{

}

ModelLoadingScene::~ModelLoadingScene()
{
    delete shader;
    delete model;
}

void ModelLoadingScene::init()
{
    BaseScene::init();

    shader = new Shader("res/shaders/model_loading.vert", "res/shaders/model_loading.frag");
    model = new Model("res/models/backpack/", "backpack.obj");
}

void ModelLoadingScene::update(float dt)
{
    BaseScene::update(dt);

    shader->setMatrix4f("projection", camera->getProjectionMatrix());
    shader->setMatrix4f("view", camera->getViewMatrix());

    glm::mat4 modelMat = glm::mat4(1.f);
    modelMat = glm::translate(modelMat, glm::vec3(0, 0, 0));
    modelMat = glm::scale(modelMat, glm::vec3(1, 1, 1));
    shader->setMatrix4f("model", modelMat);
    model->Render(*shader);
}