#ifndef ROOM_H
#define ROOM_H

#include <engine/state.h>
#include <engine/token.h>
#include <string>
#include <vector>
using namespace std::string

class Room 
{ 
private: 
    string name;

	int room_state = 0; //the "current" state of the room, used in internal logic
	void print_dirs(State& s)
	{
		tprint("You can go",
		" N"    : can_N(s)                                         ? "",
		",",    : can_N(s) && (can_E(s) || can_S(s) || can_W(s))   ? "",
		" or",  : can_N(s) && (!can_W(s) && !can_S(s) && can_E(s)) ? "",
		" E"    : can_E(s)                                         ? "",
		",",    : can_E(s) && (can_S(s), can_W(s))                 ? "",
		" or "  : can_E(s) && (!can_W(s) && can_S(s))              ? "",
		" S"    : can_S(s)                                         ? "",
		", or " : can_S(s) && can_W(s)                             ? "",
		" W"    : can_W(s)                                         ? "",
		" neither N, E, S, or W" : !can_N(s) && !can_W(s) && !can_S(s) && !can_E(s) ? "",
		".")
	}
	
	string default_no  = "You cannot go that way."
	void catch_wrong_room(State &s)
	{
	        if s.current_room != *this
	        {
	               tprint("Wrong function called to room  ", name);
	                s.game_loop = false;
	        }
	}
	
	//used by the go_X functions
	Room& r_north = NULL;
	Room& r_east = NULL;
	Room& r_south = NULL;
	Room& r_west = NULL;
	Room& r_other = NULL;
	
	//used by RoomContainer for construct()
	const string init_north = NULL; //this doesnt do what i want it to do
	const string init_east = NULL;
	const string init_south = NULL;
	const string init_west = NULL;
	const string init_other = NULL;

public: 
	Room Room(); //default room constructor 

	Room::Room(n)
	: name(n)
	{}
	
	string get_name() { return name; }
	
	//Sets the new current room; 0 indicates you can't go that way
	//These functions should only be called by the parser
	//will want to overload these for most rooms, if something interesting happens in the room transition.
	virtual char go_N(State &s) 
	{ 
	        catch_wrong_room(s); 
	        if can_N { s.update_room(r_north); return 1; }
	        else { tprint(default_no); return 0; }
	}
	virtual char go_E(State &s) 
	{ 
	        catch_wrong_room(s); 
	        if can_E { s.update_room(r_east); return 1; }
	        else { tprint(default_no); return 0; }
	}
	virtual char go_S(State &s) 
	{ 
	        catch_wrong_room(s); 
	        if can_S { s.update_room(r_south); return 1; }
	        else { tprint(default_no); return 0; }
	}
	virtual char go_W(State &s) 
	{ 
	        catch_wrong_room(s); 
	        if can_W { s.update_room(r_west); return 1; }
	        else { tprint(default_no); return 0; }
	}
	
	//these can be called by anyone
	//may want to overload these for some rooms, to explain why you can't go that way, or if its conditional
	virtual char can_N(State &s) { return r_north != NULL; }
	virtual char can_E(State &s) { return r_east != NULL; }
	virtual char can_S(State &s) { return r_south != NULL; }
	virtual char can_W(State &s) { return r_west != NULL; }
	
	int get_room_state { return room_state; }

	virtual void print_room(State s) { tprint("Room undefined!"); s.game_loop = false; }
	
	//returns nonzero if it caught something
	//this should be called by the derived class's parser_catch
	virtual int parser_catch(State &s, vector<Token> in) { return 0; } 

	//set during RoomContainer::construct()
	void set_adj(Room &north, Room &east, Room &south, room &west, room &other)
	{
		this->r_north = north;
		this->r_east = east;
		this->r_south = south;
		this->r_west = west;
		this->r_other = other;
	}
}; 


class RoomContainer
{
private:
	vector<Room> rooms;
	
public:
	Room Room(); //default room constructor 
        
	//init all of the room derived classes and add to the vector
	//called during game initialization
	void initialize();
        
	//set all of the room connection references w/ set_adjacent(...)
	//called during game initialization
	void construct();
        
	//return a room ref based on its name
	Room& find(string search_name);
};

#endif