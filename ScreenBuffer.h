#pragma once
class Color;
struct SDL_Surface;
#include <stdint.h>

class ScreenBuffer {
	SDL_Surface* mSurface;
	uint32_t GetIndex(int row, int column)const;
public:
	ScreenBuffer():mSurface(nullptr) {}
	ScreenBuffer(const ScreenBuffer& other);
	~ScreenBuffer();

	inline SDL_Surface* GetSurface()const { return mSurface; }
	ScreenBuffer& operator=(const ScreenBuffer& other);
	void Init(uint32_t format, uint32_t width, uint32_t height);
	void Clear(const Color& col);
	void SetPixel(const Color& col,int x,int y);
};
