#include "Screen.h"
#include "Vec2D.h"
#include "SDL.h"
#include <cassert>
#include "Line2D.h"


Screen::Screen() : mnoptrSurface(nullptr), moptrWindow(nullptr), mWidth(0), mHeight(0) {}

Screen::~Screen() {
	if (moptrWindow) {
		SDL_DestroyWindow(moptrWindow);
		moptrWindow = nullptr;
	}
	SDL_Quit();
}

void Screen::ClearScreen(){
	assert(moptrWindow);
	if (moptrWindow) {
		SDL_FillRect(mnoptrSurface, nullptr, mClearColor.GetPixelColor());
	}
}
SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag) {
	if (SDL_Init(SDL_INIT_VIDEO)){
		std::cout << "Error SDL_Init Failed" << std::endl;
		return nullptr;
	}

	mWidth = w;
	mHeight = h;

	moptrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth * mag, mHeight * mag, 1);

	if (moptrWindow)
	{
		mnoptrSurface = SDL_GetWindowSurface(moptrWindow);
		SDL_PixelFormat* pixelFormat = mnoptrSurface->format;
		Color::InitColorFormat(pixelFormat);
		mClearColor = Color::Black();
		mBackBuffer.Init(pixelFormat->format, mWidth, mHeight);
		mBackBuffer.Clear(mClearColor);
	}
	return moptrWindow;
}

void Screen::SwapScreen(){
	assert(moptrWindow);
	if (moptrWindow) {
		ClearScreen();
		SDL_BlitSurface(mBackBuffer.GetSurface(), nullptr, mnoptrSurface, nullptr);
		SDL_UpdateWindowSurface(moptrWindow);
		mBackBuffer.Clear(mClearColor);
	}
}

void Screen::Draw(int x, int y, const Color& col){
	assert(moptrWindow);
	if (moptrWindow) {
		mBackBuffer.SetPixel(col, x, y);
	}
}

void Screen::Draw(const Vec2D& point, const Color& col){
	assert(moptrWindow);
	if(moptrWindow) {
		mBackBuffer.SetPixel(Color::Blue(), point.GetX(), point.GetY());
	}
}

void Screen::Draw(const Line2D& line, const Color& col){
	assert(moptrWindow);
	if (moptrWindow)
	{
		int dx, dy;

		int x0 = roundf(line.GetP0().GetX());
		int y0 = roundf(line.GetP0().GetY());
		int x1 = roundf(line.GetP1().GetX());
		int y1 = roundf(line.GetP1().GetY());

		dx = x1 - x0;
		dy = y1 - y0;

		signed const char ix((dx > 0) - (dx < 0)); // evaluate to 1 or -1
		signed const char iy((dy > 0) - (dy < 0));

		dx = abs(dx) * 2; // not sure its neccessary
		dy = abs(dy) * 2;

		Draw(x0, y0, col);

		if (dx >= dy)
		{
			//go along in the x, only x will be incremented

			int d = dy - dx / 2; // decision parameter

			while (x0 != x1)
			{
				if (d >= 0)
				{
					d -= dx;
					y0 += iy;
				}

				d += dy;
				x0 += ix;

				Draw(x0, y0, col);
			}
		}
		else
		{
			//go along in y
			int d = dx - dy / 2;

			while (y0 != y1)
			{
				if (d >= 0)
				{
					d -= dy;
					x0 += ix;
				}

				d += dx;
				y0 += iy;

				Draw(x0, y0, col);
			}
		}
	}
}
