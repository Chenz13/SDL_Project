#include "main.h"
#include "Window.h"
#include "Timer.h"
#include "GameSceneManager.h"
#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "GameObject.h"
#include "Animator.h"


const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;

using namespace std;
using namespace GAME;

Window* window = new Window();



int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Surface* loadingSurf = NULL;
	SDL_Texture* bjs = NULL;

	SDL_Event e;
	bool exit = false;
	int frames = 0;
	loadingSurf = SDL_LoadBMP("images/bjs.bmp");







	bjs = SDL_CreateTextureFromSurface(window->GetRenderer(), loadingSurf);

	window->SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	window->Initialize();
	SDL_BlitSurface(loadingSurf, NULL, window->GetSurface(), NULL);

	
	SDL_Rect* animDst = new SDL_Rect();
	animDst->x = 200;
	animDst->y = 350;
	animDst->w = 100;
	animDst->h = 115;

	Animator* anim = new Animator("images/sprite3.bmp", window->GetSurface(), animDst, 26, 3, 11, 100, 115);
	Animator* sonicAnim = new Animator("images/SONICHD.bmp", window->GetSurface(), NULL, 22, 3, 10, 100, 110);
//	sonicAnim->SetDstRect(0,0,100,110);


	while (!exit) {
		SDL_WaitEvent(&e);

		if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
			exit = true;
		}
		
		SDL_UpdateWindowSurface(window->GetWindow());

		anim->PlayAnim();
		sonicAnim->PlayAnim();

	}



	SDL_Delay(250);
	SDL_FreeSurface(sonicAnim->testImage);
	SDL_FreeSurface(anim->testImage);
	SDL_FreeSurface(loadingSurf);
	window->Shutdown();
	return 0;
}