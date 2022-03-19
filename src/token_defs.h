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
	Nothing,
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
	LAST
};

enum class TkType
{
	Null = 0,
	Special,
	Verb,
	Concept,
	Item,
	Person,
	Scenery,
	LAST
};