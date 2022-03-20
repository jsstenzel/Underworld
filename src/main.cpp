#include <src/game_state.h>
#include <src/game_parser.h>
#include <engine/room.h>
#include <engine/utils.h>


int main() 
{ 
	//initial initializations
	GameState state;
	GameParser parser;
	RoomContainer allRooms;
	allRooms.initialize();
	allRooms.set_all_adjacency();

	//setup & stuff with loading the save file 

	//game loop
	state.current_room()->print_room(state);
	while(state.game_loop) 
	{ 
		parser.parse(state); 
	} 
 

	//save the file, close the game, etc 
}
