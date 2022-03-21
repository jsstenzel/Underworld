//implement specific tokens
#include <engine/token.h>
#include <src/token_defs.h>

#include <string>
#include <vector>
#include <sstream>

bool check(std::vector<Tk> in, Tk word1, Tk word2=Tk::Null, Tk word3=Tk::Null)
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

std::vector<Tk> tokenize_string(std::string input)
{
	//break string into space-delimited words
	std::stringstream ss;
	
	//map words to tokens, handling synonyms
	std::vector<Tk> in;
	
	//map unknown words to Tk::Null
	//and fill the end with a couple Tk::Null's 
	
	
	return in;
}

TkType get_token_type(Tk tok)
{
	int tnum = (int) tok;
	if (tnum <= 0) 
	{return TkType::Null;}
	else if (tnum > (int) Tk::TYPESCENERY)
	{return TkType::Scenery;}
	else if (tnum > (int) Tk::TYPEPERSON)
	{return TkType::Person;}
	else if (tnum > (int) Tk::TYPEITEM)
	{return TkType::Item;}
	else if (tnum > (int) Tk::TYPECONCEPT)
	{return TkType::Concept;}
	else if (tnum > (int) Tk::TYPEVERB)
	{return TkType::Verb;}
	else if (tnum > (int) Tk::TYPESPECIAL)
	{return TkType::Special;}
	else
	{//something weird??
	return TkType::Null;}
}