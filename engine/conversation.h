#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <engine/utils.h>
#include <str>

//TODO: I'm not sure if this architecture can support re-connecting of conversation branches. 
//If not, I need to also implement a conversation directed graph that can handle that.

//A conversation is a binary tree of [dialog and logic]
//logic can be simple, like True, or it can be state-dependent, like has_torch
//true makes you go right, false makes you go left
//logic can also be a binary decision made by the player; option1 is left, option2 is right

//A ConvoNode is one unit of a conversation tree
//Its constructor and child nodes will only be accessed by Conversation
struct ConvoNode {
private:
	//the speaker that is cprinted when this node is reached
	std::string speaker;
	//the line that is cprinted when this node is reached
	std::string line;
	//whether the tree proceeds left or right; expects a boolean or a ConvoChoice
	bool logic;
 
protected:
	struct ConvoNode* left;
	struct ConvoNode* right;
	
	//these are used by the Conversation executer if theyre nonempty
	std::string choice1 = "";
	std::string choice2 = "";

	//this constructor is used only by add_node
	ConvoNode(std::string set_speak, std::string set_line, bool set_logic)
	{
		speaker = set_speak, 
		line = set_line;
		logic = set_logic;
 
		// Left and right child for node
		// will be initialized to null
		left = NULL;
		right = NULL;
	}
	
	//This constructor is used only by add_choice
	ConvoNode(std::string set_speak, std::string set_line, std::string c1, std::string c2)
	{
		speaker = set_speak, 
		line = set_line;
		logic = false; //isn't actually used
		choice1 = c1;
		choice2 = c2;
 
		// Left and right child for node
		// will be initialized to null
		left = NULL;
		right = NULL;
	}
	
	std::string get_speak() { return speaker; }
	std::string get_line()  { return line; }
	std::string get_logic() { return logic; }
	std::string get_1()	    { return choice1; }
	std::string get_2()	    { return choice2; }
};

bool ConvoChoice(std::string choice1, std::string choice2)
{
	//convert both strs to all lowercase
	
	bool choosing = true;
	while(choosing)
	{
		//receive choice
		tprint("> ");
		std::string choice;
		std::cin >> choice;
		//convert to all lowercase
		
		if choice == choice1 return false; //go left
		else if choice == choice2 return true; // go right
		else tprint("(Choose '", choice1, "' or '", "'.")
	}
}

//Conversation implements a conversation tree
class Conversation : friend ConvoNode
{ 
private:
	struct ConvoNode* root = NULL;

public: 
	Conversation::Conversation()

	//Add a node to this conversation, with branching based on boolean
	//Returns the node you just added
	//Use that to add additional nodes
	ConvoNode* add_node(ConvoNode* parent, std::string speaker, std::string line, LeftorRight = "R", bool logic = true)
	{
		if root == NULL and parent == NULL
		{
			root = new ConvoNode(speaker, line, logic);
			return root;
		}
		else if root == NULL and parent != NULL
		{
			//fail; you shouldn't be giving weird inputs to this empty conversation
		}
		if root != NULL and parent == NULL
		{
			//fail; you need to give this Conversation node a good parent
		}
		else
		{
			if LeftorRight == "R"
			{
				if parent->right != NULL {} //fail big, you clobbered your own dialog
				parent->right = new ConvoNode(speaker, line, logic);
				return parent->right;
			}
			else if LeftorRight == "L"
			{
				if parent->left != NULL {} //fail big, you clobbered your own dialog
				parent->left = new ConvoNode(speaker, line, logic);
				return parent->left;
			}
			else //fail big! You coded it wrong, dummy
		}
	}
	
	//Add a node to this conversation, with branching based on binary choice
	//to actually add the two results of these choices, use the returned pointer
	ConvoNode* add_choice(ConvoNode& parent, std::string speaker, std::string line, std::string choice1, std::string choice2, LeftorRight = "R")
	{
		if root == NULL
		{
			root = new ConvoNode(speaker, line, choice1, choice2);
			return root;
		}
		else if root == NULL and parent != NULL
		{
			//fail; you shouldn't be giving weird inputs to this empty conversation
		}
		if root != NULL and parent == NULL
		{
			//fail; you need to give this Conversation node a good parent
		}
		else
		{
			if LeftorRight == "R"
			{
				if parent->right != NULL {} //fail big, you clobbered your own dialog
				parent->right = new ConvoNode(speaker, line, choice1, choice2);
				return parent->right;
			}
			else if LeftorRight == "L"
			{
				if parent->left != NULL {} //fail big, you clobbered your own dialog
				parent->left = new ConvoNode(speaker, line, choice1, choice2);
				return parent->left;
			}
			else //fail big! You coded it wrong, dummy
		}
	}
	
	void run_conversation()
	{
		//traverse tree
		ConvoNode* curr_node = root;
		while curr_node != NULL
		{
			cprint(curr_node.get_speak(), curr_node.get_line());
			
			//handle regular nodes
			if curr_node.get1() == "" and curr_node.get2() == ""
			{
				if curr_node.logic == true { curr_node = curr_node->right; }
				else { curr_node = curr_node->left; }
			}
			//handle choice nodes
			else
			{
				logic = ConvoChoice(curr_node.get1(), curr_node.get2());
				if logic == true { curr_node = curr_node->right; }
				else { curr_node = curr_node->left; }
			}
		}
	}

};


/*
Here's what an implementation in a Room's parser_catch() would look like

RoomOdysseusShip::parser_catch(std::vector<Token> ins)
{
	if ins[1] == tTalk and ins[2] == tOdysseus
	{
		Conversation c;
		c1 = c.add_node(NULL, "odysseus", "Hey girl, what's schwangin");
		c2 = c.add_node(c1, "you", "Gross, dude. Don't you have an Odyssey you should be focusing on right now?");
		c3 = c.add_choice(c2, "odysseus", "How's about you and me party down? I'm what you might call a Trojan horse.", 
						  "yes", "no");
				
		c_yes1 = c.add_node(c3, "you", "Yeah why not. My self respect is lower than fucking Tartarus right now, what have I got to lose", "L", state.has_condom);
		c_yes2 = c.add_node(c_yes1, "you", "Good thing I have this condom.", "R")
		c_yes3 = c.add_node(c_yes1, "you", "Sure wish I had a condom. Oh well.", "L")
	
		c_no1 = c.add_choice(c3, "you", "No.", "R")
		c_no2 = c.add_choice(c_no1, "odysseus", "That means I have a big dick.")
		c_no3 = c.add_choice(c_no2, "you", "I know what it means! You're not even Trojan you're Greek!!!")	
	
		c.run_conversation();
	}
}
*/

#endif