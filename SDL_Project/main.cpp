
#include "Window.h"
#include "Timer.h"
#include "GameSceneManager.h"
#include "Animation.h"
#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "Debug.h"
#include "Player.h"

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;

using namespace std;
using namespace GAME;


Window* window = new Window();
SDL_Surface* loadingSurf = NULL;
SDL_Texture* titleImage = NULL;

Timer* timer=NULL;

//void PlayAnim(SDL_Renderer* renderer, SDL_Texture* imageTexture, SDL_Rect* frameRect[], SDL_Rect* dsRect, int numOfFrames, bool play, float delay) {
//	if (play == true) {
//		if (currentFrame < numOfFrames) {
//			SDL_RenderCopy(window->GetRenderer(), imageTexture, frameRect[currentFrame], dsRect);
//			SDL_RenderPresent(window->GetRenderer());
//			SDL_Delay(delay);
//		}
//		else { currentFrame = 0; }
//		currentFrame++;
//	}
//}

int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	timer = new Timer();
	
	window->SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	window->Initialize();
	Player* sonic = new Player(window);
	sonic->Initialize();
	
	SDL_Event e;
	bool exit = false;

	//Load bmps as surfaces
	loadingSurf = SDL_LoadBMP("images/Title.bmp");

	//convert surfaces to texutres to work with the Renderer
	titleImage = SDL_CreateTextureFromSurface(window->GetRenderer(), loadingSurf);

	//FreeSurfaces after the texture conversion
	SDL_FreeSurface(loadingSurf);

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	timer->Start();

	while (!exit) {
		SDL_PollEvent(&e);
		timer->UpdateFrameTicks();

		if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
			exit = true;
		}
		//sonic->Update(timer->GetDeltaTime());
		sonic->HandleInput(&e);
		SDL_RenderClear(window->GetRenderer());
		SDL_RenderCopy(window->GetRenderer(), titleImage, NULL, NULL);
		
		SDL_RenderPresent(window->GetRenderer()); 
		sonic->Render();
		
	}

	SDL_Delay(250);
	SDL_DestroyTexture(titleImage);
	window->Shutdown();
	SDL_Quit();

	return 0;
}



