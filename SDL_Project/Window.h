#ifndef WINDOW_H
#define WINDOW_H

#include "SDL.h"

namespace GAME {
	class Window {
	public:
		Window();
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;
		~Window();
		bool Initialize();
		void Shutdown();
		void ClearRenderer() const;
		void SetWindowSize(const int Width_, const int Height_);
		void ToggleFullScreen();
		SDL_Renderer* GetRenderer() const;
		SDL_Surface* GetSurface() const;
		SDL_Window* GetWindow() const;
		void LoadSurface();
		int GetWidth() const;
		int GetHeight() const;
	

	protected:
	private:
		SDL_Window* SDLWindow;
		SDL_Renderer* SDLRenderer;
		SDL_Surface* SDLSurface;
		SDL_Rect winRect;

		int Width;
		int Height;

		bool bIsInitialized;
		bool bIsFullScreen;
	};
}

#endif