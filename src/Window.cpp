#include "Window.hpp"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>

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
    changed = true;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currBoard[i][j] = 0;
        }
    }

    // Exactly as seen from white's perspective, to help rendering
    // [0][RAJA][MANTRI][RATHA][GAJA][ASHVA][PADATI][COLOUR] 1 (Black) 0 (White)
    currBoard[0][0] = 0b00010001; // Black Ratha
    currBoard[0][1] = 0b00000101; // Black Ashva
    currBoard[0][2] = 0b00001001; // Black Gaja
    currBoard[0][3] = 0b01000001; // Black Raja
    currBoard[0][4] = 0b00100001; // Black Mantri
    currBoard[0][5] = 0b00001001; // Black Gaja
    currBoard[0][6] = 0b00000101; // Black Ashva
    currBoard[0][7] = 0b00010001; // Black Ratha

    for (int i = 0; i < 8; i++) {
        currBoard[1][i] = 0b00000011; // Black Padati
    }
    for (int i = 0; i < 8; i++) {
        currBoard[6][i] = 0b00000010; // White Padati
    }

    currBoard[7][0] = 0b00010000; // White Ratha
    currBoard[7][1] = 0b00000100; // White Ashva
    currBoard[7][2] = 0b00001000; // White Gaja
    currBoard[7][3] = 0b01000000; // White Raja
    currBoard[7][4] = 0b00100000; // White Mantri
    currBoard[7][5] = 0b00001000; // White Gaja
    currBoard[7][6] = 0b00000100; // White Ashva
    currBoard[7][7] = 0b00010000; // White Ratha


    // Loading all textures
    boardTexture = loadTexture("res/images/board.png");

    // White pieces
    w_raja = loadTexture("res/images/w_raja.png");
    w_mantri = loadTexture("res/images/w_mantri.png");
    w_ratha = loadTexture("res/images/w_ratha.png");
    w_gaja = loadTexture("res/images/w_gaja.png");
    w_ashva = loadTexture("res/images/w_ashva.png");
    w_padati = loadTexture("res/images/w_padati.png");
    
    // Black pieces
    b_raja = loadTexture("res/images/b_raja.png");
    b_mantri = loadTexture("res/images/b_mantri.png");
    b_ratha = loadTexture("res/images/b_ratha.png");
    b_gaja = loadTexture("res/images/b_gaja.png");
    b_ashva = loadTexture("res/images/b_ashva.png");
    b_padati = loadTexture("res/images/b_padati.png");

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

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (currBoard[row][col] != 0) {
                SDL_Rect rect = {col * 100, row * 100, 100, 100};
                int piece = currBoard[row][col];
                switch (piece)
                {   
                    // Black Pieces
                    case 0b00010001:
                        SDL_RenderCopy(renderer, b_ratha, NULL, &rect);
                        break;

                    case 0b00000101:
                        SDL_RenderCopy(renderer, b_ashva, NULL, &rect);
                        break;
                    
                    case 0b00001001:
                        SDL_RenderCopy(renderer, b_gaja, NULL, &rect);
                        break;
                    
                    case 0b01000001:
                        SDL_RenderCopy(renderer, b_raja, NULL, &rect);
                        break;
                    
                    case 0b00100001:
                        SDL_RenderCopy(renderer, b_mantri, NULL, &rect);
                        break;
                    
                    case 0b00000011:
                        SDL_RenderCopy(renderer, b_padati, NULL, &rect);
                        break;

                    
                    // White Pieces
                    case 0b00010000:
                        SDL_RenderCopy(renderer, w_ratha, NULL, &rect);
                        break;

                    case 0b00000100:
                        SDL_RenderCopy(renderer, w_ashva, NULL, &rect);
                        break;

                    case 0b00001000:
                        SDL_RenderCopy(renderer, w_gaja, NULL, &rect);
                        break;

                    case 0b01000000:
                        SDL_RenderCopy(renderer, w_raja, NULL, &rect);
                        break;

                    case 0b00100000:
                        SDL_RenderCopy(renderer, w_mantri, NULL, &rect);
                        break;

                    case 0b00000010:
                        SDL_RenderCopy(renderer, w_padati, NULL, &rect);
                        break;
                }



            }

        }
    }
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




