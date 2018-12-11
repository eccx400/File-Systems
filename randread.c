#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	FILE * input;
	long long man;

	//This code uses fopen to open the input
	//file and sets the parameters for fopen()
	//to be read
	input = fopen(argv[1], "r");
	
	//Checks to see whether or not the file can be opened.
	if(!input)
	{
		printf("File cannot be opened");
		return 0;
	}

	//changes the position indicator
	fseek(input, 0, SEEK_END);
	man = ftell(input);
	
	// This is the counter for position in test file
	long long toorukun = 0;
	long long chichan;
	
	//Checks to see if every character of file has been read
	while(toorukun < man)
	{
		int sakerugumi;

		//Loop below changes the position randomly
		do{
			chichan = rand();
			chichan = (chichan << 32) | rand();
			sakerugumi = fseek(input, chichan , SEEK_SET);
		}while(sakerugumi != 0);
		fgetc(input);
		toorukun++;
	}
	fclose(input);	
	return 0;
}
