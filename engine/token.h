#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#define string std::string

//define the full enum in implementation
enum class Tk;

//define the part of speech or category 
enum class TkType;

//App-defined function to iterate over all tokens and map command string to token vector
//You should define TokenT as Tk, which is the inherited enum of all of your defined tokens
vector<Tk> tokenize_string(string input);

//find and return the type of a token
TkType token_type(Tk tok);

#endif