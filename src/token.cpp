//implement specific tokens
#include <engine/token.h>
#include <src/token_defs.h>

#include <string>
#include <vector>
#include <sstream>

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

TkType token_type(Tk tok)
{
	int tnum = (int) tok;
	if (tnum <= 0) 
	{return TkType::Null;}
	else if (tnum > (int) Tk::TYPESCENERY)
	{return TkType::Special;}
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