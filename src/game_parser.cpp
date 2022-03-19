#include <engine/room.h>
#include <src/game_parser.h>


bool GameParser::parse_common(State &s, vec<Tk> in)
{
	//SAVE
	
	//LOAD
	
	//QUIT
	
	//STATS (and inventory)
	
	//Examine (room)
	if (in[0] == Tk::Look && (in[1] == Tk::Null || in[1] == Tk::Room))
	{ 
		s.current_room()->print_room(s); return true;
	}
	
	//N
	if (in[0] == Tk::North || (in[0] == Tk::Go && in[1] == Tk::North))
	{ 
		s.current_room()->go_N(s); return true;
	}
	
	//E
	if (in[0] == Tk::East || (in[0] == Tk::Go && in[1] == Tk::East))
	{ 
		s.current_room()->go_E(s); return true;
	}
	
	//S
	if (in[0] == Tk::South || (in[0] == Tk::Go && in[1] == Tk::South))
	{ 
		s.current_room()->go_S(s); return true;
	}
	
	//W
	if (in[0] == Tk::West || (in[0] == Tk::Go && in[1] == Tk::West))
	{ 
		s.current_room()->go_W(s); return true;
	}
}

void GameParser::parse_default(State &s, vec<Tk> in)
{
	/////Handle default commands
	
	
	/////Handle unknown commands for the rest of the function
	if (in[0] == Tk::Go) { tprint("You don't know how to go there."); return; }
	if (in[0] == Tk::Take) { tprint("You don't know how to take that."); return; }
	if (in[0] == Tk::Look) { tprint("You don't see anything like that around here."); return; }
}

void GameParser::cleanup(State &s)
{
	//Reduce menos by one if command wasn't a meta-command, like inventory or save or something

}