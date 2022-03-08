#include state.h

class Room 
{ 
private: 
        string name;

	//Vector<string> description; 

	int room_state = 0; //the "current" state of the room, used in internal logic
	void print_dirs()
	{
	        if &r_north != NULL
		cout << "You can go ";
		//?N, ?or ?E, ?or ?S, ?or ?W.
	}
	
	string default_no  = "You cannot go that way."
	catch_wrong_room(State s)
	{
	        if s.current_room != *this
	        {
	                cout << "Wrong function called to room  " << name;
	                s.game_loop = false;
	        }
	}
	
	Room &r_north = NULL;
	Room &r_east = NULL;
	Room &r_south = NULL;
	Room &r_west = NULL;
	Room &r_other = NULL;

public: 
	Room Room(); //default room constructor 

	Room::Room(n)
	: name(n)
	{}
	
	//Sets the new current room; 0 indicates you can't go that way
	//These functions should only be called by the parser
	//will want to overload these for most rooms, if something interesting happens in the room transition.
	virtual char go_N(State s) 
	{ 
	        catch_wrong_room(s); 
	        if can_N { s.current_room = r_north; return 1; }
	        else { cout << default_no; return 0; }
	}
	virtual char go_E(State s) 
	{ 
	        catch_wrong_room(s); 
	        if can_E { s.current_room = r_east; return 1; }
	        else { cout << default_no; return 0; }
	}
	virtual char go_S(State s) 
	{ 
	        catch_wrong_room(s); 
	        if can_S { s.current_room = r_south; return 1; }
	        else { cout << default_no; return 0; }
	}
	virtual char go_W(State s) 
	{ 
	        catch_wrong_room(s); 
	        if can_W { s.current_room = r_west; return 1; }
	        else { cout << default_no; return 0; }
	}
	
	//these can be called by anyone
	//may want to overload these for some rooms, to explain why you can't go that way, or if its conditional
	virtual char can_N(State s) { return r_north != NULL; }
	virtual char can_E(State s) { return r_east != NULL; }
	virtual char can_S(State s) { return r_south != NULL; }
	virtual char can_W(State s) { return r_west != NULL; }
	
	int get_room_state { return room_state; }

	virtual void print_room(State s) { cout << "Room undefined!"; s.game_loop = false; }
	
	//returns nonzero if it caught something
	//this should be called by the derived class's parser_catch
	virtual int parser_catch(State s) { return 0; } 

        //set during 
        void set_adj(Room &north, Room &east, Room &south, room &west, room &other)
        {
                r_north = north;
                r_east = east;
                r_south = south;
                r_west = west;
                r_other = other;
        }
}; 


class RoomContainer
{
        vector<Room> rooms;
        
        //init all of the room derived classes and add to the vector
        //called during game initialization
        void initialize();
        
        //set all of the room connection references w/ set_adjacent(...)
        //called during game initialization
        void construct();
        
        //return a room ref based on its name
        Room& get(string name);
};
