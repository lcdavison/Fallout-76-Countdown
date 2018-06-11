#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL.h>

#include <cstdlib>

class EventHandler 
{
	public:
		EventHandler();
		~EventHandler();

		void HandleEvents();
};

#endif
