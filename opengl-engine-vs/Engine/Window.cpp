#include "Window.h"

#include <GL/glew.h>

Window::~Window()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
}

/**
 * @brief Initializes the window
 *
 * @return true - Initialized with success | false - Initialization failed
 */
bool Window::init()
{
    // Create window
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE, WINDOW_FLAGS);
    if (!window)
    {
        return false;
    }

    // Create OpenGL context
    context = SDL_GL_CreateContext(window);
    SDL_GetWindowSize(window, &width, &height);
    return true;
}

/**
 * Call this at the end of the main loop
 */
void Window::swapWindow()
{
    SDL_GL_SwapWindow(window);
}