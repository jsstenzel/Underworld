int main() 
{ 
//setup & stuff with loading the save file 

 
	while(State.game_loop) 
	{ 
		State.current_room.print_room(); 
		parser(State); 
	} 
 

//save the file, close the game, etc 
}
