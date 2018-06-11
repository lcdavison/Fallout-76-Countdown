#include "event_handler.h"
#include <iostream>

EventHandler::EventHandler() 
{
}

EventHandler::~EventHandler() 
{
}

void EventHandler::HandleEvents() 
{
	SDL_Event event;

	SDL_WaitEventTimeout ( &event, 500 );

	if ( event.type != SDL_QUIT )
		return;

	SDL_Quit();
	exit(EXIT_SUCCESS);

}
