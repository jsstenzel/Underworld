#include <src/game_state.h>
#include <src/game_parser.h>
#include <utils.h>


int main() 
{ 
	//setup & stuff with loading the save file 
	GameState state;
	GameParser parser;

	state.current_room->print_room();
	while(state.game_loop) 
	{ 
		parser(state); 
	} 
 

//save the file, close the game, etc 
}
