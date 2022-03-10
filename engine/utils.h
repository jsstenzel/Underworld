#ifndef UTILS_H
#define UTILS_H

void tprint(string str)
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

	//lastly, print an endline
	cout << endl;
}


void cprint(string name, string str)
{
	//convert name to all caps
	
	cout << NAME << endl;
	
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

	//lastly, print two endlines to start the next line or continue other text.
	cout << endl << endl;
}

#endif