#include "window.h"

Window::Window() 
{
	Init();
	Load();
}

Window::~Window() 
{
	if ( window ) 
	{
		SDL_DestroyWindow ( window );
		window = nullptr;
	}

	if ( renderer ) 
	{
		SDL_DestroyRenderer ( renderer );
		renderer = nullptr;
	}

	if ( background_image )
	{
		SDL_DestroyTexture ( background_image );
		background_image = nullptr;
	}

	if ( font )
	{
		TTF_CloseFont ( font );
		font = nullptr;
	}
}

void Window::Init() 
{
	if ( SDL_Init ( SDL_INIT_EVERYTHING ) < 0 ) 
	{
		std::cout << "Failed to intialize SDL2 Library" << std::endl;
	}

	if ( TTF_Init () < 0 ) 
	{
		std::cout << "Failed to intialize SDL_TTF Library" << std::endl;
	}

	if ( IMG_Init ( IMG_INIT_JPG ) < 0 ) 
	{
		std::cout << "Failed to intialize SDL_Image Library" << std::endl;
	}

	window = SDL_CreateWindow ( "Fallout 76 Countdown", 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			500, 282,
			0 );

	if ( !window ) 
	{
		std::cout << "Failed to create SDL Window" << std::endl;
	}

	renderer = SDL_CreateRenderer ( window, -1, SDL_RENDERER_ACCELERATED );

	if ( !renderer )
	{
		std::cout << "Failed to create SDL Renderer" << std::endl;
	}

	SDL_SetRenderDrawColor ( renderer, 0, 0, 0, SDL_ALPHA_OPAQUE );
}

void Window::Load() 
{
	if ( !LoadBackground ( ) ) 
	{
		std::cout << "Failed to load background image" << std::endl;
	}

	if ( !LoadFont ( ) ) 
	{
		std::cout << "Failed to load font" << std::endl;
	}
}

bool Window::LoadBackground() 
{
	SDL_Surface* background_surface = IMG_Load ( "./resources/images/background.jpg" );

	if ( !background_surface ) 
	{
		return false;
	}
	else 
	{
		background_image = SDL_CreateTextureFromSurface ( renderer, background_surface );
		SDL_FreeSurface ( background_surface );

		SDL_SetTextureBlendMode ( background_image, SDL_BLENDMODE_BLEND );
		SDL_SetTextureAlphaMod ( background_image, 150 ); 
	}

	return true;
}

bool Window::LoadFont() 
{
	font = TTF_OpenFont("./resources/fonts/STENCIL.TTF", 24);

	return font != NULL;
}

void Window::Clear() 
{
	SDL_RenderClear ( renderer );
}

void Window::Render() 
{
	SDL_RenderPresent ( renderer );
}

void Window::RenderBackground() 
{
	SDL_Rect rect = { 0, 0, 500, 282 };
	SDL_RenderCopy ( renderer, background_image, NULL, &rect );
}

void Window::RenderText(const std::string text, const SDL_Color& color) 
{
	SDL_Surface* text_surface = TTF_RenderText_Solid ( font, text.c_str(), color );

	if ( !text_surface ) 
	{
		std::cout << "Failed to render text" << std::endl;
	} 
	else 
	{
		SDL_Texture* text_texture = SDL_CreateTextureFromSurface ( renderer, text_surface );
		SDL_FreeSurface ( text_surface );

		int tw, th, fw;
		SDL_QueryTexture ( text_texture, NULL, NULL, &tw, &th );
		TTF_SizeText ( font, text.c_str(), &fw, NULL );

		SDL_Rect rect = { 500 / 2 - fw / 2, 282 / 4, tw, th };

		SDL_RenderCopy ( renderer, text_texture, NULL, &rect );

		SDL_DestroyTexture(text_texture);
	}
}

void Window::RenderLines(const std::string line)
{
	std::vector<std::string> lines = BreakTextIntoLines ( line );

	int height = 282 / 2;

	for ( auto line : lines )
	{
		SDL_Surface* text_surface = TTF_RenderText_Solid ( font, line.c_str(), SDL_Color { 0, 255, 50, 255 } );

		if ( !text_surface ) 
		{
			std::cout << "Failed to create surface" << std::endl;
		}
		else
		{
			SDL_Texture* text_texture = SDL_CreateTextureFromSurface( renderer, text_surface );
			SDL_FreeSurface(text_surface);

			int tw, th, fw, fh;
			SDL_QueryTexture ( text_texture, NULL, NULL, &tw, &th );
			TTF_SizeText ( font, line.c_str(), &fw, &fh );

			SDL_Rect rect = { 500 / 2 - fw / 2, height, tw, th };

			SDL_RenderCopy ( renderer, text_texture, NULL, &rect );

			SDL_DestroyTexture ( text_texture );

			height += fh;
		}
	}
}

std::vector<std::string> Window::BreakTextIntoLines(const std::string text) 
{
	int current_index = 0;
	std::vector<std::string> lines;

	while ( current_index >= 0 ) 
	{
		int marker_index = text.find_first_of( "\n", current_index + 1 );
		
		std::string line = text.substr( ( current_index == 0 ) ? current_index : current_index + 1, marker_index - current_index );

		line.erase ( std::remove ( line.begin(), line.end(), '\n' ), line.end ( ) );

		lines.push_back ( line );

		current_index = marker_index;
	}

	return lines;
}
