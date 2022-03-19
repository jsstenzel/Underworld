#ifndef ROOM_H
#define ROOM_H

#include <engine/token.h>
#include <engine/utils.h>

#include <string>
#include <vector>
#define str std::string
#define vec std::vector

class State;

class Room 
{ 
private: 
    str name;

	int room_state = 0; //the "current" state of the room, used in internal logic
	
	void print_dirs(State &s);
	
	str default_no = "You cannot go that way.";
	
	void catch_wrong_room(State &s);
	
	//used by the go_X functions
	Room* r_north = NULL;
	Room* r_east = NULL;
	Room* r_south = NULL;
	Room* r_west = NULL;
	Room* r_other = NULL;

public: 
	Room(); //default room constructor 

	Room(str n) //construct with name
	: name(n)
	{}
	
	str get_name() { return name; }
	
	//used by RoomContainer for construct()
	const str init_north = "";
	const str init_east = "";
	const str init_south = "";
	const str init_west = "";
	const str init_other = "";
	
	//Sets the new current room; 0 indicates you can't go that way
	//These functions should only be called by the parser
	//will want to overload these for most rooms, if something interesting happens in the room transition.
	virtual char go_N(State &s);
	virtual char go_E(State &s);
	virtual char go_S(State &s);
	virtual char go_W(State &s);
	
	//these can be called by anyone
	//may want to overload these for some rooms, to explain why you can't go that way, or if its conditional
	virtual char can_N(State &s);
	virtual char can_E(State &s);
	virtual char can_S(State &s);
	virtual char can_W(State &s);
	
	int get_room_state() { return room_state; }

	virtual void print_room(State& s);
	
	//returns nonzero if it caught something
	//this should be called by the derived class's parser_catch
	virtual int parser_catch(State &s, vec<Tk> in);

	//set during RoomContainer::set_all_adjacency()
	void set_adj(Room *north, Room *east, Room *south, Room *west, Room *other);
}; 


class RoomContainer
{
private:
	vec<Room> rooms;
	
public:
	RoomContainer(); //default room constructor 
        
	//init all of the room derived classes and add to the vector
	//called during game initialization
	void initialize();
        
	//set all of the room connection references w/ set_adjacent(...)
	//called during game initialization
	void set_all_adjacency();
        
	//return a room ref based on its name
	Room* find(str search_name);
};

#endif