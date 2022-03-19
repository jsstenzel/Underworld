#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <engine/state.h>
//make a class that implements State, with stuff specific to Underworld


class GameState : public State
{
	//implement game-specific container for game-specific variables
	//Variables need to be named at compile time to be used in logic, yet also iterable?
	//Do I want a map for this? ["key"][val], nameable and iterable
};

//print_stats()

//print_map()

#endif