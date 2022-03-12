//implement specific tokens
#include <engine/token.h>

#include <string>
#define string std::string


enum class Tk
{
	Null = 0,
	TYPESPECIAL,
	Stats,
	Save,
	Load,
	Quit,
	TYPEVERB,
	Go,
	Look,
	Take,
	TYPECONCEPT,
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