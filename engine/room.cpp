//lets define all of the room instances here, make them available to the game loop, and include some 

//maybe put them all in a room container class that lets you do searches and stuff

#include <engine/room.h>
//#include everything in room_defs




void RoomContainer::initialize()
{
        RoomNull r_Null;

        RoomLetheCave r_LetheCave;
		RoomMnemosynePool r_MnemosynePool;
		RoomThreshold r_Threshold;
		RoomCharonDock r_CharonDock;
		RoomErinyePass r_ErinyePass;
		RoomAvernusCave r_AvernusCave;
		
		//etc.
		
		//once everything is in the container,
		//fail loud if two room names are the same
}


void RoomContainer::construct()
{
        //get("Lethe Cave")->set_adj(get("Lethe Shore"), get("Threshold"), get("Mnemosyne's Pool"), NULL, NULL);
        //get("Threshold")->set_adj(NULL, get("Charon's Dock"), get("Erinyes Pass"), get("Lethe Cave"), NULL);
        //etc
		//TODO change this. Make each room contain its own adjacent strings, 
		//and just loop through them all and set them up here w/ the get and set_adj functions
		
		for room in rooms //python lmao fix
		{
			try:
			{
				room->set_adj(
					this->find(room.init_north), 
					this->find(room.init_east), 
					this->find(room.init_south), 
					this->find(room.init_west), 
					this->find(room.init_other));
			}
			catch { cout << "You failed construct() for room " << room.get_name() << endl;}
		}
}

//return a room object based on its unique name
Room& RoomContainer::find(string name)
{
	if name == NULL {return NULL;}
	
	//look for and return room ref
        
	//default
	//cout << "Error during initialization; room " << name << " not defined.";
	return NULL;
}
