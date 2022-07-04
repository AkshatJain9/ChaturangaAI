#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>

#include "Window.hpp"
#include "Board.hpp"

int WIDTH = 800;
int HEIGHT = 800;

int main(int argc, char *argv[])
{   
    
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL INIT FAILED" << SDL_GetError() << std::endl;
    }

    Window window = Window();

    bool gameRunning = true;
    SDL_Event event;
    while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		window.render();
		window.display();

	}
    window.cleanUp();


    SDL_Quit();

    return EXIT_SUCCESS;
}
