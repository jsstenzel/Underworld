#ifndef GAME_PARSER_H
#define GAME_PARSER_H

#include <engine/parser.h>
#include <engine/utils.h>
#include <engine/state.h>
#include <src/token_defs.h>

#include <string>
#include <vector>
#define str std::string
#define vec std::vector
//do all of this with virtual functions, implement with game_parser

class GameParser : public Parser
{
private:
	bool parse_common(State &s, vec<Tk> in);
	
	void parse_default(State &s, vec<Tk> in);
	
	void cleanup(State &s);

};

#endif