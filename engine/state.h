#ifndef STATE_H
#define STATE_H

class Room;

class State
{
private:
	Room* curr_room;

	
public:
	State(); //default room constructor 
	
	bool game_loop = true;

	Room* current_room() { return curr_room; }
	
	Room* update_room(Room* newroom);
};

#endif