#ifndef ANIMATION_H
#define ANIMATION_H
#include "SDL.h"

class Animation
{

public:
	Animation();
	~Animation();

	SDL_Rect* animRect;
	SDL_Rect* objRect;
	int numOfFrames;
	bool play;
	int delay;

	void PlayAnim(SDL_Rect* animRect[], int numOfFrames, bool play, int delay );
	SDL_Renderer* Get_Renderer(SDL_Renderer&);
	SDL_Rect* Set_ObjRect(SDL_Rect&);
	void LoadSpriteSheet(const char* fileNameBMP);
	void Set_AnimRect(int x, int y, int w, int h, int numOfFrames, int numOfRows, int framesPerRow);

private:
	int currentFrame;
	SDL_Renderer* renderer;
	SDL_Surface* spriteSheetSurf;
	SDL_Texture* spriteSheetTex;

};


#endif