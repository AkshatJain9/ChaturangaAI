#include "Window.hpp"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

Window::Window():window(NULL), renderer(NULL)
{   
    // Initialise pointers to window and renderer
    window = SDL_CreateWindow("Chaturanga", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_ALLOW_HIGHDPI);
    
    if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
    }

    // Initialise board render state
    changed = false;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            currBoard[i][j] = 0;
        }
    }

    boardTexture = loadTexture("res/images/board.png");

    if (boardTexture == NULL)
    {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }
   
}

// Load Texture from file
SDL_Texture* Window::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

// Clears the screen for fresh rendering
void Window::clear()
{
	SDL_RenderClear(renderer);
}

// Main render function, reading from currBoard and rendering to screen
void Window::render()
{
	SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
}

// Display the rendered screen
void Window::display()
{
	SDL_RenderPresent(renderer);
}

// Clean Up Rendering Environment before Exiting
void Window::cleanUp()
{
	SDL_DestroyWindow(window);
}




