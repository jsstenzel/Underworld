#ifndef GAME_PARSER_H
#define GAME_PARSER_H

#include <engine/parser.h>
#include <engine/token.h>
//do all of this with virtual functions, implement with game_parser

class GameParser : Parser
{
private:
	bool parse_common(State s, vector<Token> in)
	{
		//SAVE
		
		//LOAD
		
		//QUIT
		
		//STATS (and inventory)
		
		//Examine (room)
		if in[0] == tLook and (in[1] == tNull or in[1] == tRoom)
		{ 
			s.current_room()->print_room(); return true;
		}
		
		//N
		if in[0] == tNorth or (in[0] == tGo and in[1] == tNorth)
		{ 
			s.current_room()->go_N(); return true;
		}
		
		//E
		if in[0] == tEast or (in[0] == tGo and in[1] == tEast)
		{ 
			s.current_room()->go_E(); return true;
		}
		
		//S
		if in[0] == tSouth or (in[0] == tGo and in[1] == tSouth)
		{ 
			s.current_room()->go_S(); return true;
		}
		
		//W
		if in[0] == tWest or (in[0] == tGo and in[1] == tWest)
		{ 
			s.current_room()->go_W(); return true;
		}
	}
	
	void parse_default(State s, vector<Token> in)
	{
		/////Handle default commands
		
		
		/////Handle unknown commands for the rest of the function
		if in[0] == tGo { tprint("You don't know how to go there."); return; }
		if in[0] == tTake { tprint("You don't know how to take that."); return; }
		if in[0] == tLook { tprint("You don't see anything like that around here."); return; }
	}
	
	void cleanup(State s)
	{
		//Reduce menos by one if command wasn't a meta-command, like inventory or save or something

	}

};

#endif