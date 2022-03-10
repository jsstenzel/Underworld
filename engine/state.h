#ifndef STATE_H
#define STATE_H
#include <engine/room.h>

class State
{
private:
	Room& current_room;
	
public:
	Room& current_room() { return current_room; }
	
	Room& update_room(Room& newroom)
	{
		this->current_room = newroom;
		
		//anytime a room is updated, it print_room should be called, if never else
		this->current_room->print_room();
		return current_room;
	}
	
};

#endif