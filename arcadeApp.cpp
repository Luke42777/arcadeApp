#include <iostream>

#include "SDL.h"
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"

using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;


int main(int argc, char * argv[]) {

	Screen theScreen;
	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	//theScreen.Draw(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Color::Red());
	theScreen.Draw(Line2D(Vec2D(0, 0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)), Color::Blue());
	theScreen.SwapScreen();

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
