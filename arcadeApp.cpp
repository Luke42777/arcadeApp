#include <iostream>

#include "SDL.h"
#include "Color.h"

using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

size_t GetIndex(SDL_Surface* noptrWindowSurface, int row, int column) {
	return row * noptrWindowSurface->w + column;
}
void SetPixel(SDL_Surface* noptrWindowSurface, Color color, int x, int y) {
	SDL_LockSurface(noptrWindowSurface);

	uint32_t * pixels = (uint32_t*)noptrWindowSurface->pixels;
	size_t index = GetIndex(noptrWindowSurface, y, x);
	pixels[index] = color.GetPixelColor();

	SDL_UnlockSurface(noptrWindowSurface);
}

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL_Init failed\n";
		return 1;
	}

	SDL_Window* optrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (optrWindow == nullptr) {
		cout << "Couldn't create window. Got error: " << SDL_GetError() << endl;
	}

	SDL_Surface* noptrSurface = SDL_GetWindowSurface(optrWindow);

	
	
	SDL_PixelFormat* pixelFormat = noptrSurface->format;
	
	Color::InitColorFormat(pixelFormat);
	

	cout << SDL_GetPixelFormatName(pixelFormat->format);
	SetPixel(noptrSurface, Color::Blue(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	SDL_UpdateWindowSurface(optrWindow);

	SDL_Event sdlEvent;
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&sdlEvent)) {
			switch (sdlEvent.type) {
				case SDL_QUIT:
				{
					running = false;
					break;
				}
			}
		}
	}
	SDL_DestroyWindow(optrWindow);
	SDL_Quit();

	return 0;
}
