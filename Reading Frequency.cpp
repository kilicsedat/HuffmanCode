// 
//

#include "pch.h"
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	fstream inFile;
	char oneChar;

	int frequency[128];


	for (int ASCII = 0; ASCII < 128; ASCII++) //Loop through all the ASCII characters to get the frequency of each
	{
		frequency[ASCII] = 0;
	}

	inFile.open("ASCII.txt", ios::in); //Reads file

	if (inFile.fail()) //Check for error opening the file
	{
		cout << "Error: File not found!" << endl << endl;
	}
	else
	
	
	{
		oneChar = inFile.get();

		while (inFile.eof() == false) //End of file
		{
			if (oneChar != ' ')
			{
				frequency[oneChar]++; //When not empty character
			}
			oneChar = inFile.get();
		
		}
	
	}

	inFile.close();
	
	ofstream mfile;
	mfile.open("freq.txt");
	
	for (char count = '+'; count <= 'z'; count++)
	{
		if (frequency[count] != 0)
		{
			mfile << count << setw(4) << frequency[count] << endl; // puts nonzero characters in the new text file freq.txt
		}
	}
	return 0;
}
