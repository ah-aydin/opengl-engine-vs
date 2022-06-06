#include "BaseScene.h"

void BaseScene::init()
{
    camera = new Camera(0, 0, 0, 0, -40, 0, 90, 1600.f / 900.f);
}

void BaseScene::handleInput()
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