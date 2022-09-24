#pragma once
#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"
#include "Vec2D.h"

struct SDL_Window;
struct SDL_Surface;
class Line2D;
class Star2D;
class Screen
{
	void ClearScreen();

	uint32_t mWidth;
	uint32_t mHeight;
	Color mClearColor;
	ScreenBuffer mBackBuffer;

	SDL_Window* moptrWindow;
	SDL_Surface* mnoptrSurface;

	//we dont want to have our screen copied so copy constructor and assignment operator are in private section
	Screen(const Screen& other);
	Screen& operator=(const Screen& other);

public:
	Screen();
	~Screen();

	void SwapScreen();
	SDL_Window* Init(uint32_t width, uint32_t height, uint32_t mag);

	inline void SetClearColor(const Color& col) { mClearColor = col; }
	inline uint32_t GetWidth()const { return mWidth; }
	inline uint32_t GetHeight()const { return mHeight; }


	//Draw methods go here

	void Draw(int x, int y, const Color& col); 
	void Draw(const Vec2D& point, const Color& col);
	void Draw(const Line2D& line, const Color& col);
	void Draw(const Star2D& star, const Color& col);
	void Rotate(Line2D& line, const Color& col,float angle, bool antiClockwise = false);
	
};

