#ifndef ANIMATION_H
#define ANIMATION_H
#include "SDL.h"

class Animation
{

public:
	Animation();
	~Animation();

	SDL_Rect* animRect;
	const SDL_Rect* objRect;
	int numOfFrames;
	bool play;
	int delay;

	void PlayAnim( int numOfFrames, bool play, int delay );
	SDL_Renderer* Get_Renderer(SDL_Renderer*);
	void Set_ObjRect(SDL_Rect*);
	void LoadSpriteSheet(const char* fileNameBMP);
	SDL_Rect* Set_AnimRect(int x, int y, int w, int h, int numOfFrames, int numOfRows, int framesPerRow);
	void DestroyAnim();

private:
	int currentFrame;
	SDL_Renderer* renderer;
	SDL_Surface* spriteSheetSurf;
	SDL_Texture* spriteSheetTex;

};


#endif