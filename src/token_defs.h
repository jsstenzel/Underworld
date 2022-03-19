#ifndef TOKEN_DEFS_H
#define TOKEN_DEFS_H

//implement specific tokens
#include <engine/token.h>


enum class Tk
{
	Null = 0, //an empty token, semantically empty
	TYPESPECIAL,
	Stats,
	Save,
	Load,
	Quit,
	TYPEVERB,
	Go,
	Look,
	Take,
	Speak,
	Attack,
	TYPECONCEPT,
	Nothing, //the concept of nothing, semantically non-empty
	North,
	East,
	South,
	West,
	TYPEITEM,
	Torch,
	Key,
	TYPEPERSON,
	Self,
	Crowd,
	Hecate,
	Erinye,
	Charon,
	TYPESCENERY,
	Room,
	Lethe,
	Wall,
	Floor,
	Ceiling,
	ANY //wildcard token
};

enum class TkType
{
	Null = 0, //i.e. not a type
	Special,
	Verb,
	Concept,
	Item,
	Person,
	Scenery,
	ANY       //i.e. any type
};

bool check(vec<Tk> in, Tk word1, Tk word2 = Tk::Null, Tk word3 = Tk::Null)
{
	//return true if in matches the args
	//also allow missing vector elements to equal Null
	//also handle Any. But Null does not match Any!
	int len = in.size();
	if (len == 0) return (word1 == Tk::Null);
	else if (len == 1)
	{
		if ((word1 == in[1] || word1 == Tk::ANY) && word2 == Tk::Null && word3 == Tk::Null) return true;
	}	
	else if (len == 2)
	{
		if ((word1 == in[1] || word1 == Tk::ANY) && (word2 == in[2] || word2 == Tk::ANY) && word3 == Tk::Null) return true;
	}	
	else if (len == 3)
	{
		if ((word1 == in[1] || word1 == Tk::ANY) && (word2 == in[2] || word2 == Tk::ANY) && (word3 == in[3] || word3 == Tk::ANY)) return true;
	}	
	else return false;
	return false;
}

#endif