#include <engine/utils.h>

//formatted terminal printing of one string
void tprint_1(std::string out)
{
	int width = 80;
	////first, format the string so that the max width is 80 characters and words aren't split on a line
	
	//loop over text starting at character 0
	//terminate loop if there are 80 or fewer characters remaining
	for (int c=0; c < out.size() - width; )
	{		
		if (out[c+width] == ' ')
		{
			//set 81st char to \n, step to following character. Prevents line from starting with space
			out[c+width] = '\n';
			c+=width;
		}
		else if (out[c+width-1] == ' ')
		{
			//set 80th char to \n, step to following character. Handles lines that end with space
			out[c+width-1] = '\n';
			c+=width;
		}
		else
		{
			//step back until whitespace is found, and introduce a line break
			int break_idx = 0;
			for (int cc=c+width-1; cc > 0; cc--)
			{
				if (out[cc] == ' ')
				{
					out[cc] = '\n';
					break_idx = cc;
					break;					
				}
			}
			c+=break_idx;
		}		
	} //repeat until string end

	//now, print the formatted string.
	std::cout << out;

	//lastly, print an std::endline
	std::cout << std::endl;
}

//nice conversation-formatted terminal printing of one string
void cprint_1(std::string name, std::string out)
{
	//convert name to all caps and print
	std::string NAME;
	for (char& x : name) NAME = toupper(x);
	std::cout << NAME << std::endl;
	
	////format text for a 72 character space, giving an 8 character indent
	
	int width = 72;
	////first, format the string so that the max width is 80 characters and words aren't split on a line
	
	//loop over text starting at character 0
	//terminate loop if there are 80 or fewer characters remaining
	for (int c=0; c < out.size() - width; )
	{		
		if (out[c+width] == ' ')
		{
			//set 81st char to \n, step to following character. Prevents line from starting with space
			out[c+width] = '\n';
			c+=width;
		}
		else if (out[c+width-1] == ' ')
		{
			//set 80th char to \n, step to following character. Handles lines that end with space
			out[c+width-1] = '\n';
			c+=width;
		}
		else
		{
			//step back until whitespace is found, and introduce a line break
			int break_idx = 0;
			for (int cc=c+width-1; cc > 0; cc--)
			{
				if (out[cc] == ' ')
				{
					out[cc] = '\n';
					break_idx = cc;
					break;					
				}
			}
			c+=break_idx;
		}		
		
		//add in 8 whitespaces at the start and after every '\n'
		out.insert(c,"        ");
		
	} //repeat until string end

	//now, print the formatted string.
	std::cout << out;

	//lastly, print two std::endlines to start the next line or continue other text.
	std::cout << std::endl << std::endl;
}

//the addToStream function helps us take arbitrary lengths of string input and concatenate them behind the scenes
void addToStream(std::stringstream&)
{}

template<typename T, typename... Args>
void addToStream(std::stringstream& a_stream, T&& a_value, Args&&... a_args)
{
    a_stream << std::forward<T>(a_value);
    addToStream(a_stream, std::forward<Args>(a_args)...);
}

//formatted terminal printing of any number of strings
template<typename... Args>
void tprint(Args&&... a_args)
{
    std::stringstream s;
    addToStream(s, std::forward<Args>(a_args)...);
    tprint_1(s.str());
}

//nice conversation-formatted terminal printing of one string
template<typename... Args>
void cprint(std::string name, Args&&... a_args)
{
    std::stringstream s;
    addToStream(s, std::forward<Args>(a_args)...);
    cprint_1(name, s.str());
}