#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>
#define str std::string
#define vec std::vector

//define the full enum in implementation
enum class Tk;

//define the part of speech or category 
enum class TkType;

//App-defined function to iterate over all tokens and map command string to token vector
//You should define TokenT as Tk, which is the inherited enum of all of your defined tokens
vec<Tk> tokenize_string(str input);

//find and return the type of a token
TkType token_type(Tk tok);

#endif