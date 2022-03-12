#ifndef PARSER_H
#define PARSER_H

#include <engine/token.h>
#include <engine/state.h>

#include <string>
#include <vector>
#define str std::string
#define vec std::vector
//do all of this with virtual functions, implement with game_parser

class Parser
{
private:
	bool parse_found = false;
	
	//run before room parser; commands common to all rooms
	virtual bool parse_common(State &s, vec<Tk> in);
	
	//run after room parser; commands default to all rooms
	virtual void parse_default(State &s, vec<Tk> in);
	
	//commands to run at the end of each game loop
	virtual void cleanup(State &s);
	
public:
	Parser();

	void parse(State &s)
	{ 
		//get input from user
		tprint("> ");
		std::cin >> input;

		//convert to tokens
		vec<Tk> in = tokenize_input(input);

		//switch over common commands
		parse_result = self->parse_common(s, in);

		//let the room parser catch first
		if !parse_result { parse_result = s.current_room.parser_catch(); }

		//switch over default commands true in any room
		//include handling for unknown commands
		if !parse_result { self->parse_default(s, in); }

		self->cleanup(s);
	}

}; 


#endif