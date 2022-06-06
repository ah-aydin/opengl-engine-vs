#pragma once

#include "BaseScene.h"

#include "../Rendering/ModelTemplates/CubeModel.h"
#include "../Rendering/Shader.h"

class CubeOutlinesScene : public BaseScene
{
public:
	void init() override;
	void update(float dt) override;

	~CubeOutlinesScene();

private:
	CubeModel cube;
	Shader *cubeShader;
	Shader *outlineShader;
};

