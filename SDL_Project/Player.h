#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Window.h"
using namespace GAME;
class Player : GameObject
{
private:
	//enum Animate {
	//	IDLE,
	//	WALKING,
	//	RUNNING,
	//	SPINNING,

	//};

	Window* window;
	Animation* anim;
	SDL_Rect* playerRect;

	int startFrame;
	int endFrame;
	bool run;
	//void HandleAnimation();

public:
	void Initialize();
	void Update(float deltaTime);
	void Render();
	void HandleInput(SDL_Event*);
	Player(Window*);
	~Player();

};

