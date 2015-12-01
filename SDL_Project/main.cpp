
#include "Window.h"
#include "Timer.h"
#include "GameSceneManager.h"
#include "Animation.h"
#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "Debug.h"

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;

using namespace std;
using namespace GAME;

Animation* anim = NULL;
Window* window = new Window();
SDL_Surface* loadingSurf = NULL;
SDL_Surface* sonicSurf = NULL;
SDL_Texture* titleImage = NULL;
SDL_Texture* sonicTexture = NULL;

SDL_Rect* frame = NULL;
SDL_Rect* playerRect;
int currentFrame = 0;



void PlayAnim(SDL_Renderer* renderer, SDL_Texture* imageTexture, SDL_Rect* frameRect[], SDL_Rect* dsRect, int numOfFrames, bool play, float delay) {
	if (play == true) {
		if (currentFrame < numOfFrames) {
			SDL_RenderCopy(window->GetRenderer(), imageTexture, frameRect[currentFrame], dsRect);
			SDL_RenderPresent(window->GetRenderer());
			SDL_Delay(delay);
		}
		else { currentFrame = 0; }
		currentFrame++;
	}
}

int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	playerRect = new SDL_Rect();
	playerRect->x = 150;
	playerRect->y = 150;
	playerRect->w = 48;
	playerRect->h = 50;
	
	window->SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	window->Initialize();
	anim = new Animation(0, 0, 48, 50, 55, 5, 11, playerRect);
	anim->LoadSpriteSheet("images/Sonic.bmp", window->GetRenderer());

	
	SDL_Event e;
	bool exit = false;
	int frames = 0;

	//Load bmps as surfaces
	loadingSurf = SDL_LoadBMP("images/Title.bmp");
	sonicSurf = SDL_LoadBMP("images/Sonic.bmp");
	
	//before converting to texture, remove the background colour with the colour key of the background
	SDL_SetColorKey(sonicSurf, SDL_TRUE, SDL_MapRGB(sonicSurf->format, 255,0,255));

	//convert surfaces to texutres to work with the Renderer
	titleImage = SDL_CreateTextureFromSurface(window->GetRenderer(), loadingSurf);
	sonicTexture = SDL_CreateTextureFromSurface(window->GetRenderer(), sonicSurf);

	//FreeSurfaces after the texture conversion
	SDL_FreeSurface(loadingSurf);
	SDL_FreeSurface(sonicSurf);
	
	SDL_Rect* idleFrame[6];
	SDL_Rect* frame[6];

	for (int i = 0; i <=5; i++) {
		frame[i] = new SDL_Rect();

		frame[i]->x = i * 48;
		frame[i]->y = 0;
		frame[i]->w = 48;
		frame[i]->h = 50;
	}
	for (int i = 0; i <= 5; i++) {
		idleFrame[i] = new SDL_Rect();
		idleFrame[i]->x = (5 + i) * 48;
		idleFrame[i]->y = 0;
		idleFrame[i]->w = 48;
		idleFrame[i]->h = 50;
	}

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	while (!exit) {
		SDL_PollEvent(&e);

		if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
			exit = true;
		}

		SDL_RenderClear(window->GetRenderer());
		SDL_RenderCopy(window->GetRenderer(), titleImage, NULL, NULL);
		
		anim->PlayAnim(55, true, 100, *window->GetRenderer());
	//	PlayAnim(window->GetRenderer(), sonicTexture, idleFrame, playerRect, 6, true, 50);
		//SDL_RenderPresent(window->GetRenderer()); 
	}

	SDL_Delay(250);
	SDL_DestroyTexture(titleImage);
	SDL_DestroyTexture(sonicTexture);
	anim->DestroyAnim();
	window->Shutdown();
	SDL_Quit();

	return 0;
}



