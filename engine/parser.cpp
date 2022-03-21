#include <engine/parser.h>
#include <engine/room.h>

void Parser::parse(State &s)
{ 
//get input from user
	tprint("> ");
	std::string input;
	std::cin >> input;

	//convert to tokens
	std::vector<Tk> in = tokenize_string(input);

	//switch over common commands
	bool parse_result = parse_common(s, in);

	//let the room parser catch first
	if (!parse_result) { parse_result = s.current_room()->parser_catch(s, in); }

	//switch over default commands true in any room
	//include handling for unknown commands
	if (!parse_result) { parse_default(s, in); }

	cleanup(s);
}