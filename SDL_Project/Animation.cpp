#include "Animation.h"

SDL_Surface* spriteSheetSurf = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* spriteSheetTex = NULL;
SDL_Rect* objRect = NULL;
SDL_Rect* animRect = NULL;

Animation::Animation()
{
}


Animation::~Animation()
{
}

//creates a texture from BMP, this may be more useful in a GameObject class 
void Animation::LoadSpriteSheet(const char* fileNameBMP) {	
	spriteSheetSurf = SDL_LoadBMP(fileNameBMP);
	spriteSheetTex = SDL_CreateTextureFromSurface(renderer, spriteSheetSurf);
}

//Window Renderer
SDL_Renderer* Animation::Get_Renderer(SDL_Renderer& winRenderer) {
	return renderer = &winRenderer;
}

//player/dstRect
SDL_Rect* Animation::Set_ObjRect(SDL_Rect& playerRect) {
	return objRect = &playerRect;
}

void Animation::Set_AnimRect(int x, int y, int w, int h, int numOfFrames, int numOfRows, int framesPerRow) {
	
	int frameCount=0;
	int rowCount = 0;
	
	for (int i = 0; i <= numOfFrames; i++) {	
		
		if (frameCount = framesPerRow)
			{
				rowCount++;
		}
		frameCount++;

		animRect = new SDL_Rect[numOfFrames];

		animRect[i].x = x + i * w;
		animRect[i].y = y + rowCount * h;
		animRect[i].w = w;
		animRect[i].h = h;
	}
}

//void Animation::SetAnimationState(SDL_Renderer& winRenderer, SDL_Rect& playerRect, )

void Animation::PlayAnim(SDL_Rect* animRect[], int numOfFrames, bool play, int delay) {

	if (play == true) {

		if (currentFrame < numOfFrames) {
			SDL_RenderCopy(renderer, spriteSheetTex, animRect[currentFrame], objRect);
			SDL_RenderPresent(renderer);
			SDL_Delay(delay);
		}
		else { currentFrame = 0; }
		currentFrame++;
	}
}