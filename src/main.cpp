#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>

#include "Window.hpp"
#include "Board.hpp"


int main(int argc, char *argv[])
{   
    // Checks if SDL has initialised properly
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL INIT FAILED" << SDL_GetError() << std::endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
        return 1;
    }
		
    // Window represents 'View' Component of MVVM pattern
    Window window = Window();

    bool gameRunning = true;
    SDL_Event event;
    
    // Main Game Loop
    while (gameRunning)
	{
		// Check if game has been exited
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
