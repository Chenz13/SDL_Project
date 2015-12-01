#include "Animation.h"
#include <iostream>

SDL_Surface* spriteSheetSurf = NULL;
//SDL_Renderer* renderer = NULL;
SDL_Texture* spriteSheetTex = NULL;
SDL_Rect* objRect = NULL;
SDL_Rect* animRect = NULL;

int frameCount = 0;
int rowCount = 0;
int colCount = 0;

Animation::Animation(int _x, int _y, int _w, int _h, int _numOfFrames, int _numOfRows, int _framesPerRow, SDL_Rect* _objRect)
{
	x = _x; y = _y; w = _w; h = _h;

	numOfFrames = _numOfFrames; numOfRows = _numOfRows; framesPerRow = _framesPerRow;
	objRect = _objRect;
	animRect = new SDL_Rect[numOfFrames];
	Animation::Set_AnimRect();
}


Animation::~Animation()
{
}

//editeddddddd
//creates a texture from BMP, this may be more useful in a GameObject class 
SDL_Texture* Animation::LoadSpriteSheet(const char* fileNameBMP, SDL_Renderer* renderer) {	

	spriteSheetSurf = SDL_LoadBMP(fileNameBMP);
	SDL_SetColorKey(spriteSheetSurf, SDL_TRUE, SDL_MapRGB(spriteSheetSurf->format, 255, 0, 255));
	spriteSheetTex = SDL_CreateTextureFromSurface(renderer, spriteSheetSurf);
	SDL_FreeSurface(spriteSheetSurf);
	return spriteSheetTex;
}

//Window Renderer
//SDL_Renderer* Animation::Get_Renderer(SDL_Renderer* winRenderer) {
//	return renderer = winRenderer;
//}

//player/dstRect
//void Animation::Set_ObjRect(SDL_Rect* playerRect) {
//	 objRect = playerRect;
//	
//}

void Animation::Set_AnimRect() {

	for (int i = 0; i < numOfFrames; i++) {

		if (frameCount < numOfFrames) {

			animRect[frameCount].x =  colCount * w;
			animRect[frameCount].y =  rowCount * h;
			animRect[frameCount].w = w;
			animRect[frameCount].h = h;

			std::cout << "frameCount " << frameCount << " colCount " << colCount << " rowCount " << rowCount << " x = " << animRect[frameCount].x << " y = " << animRect[frameCount].y << std::endl;
		}

		if (colCount == framesPerRow)
		{
			colCount = 0;
			rowCount++;
		}

		frameCount++;
		colCount++;
	}

}

//void Animation::SetAnimationState(SDL_Renderer& winRenderer, SDL_Rect& playerRect, )

void Animation::PlayAnim(int numOfFrames, bool play, int delay, SDL_Renderer& renderer) {

	if (play == true) {

		if (currentFrame < numOfFrames) {
			SDL_RenderCopy(&renderer, spriteSheetTex, &animRect[currentFrame], objRect);
			SDL_RenderPresent(&renderer);
			SDL_Delay(delay);
			
		}
		else { 
			currentFrame = 0;
		}
		std::cout << "currentFrame " << currentFrame << std::endl;
		currentFrame++;
	}
	
}

void Animation::DestroyAnim() {
	SDL_DestroyTexture(spriteSheetTex);
}