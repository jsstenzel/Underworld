int main() 
{ 
//setup & stuff with loading the save file 


	state.current_room->print_room();
	while(state.game_loop) 
	{ 
		parser(state); 
	} 
 

//save the file, close the game, etc 
}
