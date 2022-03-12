#ifndef STATE_H
#define STATE_H
#include <engine/room.h>

class State
{
private:
	&Room curr_room;
	
public:
	State State(); //default room constructor 

	&Room current_room() { return curr_room; }
	
	&Room update_room(&Room newroom)
	{
		this->curr_room = newroom;
		
		//anytime a room is updated, it print_room should be called, if never else
		this->curr_room->print_room();
		return curr_room;
	}
	
};

#endif