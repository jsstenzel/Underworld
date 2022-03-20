#include <src/game_state.h>
#include <src/game_parser.h>
#include <engine/room.h>
#include <engine/utils.h>

//#include everything in room_defs
#include <src/rooms/entrance_defs.h>

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