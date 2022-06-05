#pragma once

#include <SDL/SDL.h>
#include <map>
#include <string>

#define KEY_ARRAY_SIZE 501

/**
 * @brief Datatype to store mouse movement
 */
struct Mouse
{
    Sint32 x, y;
};

/**
 * @brief Datatype to store a trigger related to a key
 */
struct InputAction
{
    SDL_KeyCode keyCode;
};

/**
 * @brief Datatype to store an input axis given a positive and negative key
 */
struct InputAxis
{
    SDL_KeyCode positiveKey;
    SDL_KeyCode negativeKey;
};

/**
 * @brief Class that provides static methods to access the created
 * input axes, input actions and mouse movements.
 */
class Input
{
private:
    static bool keys[KEY_ARRAY_SIZE];
    static int convertKeycode(SDL_KeyCode);
    static bool getKeyPress(SDL_KeyCode);

    static Mouse mouse;
    static std::map<std::string, InputAction> actions;
    static std::map<std::string, InputAxis> axes;

public:
    // Event handlers
    static void keyDown(SDL_KeyCode code);
    static void keyUp(SDL_KeyCode code);
    static void mouseMotion(Sint32 x, Sint32 y);
    static void resetMouse();

    // Input creation
    static void createAction(const std::string& name, SDL_KeyCode keyCode);
    static void createAxis(const std::string& name, SDL_KeyCode positiveKey, SDL_KeyCode negativeKey);

    // Input access
    static bool getAction(const std::string& action);
    static float getAxis(const std::string& axis);
    static Sint32 mouseX();
    static Sint32 mouseY();
};