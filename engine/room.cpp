//lets define all of the room instances here, make them available to the game loop, and include some 

//maybe put them all in a room container class that lets you do searches and stuff

#include <engine/room.h>
#include <engine/state.h>

//#include everything in room_defs

#include <string>
#include <vector>
#define str std::string
#define vec std::vector

void Room::print_dirs(State &s)
{
	tprint("You can go", //this can so be optimized! Think about it later
	/* N"    : (can_N(s))                                         ? ""),
	(",",    : (can_N(s) && (can_E(s) || can_S(s) || can_W(s)))   ? ""),
	(" or",  : (can_N(s) && (!can_W(s) && !can_S(s) && can_E(s))) ? ""),
	(" E"    : (can_E(s))                                         ? ""),
	(",",    : (can_E(s) && (can_S(s), can_W(s)))                 ? ""),
	(" or "  : (can_E(s) && (!can_W(s) && can_S(s)))              ? ""),
	(" S"    : (can_S(s))                                         ? ""),
	(", or " : (can_S(s) && can_W(s))                             ? ""),
	(" W"    : (can_W(s))                                         ? ""),
	(" neither N, E, S, or W" : (!can_N(s) && !can_W(s) && !can_S(s) && !can_E(s)) ? ""),*/
	".");
}
	
void Room::catch_wrong_room(State &s)
{
	if (s.current_room() != this)
	{
		tprint("Wrong function called to room  ", name);
		s.game_loop = false;
	}
}

char Room::go_N(State &s) 
{ 
	catch_wrong_room(s); 
	if (can_N(s)) { s.update_room(r_north); return 1; }
	else { tprint(default_no); return 0; }
}
char Room::go_E(State &s) 
{ 
	catch_wrong_room(s); 
	if (can_E(s)) { s.update_room(r_east); return 1; }
	else { tprint(default_no); return 0; }
}
char Room::go_S(State &s) 
{ 
	catch_wrong_room(s); 
	if (can_S(s)) { s.update_room(r_south); return 1; }
	else { tprint(default_no); return 0; }
}
char Room::go_W(State &s) 
{ 
	catch_wrong_room(s); 
	if (can_W(s)) { s.update_room(r_west); return 1; }
	else { tprint(default_no); return 0; }
}
	
char Room::can_N(State &s) { return r_north != NULL; }
char Room::can_E(State &s) { return r_east != NULL; }
char Room::can_S(State &s) { return r_south != NULL; }
char Room::can_W(State &s) { return r_west != NULL; }

int Room::parser_catch(State &s, vec<Tk> in) 
{ return 0; } 

void Room::print_room(State& s)
{ tprint("Room undefined!"); s.game_loop = false; }

void Room::set_adj(Room *north, Room *east, Room *south, Room *west, Room *other)
{
	this->r_north = north;
	this->r_east = east;
	this->r_south = south;
	this->r_west = west;
	this->r_other = other;
}




void RoomContainer::initialize()
{
        RoomNull r_Null;

        RoomLetheCave r_LetheCave;
		RoomMnemosynePool r_MnemosynePool;
		RoomThreshold r_Threshold;
		RoomCharonDock r_CharonDock;
		RoomErinyePass r_ErinyePass;
		RoomAvernusCave r_AvernusCave;
		
		//etc.
		
		//once everything is in the container,
		//fail loud if two room names are the same
}


void RoomContainer::set_all_adjacency()
{		
	for (auto & room : rooms)
	{
		try
		{
			room.set_adj(
				this->find(room.init_north), 
				this->find(room.init_east), 
				this->find(room.init_south), 
				this->find(room.init_west), 
				this->find(room.init_other));
		}
		catch { tprint("You failed set_all_adjacency() for room ",room.get_name());}
	}
}

//return a room object based on its unique name
Room* RoomContainer::find(str search_name)
{
	if (search_name == "") {return NULL;}
	
	//look for and return room ref
        
	//default
	//tprint("Error during initialization; room ",name," not defined.");
	return NULL;
}
