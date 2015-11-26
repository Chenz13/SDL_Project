#include "Animation.h"
#include <iostream>

SDL_Surface* spriteSheetSurf = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* spriteSheetTex = NULL;
const SDL_Rect* objRect = NULL;

SDL_Rect* animRect = NULL;
Animation::Animation()
{
}


Animation::~Animation()
{
}
//editeddddddd
//creates a texture from BMP, this may be more useful in a GameObject class 
void Animation::LoadSpriteSheet(const char* fileNameBMP) {	

	spriteSheetSurf = SDL_LoadBMP(fileNameBMP);
	SDL_SetColorKey(spriteSheetSurf, SDL_TRUE, SDL_MapRGB(spriteSheetSurf->format, 255, 0, 255));
	spriteSheetTex = SDL_CreateTextureFromSurface(renderer, spriteSheetSurf);
	SDL_FreeSurface(spriteSheetSurf);

}

//Window Renderer
SDL_Renderer* Animation::Get_Renderer(SDL_Renderer* winRenderer) {
	return renderer = winRenderer;
}

//player/dstRect
void Animation::Set_ObjRect(SDL_Rect* playerRect) {
	 objRect = playerRect;
	
}

SDL_Rect* Animation::Set_AnimRect(int x, int y, int w, int h, int numOfFrames, int numOfRows, int framesPerRow) {
	
	animRect = new SDL_Rect[numOfFrames];
	int frameCount = 0;
	int rowCount = 0;
	int colCount = 0;
	for (int i = 0; i <= numOfFrames; i++) {	


		animRect[i].x = x + colCount * w;
		animRect[i].y = y + rowCount * h;
		animRect[i].w = w;
		animRect[i].h = h;

		if (frameCount = framesPerRow)
		{
			colCount = 0;
			rowCount++;
		}
		colCount++;
		frameCount++;
	}

	return animRect;
	printf(("%d, %d"), animRect[0].x, animRect[5].x);
}

//void Animation::SetAnimationState(SDL_Renderer& winRenderer, SDL_Rect& playerRect, )

void Animation::PlayAnim(int numOfFrames, bool play, int delay) {

	if (play == true) {

		if (currentFrame < numOfFrames) {
			SDL_RenderCopy(renderer, spriteSheetTex, &animRect[currentFrame], objRect);
			SDL_RenderPresent(renderer);
			SDL_Delay(delay);
		}
		else { currentFrame = 0; }
		currentFrame++;
	}
	else {
		return;
	}
}

void Animation::DestroyAnim() {
	SDL_DestroyTexture(spriteSheetTex);
}