#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>

class Window {
    public:
    Window();
    void display();
    void cleanUp();
	void clear();
	void render();
    SDL_Texture* loadTexture(const char* p_filePath);


    private:
    SDL_Window* window;
	SDL_Renderer* renderer;
    bool changed;
    uint8_t currBoard [8][8];
    SDL_Texture* boardTexture;

    SDL_Texture* w_raja;
    SDL_Texture* w_mantri;
    SDL_Texture* w_ratha;
    SDL_Texture* w_gaja;
    SDL_Texture* w_ashva;
    SDL_Texture* w_padati;

    SDL_Texture* b_raja;
    SDL_Texture* b_mantri;
    SDL_Texture* b_ratha;
    SDL_Texture* b_gaja;
    SDL_Texture* b_ashva;
    SDL_Texture* b_padati;


};