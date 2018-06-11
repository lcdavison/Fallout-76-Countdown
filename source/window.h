#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Window 
{
	public:
		Window();
		~Window();

		void				Init();
		void				Load();

		bool 				LoadBackground();
		bool				LoadFont();

		void				Clear();
		void				Render();

		void				RenderBackground();
		void				RenderText(const std::string, const SDL_Color&);
		void				RenderLines(const std::string);

		std::vector<std::string>	BreakTextIntoLines(const std::string);
	private:
		SDL_Texture*			background_image;
		TTF_Font*			font;	

		SDL_Window* 			window;
		SDL_Renderer* 			renderer;
};
#endif
