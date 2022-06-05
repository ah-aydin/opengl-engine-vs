#pragma once

#include <vector>

#include "../Camera.h"
#include "../Input.h"

/**
 * @brief Class from which all other levels/scenes should be extended from
 *
 */
class BaseScene
{
protected:
    // The main camera of the scene
    Camera* camera = nullptr;
public:
    BaseScene() { };
    // Call on creation
    virtual void init() { };
    /**
     * @brief Call on every frame for update, make sure to call the super class
     * version to handle inputs.
     *
     * @param dt time in miliseconds since last frame
     */
    virtual void update(float dt) { handleInput(); };
    virtual ~BaseScene() { };

protected:
    // Get's called with the update method to handle inputs
    virtual void handleInput() { };
};