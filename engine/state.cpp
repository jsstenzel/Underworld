#include <engine/room.h>
#include <engine/state.h>

Room* State::update_room(Room* newroom)
{
	this->curr_room = newroom; //figure out why this doesnt work - i need to make it a pointer, right?
	
	//anytime a room is updated, it print_room should be called, if never else
	this->curr_room->print_room(*this);
	return curr_room;
}