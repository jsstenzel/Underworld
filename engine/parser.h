#ifndef PARSER_H
#define PARSER_H

#include <engine/token.h>
#include <engine/state.h>
#include <engine/utils.h>

#include <iostream>
#include <string>
#include <vector>
//do all of this with virtual functions, implement with game_parser

class Parser
{
private:
	bool parse_found = false;
	
	//run before room parser; commands common to all rooms
	virtual bool parse_common(State &s, std::vector<Tk> in) = 0;
	
	//run after room parser; commands default to all rooms
	virtual void parse_default(State &s, std::vector<Tk> in) = 0;
	
	//commands to run at the end of each game loop
	virtual void cleanup(State &s) = 0;
	
public:
	Parser()
	{}

	void parse(State &s);
}; 


#endif