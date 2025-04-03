
#include "SDL3/SDL.h"
#include <vector>
#include <iostream>

bool pollEvents(std::vector<SDL_Event>&);

SDL_Window* sdl_window;
int main()
{

	sdl_window = SDL_CreateWindow("TITLE", 800, 600, 0);




	while(true)
	{

		std::vector<SDL_Event> sdl_events;
		pollEvents(sdl_events);






	}




	return 0;
}


bool pollEvents(std::vector<SDL_Event>& sdl_events)
{

    /* PUMP EVENTS READS THE OS EVENTS AND PLACES IT INTO SDL's EVENT QUEUE*/
    SDL_PumpEvents();

	static uint64_t counter = 0;

#define MAX_NUM_EVENTS (2056*2)
    
    
    /* THIS IS THE BUFFER YOU'RE WRITING INTO */
    sdl_events.resize(MAX_NUM_EVENTS);
    int64_t total_num_events_read = 0;



    for (auto num_events_returned = SDL_PeepEvents(&sdl_events[total_num_events_read], MAX_NUM_EVENTS, SDL_EventAction::SDL_GETEVENT, SDL_EVENT_FIRST, SDL_EVENT_LAST); num_events_returned != 0;)
    {
        if (num_events_returned < 1)
        {
			std::cout << "SDL_PeepEvents returned negative value: ", SDL_GetError();
			return false;
		}

        total_num_events_read += num_events_returned;
        if (num_events_returned < MAX_NUM_EVENTS) break; // IF THIS IS TRUE THEN WE'VE PROCESSED ALL THE EVENTS POLLED



        

        

        sdl_events.resize(sdl_events.size() + MAX_NUM_EVENTS);
    }

    sdl_events.resize(total_num_events_read);




    for (uint32_t i = 0, size = sdl_events.size(); i < size; ++i)
    {


        SDL_Event& SDLEvent = sdl_events[i];

        switch (SDLEvent.type)
        {
        

        case SDL_EVENT_MOUSE_MOTION:
        {
			std::cout << "Mouse motion received. Counter = " << counter++ << "\n";
            break;
        }
        
        case SDL_EVENT_MOUSE_BUTTON_UP:
		{
            static bool relative_mode = false;
			relative_mode = !relative_mode;
			auto result = SDL_SetWindowRelativeMouseMode(sdl_window, relative_mode);

			if (!result) 
				std::cout << "Failed to set relative mode to " << relative_mode << "\n";
			else
				std::cout << "Successfully set relative mode to " << relative_mode << "\n";


            break;
		}
        default:
            
            break;

        }

    }


    return false;
}