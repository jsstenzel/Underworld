//implement specific tokens
#include <src/token_defs.h>

#include <string>
#define string std::string


void main()
{
	vector<Tk> in = tokenize_string("go north");
}


vector<Tk> tokenize_string(string input)
{
	//break string into space-delimited words
	
	//map words to tokens, handling synonyms
	
	//map unknown words to Tk:Null / Token:Null
}

TkType token_type(Tk tok);
{
	tnum = (int) tok;
	if tnum <= 0 
		return TkType::Null;
	else if tnum > (int) Tk::TYPESCENERY
		return TkType::Special;
	else if tnum > (int) Tk::TYPEPERSON
		return TkType::Person;
	else if tnum > (int) Tk::TYPEITEM
		return TkType::Item;
	else if tnum > (int) Tk::TYPECONCEPT
		return TkType::Concept;
	else if tnum > (int) Tk::TYPEVERB
		return TkType::Verb;
	else if tnum > (int) Tk::TYPESPECIAL
		return TkType::Special;
	else
		//something weird??
		return TkType::Null;
}