#include "Player.h"

SDL_Rect* playerRect = NULL;
enum Animate animation;
bool run = false;
Player::Player(Window* windowInstance)
{
	window = windowInstance;
}

Player::~Player()
{
}

void Player::Initialize() {
	startFrame = 5;
	endFrame = 10;
	playerRect = new SDL_Rect();
	playerRect->x = 255;
	playerRect->y = 150;
	playerRect->w = 48;
	playerRect->h = 50;

	anim = new Animation(0, 0, 48, 50, 55, 5, 11, playerRect);
	anim->LoadSpriteSheet("images/Sonic.bmp", window->GetRenderer());
	anim->Set_Animation(5, 10);

}

void Player::Update(float deltaTime) {
	if (run) {
		anim->Set_Animation(0, 5);
	}
}

void Player::Render() {
	anim->PlayAnim(true, 100, *window->GetRenderer());
}

void Player::HandleInput(SDL_Event* e) {
	
	switch (e->type) {
	case SDL_KEYDOWN:
		switch (e->key.keysym.sym)
		{
		case SDLK_RIGHT:
			playerRect->x += 5;
			run = true;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
}



