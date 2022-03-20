#include <engine/room.h>
#include <src/game_parser.h>


bool GameParser::parse_common(State &s, std::vector<Tk> in)
{
	//SAVE
	
	//LOAD
	
	//QUIT
	
	//STATS (and inventory)
	
	//Examine (room)
	if (check(in, Tk::Look) || check(in, Tk::Look, Tk::Room))
	{ 
		s.current_room()->print_room(s); return true;
	}
	
	//N
	if (check(in, Tk::North) || check(in, Tk::Go, Tk::North))
	{ 
		s.current_room()->go_N(s); return true;
	}
	
	//E
	if (check(in, Tk::East) || check(in, Tk::Go, Tk::East))
	{ 
		s.current_room()->go_E(s); return true;
	}
	
	//S
	if (check(in, Tk::South) || check(in, Tk::Go, Tk::South))
	{ 
		s.current_room()->go_S(s); return true;
	}
	
	//W
	if (check(in, Tk::West) || check(in, Tk::Go, Tk::West))
	{ 
		s.current_room()->go_W(s); return true;
	}
	
	//default
	return false;
}

void GameParser::parse_default(State &s, std::vector<Tk> in)
{
	/////Handle default commands
	
	
	/////Handle unknown commands for the rest of the function
	if (check(in,Tk::Go,Tk::ANY)) { tprint("You don't know how to go there."); return; }
	if (check(in,Tk::Take,Tk::ANY)) { tprint("You don't know how to take that."); return; }
	if (check(in,Tk::Look,Tk::ANY)) { tprint("You don't see anything like that around here."); return; }
	
	if (check(in,Tk::Go)) { tprint("Go where? Maybe you should look around again."); return; }
	if (check(in,Tk::Take)) { tprint("Take what?"); return; }
}

void GameParser::cleanup(State &s)
{
	//Reduce menos by one if command wasn't a meta-command, like inventory or save or something

}