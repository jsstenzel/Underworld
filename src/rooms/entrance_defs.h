#include <engine/room.h>
#include <engine/utils.h>

#include <src/game_state.h>

#include <string>
#include <vector>

class RoomNull : Room 
{ 
public: 
	RoomNull() 
	: Room{"Null"}
	{}

	void print_room(State& s)
	{
		tprint("Uh-oh! You're in the null room. Classic mistake.");
		s.game_loop = false;
	}

}; //is that ok?


class RoomLetheCave : Room 
{ 
private:
	const std::string init_north = "Lethe Mouth";
	const std::string init_east = "Threshold";
	const std::string init_south = "Mnemosyne's Pool";

public: 
	RoomLetheCave() 
	: Room{"Lethe Cave"}
	{}

	void print_room(State s)
	{
		if (room_state == 0)
		{
			tprint("You come to awareness with a sudden moment of clarity, as if you awoke in an instant from a long uneasy sleep.");
			tprint("You look down. You have the body of a woman, wearing a bone-white chiton. You are kneeling by a river rushing swift in the darkness. Your hands and face are wet. You have no memories before this moment.");
			tprint("You don't know who you are or how you got here, but looking around, you are certain that this is the river Lethe, you are in the Underworld, and you are dead.");
			tprint("You stand up. You feel nothing, no pain or surprise. To the west of you is the river, which rushes from South to North along a cavern you cannot see far down. The large cave you are in continues to the East. What do you do?");
			room_state++;
		}
		else
		{
			tprint("You are in a dead-end cave. The river Lethe burbles past you from South to North along a dim channel, its water silvery and placid.");
		}
		this->print_dirs(s);
	}
	
	char go_N(State s) 
	{
		catch_wrong_room(s);
		if (can_N(s))
		{
			tprint("Sniffing the poppy deeply, you step down into the water, swimming with the current.");
			s.update_room(r_north); return 1;
		}
		else
		{
			tprint("The river flows north, but you do not think you can safely swim it"); return 0;
		}
	}
	char go_S(State s) 
	{
		catch_wrong_room(s);
		if (can_S(s))
		{
			tprint("Sniffing the poppy deeply, you step down into the water, swimming against the current.");
			s.update_room(r_south); return 1;
		}
		else
		{
			tprint("The river flows from the south. You do not think you can safely swim it."); return 0;
		}
	}
	char go_W(State s) 
	{
		catch_wrong_room(s);
		tprint("You cannot go that way. There is only a rushing river, and beyond that a rocky cave wall."); return 0;
	}
	
	char can_N(State s) { return s.can_swim; }
	char can_S(State s) { return s.can_swim; }
	
	int parser_catch(State s, std::vector<Tk> v_in)
	{
		return 0;
	}

};


class RoomThreshold : Room 
{ 
private:
	const std::string init_east = "Charon's Dock";
	const std::string init_south = "Erinye Pass";
	const std::string init_west = "Lethe Cave";

public: 
	RoomThreshold() 
	: Room{"Threshold"}
	{}

	void print_room(State s)
	{
		tprint("You are in a large, high-ceilinged cave that seems to lie at the intersection of three paths. There is a crowd of people milling around. Some are weeping, some are shouting and arguing, but many are sitting in the dirt or pacing around morosely.");
		this->print_dirs(s);
	}

	//	default go_X should be fine
	
	int parser_catch(State s, std::vector<Tk> v_in)
	{
		return 0;
	}

};

class RoomMnemosynePool : Room 
{ 
public: 
	RoomMnemosynePool() 
	: Room{"Mnemosyne's Pool"}
	{}

	void print_room(State& s)
	{
		tprint("Uh-oh! You're in the null room. Classic mistake.");
		s.game_loop = false;
	}

};

class RoomCharonDock : Room 
{ 
public: 
	RoomCharonDock() 
	: Room{"Charon's Dock"}
	{}

	void print_room(State& s)
	{
		tprint("Uh-oh! You're in the null room. Classic mistake.");
		s.game_loop = false;
	}

};

class RoomErinyePass : Room 
{ 
public: 
	RoomErinyePass() 
	: Room{"Erinye Pass"}
	{}

	void print_room(State& s)
	{
		tprint("Uh-oh! You're in the null room. Classic mistake.");
		s.game_loop = false;
	}

};

class RoomAvernusCave : Room 
{ 
public: 
	RoomAvernusCave() 
	: Room{"Avernus Cave"}
	{}

	void print_room(State& s)
	{
		tprint("Uh-oh! You're in the null room. Classic mistake.");
		s.game_loop = false;
	}

};