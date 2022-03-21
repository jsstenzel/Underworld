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
	ANY, //wildcard token
	ALL  //ANY including Null
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

bool check(std::vector<Tk> in, Tk word1, Tk word2=Tk::Null, Tk word3=Tk::Null);

#endif