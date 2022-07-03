#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>

int WIDTH = 800;
int HEIGHT = 800;

int main(int argc, char *argv[])
{   
    
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL INIT FAILED" << SDL_GetError() << std::endl;
    }

    SDL_Rect rect = {100, 100, 100 , 100};

    SDL_Window* window = SDL_CreateWindow("Chaturanga", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == window)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Texture* boardTexture = IMG_LoadTexture(renderer, "res/images/board.png");

    SDL_Texture* testPiece = IMG_LoadTexture(renderer, "res/images/w_gaja.png");

    if (boardTexture == NULL) {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }

    SDL_Event windowEvent;

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {break;}
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
        SDL_RenderCopy(renderer, testPiece, NULL, &rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
