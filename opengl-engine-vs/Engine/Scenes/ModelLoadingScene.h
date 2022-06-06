#pragma once

#include "BaseScene.h"

#include "../Rendering/Shader.h"
#include "../Rendering/Model.h"

class ModelLoadingScene : public BaseScene
{
public:
    ModelLoadingScene();
    void init() override;
    void update(float dt) override;
    ~ModelLoadingScene();

private:
    Shader* shader;
    Model* model;
};