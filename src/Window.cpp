#include "Window.hpp"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

Window::Window()
{
    window = SDL_CreateWindow("Chaturanga", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_ALLOW_HIGHDPI);
    
    if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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

SDL_Texture* Window::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void Window::cleanUp()
{
	SDL_DestroyWindow(window);
}

void Window::clear()
{
	SDL_RenderClear(renderer);
}

void Window::render()
{
	SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
}

void Window::display()
{
	SDL_RenderPresent(renderer);
}