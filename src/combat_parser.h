#ifndef COMBAT_PARSER_H
#define COMBAT_PARSER_H

#import <engine/utils.h>
#import <engine/parser.h>
#import <engine/room.h>

#include <string>
#define std::string std::string

//A combat is a smaller game loop embedded in the larger one
//It uses its own parser, the CombatParser, with a restricted set of commands
//A combat goes back and forth, you and the enemy taking actions and updating the game state,
//until one of you dies or flees.

class CombatRoom : Room
{
public: 
	CombatRoom::CombatRoom()
	: Room("")
	
	//expose name setting
	void set_name(std::string newname) { this->name = newname; }

	void print_room(State s) 
	{ 
		//do nothing and do it quietly
		return;
	}	
	
	//Purposefully sparse parser_catch, so that most combat logic is in CombatParser
	virtual int parser_catch(State s, std::vector<Token> in)
	{ 
		if in[0] == tLook and (in[1] == tNull or in[1] == tRoom)
		{ 
			tprint("You are in ", name, ", but there is not time to look around! You are in combat!");
			return true;
		}
		return false;
	} 
	
	//base go_X is fine
	//base can_X is fine
};


//implement pretty much like game loop: 
//run "fight.init_combat(); while(fight.combat_loop()) fight.parse(s)"
class CombatParser : Parser
{ 
private:
	bool combat_loop = true;
	
	//combat can only be ended by internal logic
	void end_combat() 
	{
		combat_loop = false;
		
		//set back the junk we messed with
		s.update_room(prev_room);
	}
	
	CombatRoom r_Combat;
	
	Room& prev_room;

public: 
	CombatParser::CombatParser()

	bool combat_loop() {return combat_loop;)
	
	void init_combat(State s)
	{
		//We don't want room commands to be accessible from the combat loop
		//Therefore, we will move to r_Combat for the duration of the loop
		prev_room = s.current_room();
		r_Combat.set_name(s.current_room()->get_name);
		s.update_room(r_Combat);
	}
	
	bool parse_common(State s, std::vector<Token> in)
	{		
		//SAVE
		
		//LOAD
		
		//QUIT
		
		//STATS (and inventory)
		
		//No time to Look or Go
	}
	
	//use this in derived classes to define combat-specific logic
	virtual void parse_default(State s, std::vector<Token> in);
	
	//use this however you want; to implement the enemy's turn, maybe
	virtual void cleanup(State s);
};
