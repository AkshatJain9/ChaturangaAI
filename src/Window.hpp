#pragma once
#include <SDL.h>
#include <SDL_image.h>

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
    int currBoard [8][8];
    SDL_Texture* boardTexture;
};