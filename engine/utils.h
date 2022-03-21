#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <sstream>

//formatted terminal printing of one string
void tprint_1(std::string out);

//nice conversation-formatted terminal printing of one string
void cprint_1(std::string name, std::string out);

//the addToStream function helps us take arbitrary lengths of string input and concatenate them behind the scenes
void addToStream(std::stringstream&);

template<typename T, typename... Args>
void addToStream(std::stringstream& a_stream, T&& a_value, Args&&... a_args);

//formatted terminal printing of any number of strings
template<typename... Args>
void tprint(Args&&... a_args);

//nice conversation-formatted terminal printing of one string
template<typename... Args>
void cprint(std::string name, Args&&... a_args);


#endif