#pragma once

#include <SDL/SDL.h>

#include "Window.h"

class Application
{
public:
    Application() {};
    ~Application();

private:
    // Initialization
    bool init();
    bool sdlInit();
    bool glInit();
    void inputInit();
    // Terminate
    void quit();

    // Main loop
    void mainLoop();
    void PollEvents();
    bool running = true;
    SDL_Event event;

public:
    int run();

    Window window;
};