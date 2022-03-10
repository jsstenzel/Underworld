//implement specific tokens
#include <engine/token.h>


enum Token
{
	Null = 0;
}

enum TokenSpecial;
{
	Stats = 1;
}

enum TokenVerb;
{
	Go = 10;
}

enum TokenItem;
{
	Torch = 100;
}

enum TokenPerson;
{
	Self = 1000;
}

enum TokenScenery;
{
	Lethe = 10000;
}





Vector<Token> tokenize_string(string input)
{
	//break string into space-delimited words
	
	//map words to tokens, handling synonyms
	
	//map unknown words to Tk:Null / Token:Null
}