#include room.h

class RoomNull : Room 
{ 
public: 
	RoomNull::RoomNull()
	: Room("Null") //does this work??

	void print_room(State s)
	{
		cout << "Uh-oh! You're in the null room. Classic mistake.";
		s.game_loop = false;
	}

}; //is that ok?


class RoomLetheCave : Room 
{ 
public: 
	RoomLetheCave::RoomLetheCave()
	: Room("Lethe Cave") //does this work??

	void print_room(State s)
	{
		if room_state == 0:
		{
			cout << "game intro";
			//do whatever initialization
			room_state++;
		}
		else:
		{
			cout << "game continues";
			room_state++;
		}
		self.print_dirs();
	}
	
	char go_N(State s) 
	{
	        catch_wrong_room(s);
	        if can_N(s)
	        {
	                cout << "You jump into the water, swimming with the current."
	                s.current_room = r_north; return 1;
	        }
	        else:
	        {
	                cout << "The river flows north, but you do not think you can safely swim it"; return 0;
	        }
	}
	char go_S(State s) 
	{
	        catch_wrong_room(s);
	        if can_N(s)
	        {
	                cout << "You jump into the water, swimming against the current."
	                s.current_room = r_north; return 1;
	        }
	        else:
	        {
	                cout << "The river flows from the south. You do not think you can safely swim it." return 0;
	        }
	}
	char go_W(State s) 
	{
	        catch_wrong_room(s);
	        cout << "You cannot go that way. There is only a rushing river, and beyond that a rocky cave wall." return 0;
	}
	
	char can_N(State s) { return s.can_swim; }
	char can_S(State s) { return s.can_swim; }
	
	int parser_catch(State s, vector v_in<string>)
	{
		return 0;
	}

}; //is that ok?
