//lets define all of the room instances here, make them available to the game loop, and include some 

//maybe put them all in a room container class that lets you do searches and stuff

#include room.h
#include room_defs.h




void RoomContainer::initialize()
{
        RoomNull r_Null;

        RoomLetheCave r_LetheCave;
}


void RoomContainer::construct()
{
        get("Lethe Cave")->set_adj(get("Lethe Shore"), get("Threshold"), get("Mnemosyne's Pool"), NULL, NULL);
        get("Threshold")->set_adj(NULL, get("Charon's Dock"), get("Erinyes Pass"), get("Lethe Cave"), NULL);
        //etc
		//TODO change this. Make each room contain its own adjacent strings, and just loop through them all and set them up here w/ the get and set_adj functions
}

Room& RoomContainer::get(string name)
{
        //look for and return room ref
        
        //default
        cout << "Error during initialization; room " << name << " not defined.";
}
