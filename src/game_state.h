#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <engine/state.h>

#include <map>
//make a class that implements State, with stuff specific to Underworld


class GameState : public State
{
public:
	GameState() :
	State()
	{}
	
	//implement game-specific container for game-specific variables
	//Variables need to be named at compile time to be used in logic, yet also iterable?
	//Do I want a map for this? ["key"][val], nameable and iterable
	
	/*std::map<std::string, int> data = 
	{
		//Room state data
		["stateLetheCave"][0],
		["stateThreshold"][0],
		//Inventory
		["hasTorch"][0],
		["hasKey"][0],
		["hasHarp"][0],
		["hasPoppy"][0],
		["hasSword"][0],
		["hasSpear"][0],
		//Status
		["menos"][100],
		["isCow"][0],
		//Story flags
		["hasMemory"][0]
	}*/
};

//print_stats()

//print_map()

#endif