#include <SDL.h>
#include "ScreenBuffer.h"
#include "Color.h"
#include <cassert>


ScreenBuffer::ScreenBuffer(const ScreenBuffer& other) {
	if (other.mSurface != nullptr) {
		mSurface = SDL_CreateRGBSurfaceWithFormat(0, other.mSurface->w, other.mSurface->h, 0, other.mSurface->format->format);
		SDL_BlitSurface(other.mSurface, nullptr, mSurface, nullptr);
	}
}
ScreenBuffer::~ScreenBuffer() {
	if (mSurface) {
		SDL_FreeSurface(mSurface);
	}
}
ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& other) {
	if (&other == this) {
		return *this;
	}
	if (mSurface) {
		SDL_FreeSurface(mSurface);
		mSurface = nullptr;
	}
	
	if (other.mSurface != nullptr) {
		mSurface = SDL_CreateRGBSurfaceWithFormat(0, other.mSurface->w, other.mSurface->h, 0, other.mSurface->format->format);
		SDL_BlitSurface(other.mSurface, nullptr, mSurface, nullptr);//copy all of the pixels from other to *this
	}
	return *this;	
}
void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height) {
	mSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
}
uint32_t ScreenBuffer::GetIndex(int row, int column)const {
	assert(mSurface);
	if (mSurface) {
		return row * mSurface->w + column;
	}
	return 0;
	
}
void ScreenBuffer::SetPixel(const Color& color, int x, int y) {
	assert(mSurface);
	if (y >= 0 && y < mSurface->h && x >= 0 && x < mSurface->w) {
		SDL_LockSurface(mSurface);

		uint32_t* pixels = (uint32_t*)mSurface->pixels;
		size_t index = GetIndex(y, x);
		pixels[index] = color.GetPixelColor();

		SDL_UnlockSurface(mSurface);
	}
}
void ScreenBuffer::Clear(const Color& col) {
	assert(mSurface);//debug 
	if (mSurface) {
		SDL_FillRect(mSurface, nullptr, col.GetPixelColor());
	}
}