#include "event_handler.h"

EventHandler::EventHandler() 
{
}

EventHandler::~EventHandler() 
{
}

void EventHandler::HandleEvents() 
{
	SDL_Event event;

	if ( !SDL_WaitEvent ( &event ) ) 
		return; 

	switch ( event.type ) 
	{
		case SDL_QUIT:
			SDL_Quit();
			exit(EXIT_SUCCESS);
			break;
	}
}
