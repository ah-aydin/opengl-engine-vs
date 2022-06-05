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
    camera = new Camera(0, 0, 0, 0, -40, 0, 90, 1600.f / 900.f);
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

void ModelLoadingScene::handleInput()
{
    // Handle camera input
    float forward = Input::getAxis("forward");
    float right = Input::getAxis("right");
    float up = Input::getAction("jump") ? 1.f : 0.f;
    float down = Input::getAction("crouch") ? 1.f : 0.f;
    float mouseX = (float)Input::mouseX();
    float mouseY = (float)Input::mouseY();

    camera->handleInput(forward, right, up, down, mouseX, mouseY);
}