#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#define str std::string

//formatted terminal printing of one string
void tprint_1(str out)
{
	////first, format the string so that the max width is 80 characters and words aren't split on a line
	
	//loop over text starting at character 0
	//if 80th char is not a whitespace,
		//then step back until whitespace is found
		//and change it to an \n
		//then step to the character following the \n
	//else
		//set 80th char to \n, step to following character
	//repeat until string end

	//now, print the formatted string.

	//lastly, print an std::endline
	std::cout << std::endl;
}

//nice conversation-formatted terminal printing of one string
void cprint_1(str name, str out)
{
	//convert name to all caps
	str NAME = name;
	
	std::cout << NAME << std::endl;
	
	////format text for a 72 character space, giving an 8 character indent
	
	//loop over text starting at character 0
	//add 8 characters of spaces before here
	//if 72nd char is not a whitespace,
		//then step back until whitespace is found
		//and change it to an \n
		//then step to the character following the \n
	//else
		//set 72nd char to \n, step to following character
	//repeat until string end

	//now, print the formatted string.

	//lastly, print two std::endlines to start the next line or continue other text.
	std::cout << std::endl << std::endl;
}

//the addToStream function helps us take arbitrary lengths of string input and concatenate them behind the scenes
void addToStream(std::ostringstream&)
{}

template<typename T, typename... Args>
void addToStream(std::ostringstream& a_stream, T&& a_value, Args&&... a_args)
{
    a_stream << std::forward<T>(a_value);
    addToStream(a_stream, std::forward<Args>(a_args)...);
}

//formatted terminal printing of any number of strings
template<typename... Args>
void tprint(Args&&... a_args)
{
    std::ostringstream s;
    addToStream(s, std::forward<Args>(a_args)...);
    tprint_1(s.str());
}

//nice conversation-formatted terminal printing of one string
template<typename... Args>
void cprint(str name, Args&&... a_args)
{
    std::ostringstream s;
    addToStream(s, std::forward<Args>(a_args)...);
    cprint_1(name, s.str());
}



#endif