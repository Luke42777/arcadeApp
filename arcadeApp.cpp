#include <iostream>

#include "SDL.h"
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
#include "Star2D.h"

using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 2;


int main(int argc, char * argv[]) {

	Screen theScreen;
	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	//theScreen.Draw(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Color::Red());

	/*  LINE ROTATING
	Line2D line(Vec2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), Vec2D(SCREEN_WIDTH / 2, 100.f));
	theScreen.Draw(line, Color::Blue());
	theScreen.SwapScreen();
	for (size_t i = 0; i < 5; i++) {
		SDL_Delay(1000);
		theScreen.SwapScreen();
		theScreen.Rotate(line, Color::Blue(),60.0f,true);
		theScreen.Draw(line, Color::Blue());
		theScreen.SwapScreen();
	}
	*/
	Star2D star(Vec2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), 20.f);
	theScreen.Draw(star, Color::Green());
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
