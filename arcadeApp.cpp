#include <iostream>

#include "SDL.h"
#include "Color.h"
#include "Screen.h"

using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 1;


int main(int argc, char * argv[]) {

	Screen screen;
	screen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	screen.Draw(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Color::Red());
	screen.SwapScreen();

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
	

	return 0;
}
