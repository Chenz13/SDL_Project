#include "Window.h"
#include <string>
#include "string.h"
#include <sstream>
#include "Debug.h"

using namespace GAME;
using namespace std;
Window::Window() :SDLWindow(nullptr), SDLRenderer(nullptr), SDLSurface(nullptr), winRect(), Width(0), Height(0), bIsInitialized(false), bIsFullScreen(false) {
}

Window::~Window() {
	Shutdown();
}

bool Window::Initialize() {
	bIsInitialized = false;



	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		Debug::Log(EMessageType::FATAL_ERROR, std::string(SDL_GetError()), __FILE__, __LINE__);
		return bIsInitialized = false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		Debug::Log(EMessageType::WARNING, "Linear texture filtering is not enabled.", __FILE__, __LINE__);
	}

	SDLWindow = SDL_CreateWindow("SDL Example Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winRect.w, winRect.h, SDL_WINDOW_SHOWN);
	if (!SDLWindow) {
		Debug::Log(EMessageType::FATAL_ERROR, "Failed to create a window!", __FILE__, __LINE__);
		Shutdown();
		return false;
	}

	SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);

	if (!SDLRenderer) {
		Debug::Log(EMessageType::FATAL_ERROR, std::string(SDL_GetError()), __FILE__, __LINE__);
		Shutdown();
		return false;
	}

	SDLSurface = SDL_GetWindowSurface(SDLWindow);

	if (!SDLWindow) {
		Debug::Log(EMessageType::FATAL_ERROR, std::string(SDL_GetError()), __FILE__, __LINE__);
		Shutdown();
		return false;
	}

	SDL_SetRenderDrawColor(SDLRenderer, 0, 0, 0, 255);
	SDL_RenderPresent(SDLRenderer);
	SDL_RenderFillRect(SDLRenderer, &winRect);


	SDLSurface = SDL_GetWindowSurface(SDLWindow);


	bIsInitialized = true;
	return true;
}

void Window::Shutdown() {
	SDL_FreeSurface(SDLSurface);
	SDLSurface = nullptr;
	SDL_DestroyRenderer(SDLRenderer);
	SDLRenderer = nullptr;
	SDL_DestroyWindow(SDLWindow);
	SDLWindow = nullptr;

	bIsInitialized = false;
}

void Window::SetWindowSize(const int Width_, const int Height_) {
	winRect.w = Width_;
	winRect.h = Height_;
}

void Window::ClearRenderer() const {
	SDL_SetRenderDrawColor(SDLRenderer, 0, 0, 0, 255);
	SDL_RenderClear(SDLRenderer);
}

void Window::ToggleFullScreen() {
	bIsFullScreen = !bIsFullScreen;
	SDL_SetWindowFullscreen(SDLWindow, (bIsFullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN));
}

SDL_Window* Window::GetWindow() const {
	return SDLWindow;
}


SDL_Renderer* Window::GetRenderer() const {
	return SDLRenderer;
}

SDL_Surface* Window::GetSurface() const {

	return SDLSurface;
}

int Window::GetWidth() const {
	return Width;
}

int Window::GetHeight() const {
	return Height;
}