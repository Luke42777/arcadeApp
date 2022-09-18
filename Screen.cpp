#include "Screen.h"
#include "Vec2D.h"
#include "SDL.h"
#include <cassert>


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
SDL_Window* Screen::Init(uint32_t width, uint32_t height, uint32_t mag) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL_Init failed\n";
		return nullptr;
	}
	mWidth = width;
	mHeight = height;

	moptrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth * mag, mHeight * mag,0);
	if (moptrWindow) {
		mnoptrSurface = SDL_GetWindowSurface(moptrWindow);
		SDL_PixelFormat* pixelFormat = mnoptrSurface->format;
		Color::InitColorFormat(pixelFormat);
		mClearColor = Color::Black();
		mBackBuffer.Init(pixelFormat->format, mWidth, mHeight);
		mBackBuffer.Clear(mClearColor);
		return moptrWindow;
	}
    return nullptr;
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
