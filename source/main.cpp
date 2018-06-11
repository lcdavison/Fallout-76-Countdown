#include <SDL.h>

#include "window.h"
#include "event_handler.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

const float DELTA_TIME = 1000 / 1;

Window window;

bool running = false;
std::time_t release_time;
std::string text = "NULL";

void Render() 
{
	SDL_Color text_color = { 0, 255, 50, 255 };

	window.Clear();	
	window.RenderBackground();
	window.RenderText("FALLOUT 76 COUNTDOWN!", text_color);
	window.RenderLines(text);
	window.Render();
}

void Update() 
{
	double total_seconds = std::difftime(release_time, std::time(nullptr));

	float months = total_seconds / (3600 * 24 * 7 * 4);
	total_seconds = std::fmod(total_seconds, 3600 * 24 * 7 * 4);
	float days = total_seconds / (3600 * 24);
	total_seconds = std::fmod(total_seconds, 3600 * 24);
	float hours = total_seconds / 3600;
	total_seconds = std::fmod(total_seconds, 3600);
	float minutes = total_seconds / 60;

	text = "MONTHS : " + std::to_string(static_cast<int>(std::floor(months))) + "\n" + "DAYS : " + std::to_string(static_cast<int>(std::floor(days))) + "\n" + "HOURS : " + std::to_string(static_cast<int>(std::ceil(hours))) + "\n" + "MINUTES : " + std::to_string(static_cast<int>(std::ceil(minutes)));

	printf("MONTHS : %2.f DAYS : %2.f HOURS : %2.f MINUTES : %2.f\n", std::floor(months), std::floor(days), hours, minutes);
}

int main(int argc, char* argv[]) 
{
	running = true;

	EventHandler event_handler;

	tm* release_date = new tm;

	release_date->tm_sec = 0;
	release_date->tm_min = 0;
	release_date->tm_hour = 12;
	release_date->tm_mday = 14;
	release_date->tm_mon = 10;
	release_date->tm_year = 118;

	release_time = std::mktime(release_date);

	delete release_date;

	std::time_t last_time = std::time ( nullptr );
	float accumulator = 0;

	while (running) 
	{
		event_handler.HandleEvents ( ); 

		std::time_t current_time = std::time ( nullptr );
		double frame_time = std::difftime ( current_time, last_time );

		accumulator += frame_time * 1000;

		last_time = current_time;

		while ( accumulator >= DELTA_TIME ) 
		{
			Update();

			accumulator -= DELTA_TIME;

			Render();
		}
	}

	return 0;
}
