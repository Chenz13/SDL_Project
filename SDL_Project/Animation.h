#ifndef ANIMATION_H
#define ANIMATION_H
#include "SDL.h"

class Animation
{

public:
	Animation(int _x, int _y, int _w, int _h, int _numOfFrames, int _numOfRows, int _framesPerRow, SDL_Rect* objRect);
	~Animation();

	int x, y, w, h;
	int framesPerRow, numOfFrames, numOfRows;

	SDL_Rect* animRect;
	SDL_Rect* objRect;
	//const SDL_Rect* objRect;

	bool play;
	int delay;
	int frameCount;
	int rowCount;
	int colCount;
	void PlayAnim( int numOfFrames, bool play, int delay, SDL_Renderer& renderer );
	//SDL_Renderer* Get_Renderer(SDL_Renderer*);
	void Set_ObjRect(SDL_Rect*);
	SDL_Texture* LoadSpriteSheet(const char* fileNameBMP, SDL_Renderer* renderer);
	void Set_AnimRect();
	void DestroyAnim();

private:
	int currentFrame;
	//SDL_Renderer* renderer;
	SDL_Surface* spriteSheetSurf;
	SDL_Texture* spriteSheetTex;

};


#endif