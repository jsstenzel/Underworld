#ifndef STATE_H
#define STATE_H

#include <map>
#include <string>

class Room;

class State
{
private:
	Room* curr_room;
	
public:
	State() //default room constructor 
	{}
	
	bool game_loop = true;
	
	std::map<std::string, int> data;

	Room* current_room() { return curr_room; }
	
	Room* update_room(Room* newroom);
};

#endif