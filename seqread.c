#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * This code will read the characters generated in the file
 * sequentially 
 */
int main(int argc, char *argv[])
{
	FILE *input;
	char arr[1024];

	//This opens the file with parameters set to read
	input = fopen(argv[1], "r");
	
	//Checks to see whether the file has correctly opened
	if(!input)
	{
		printf("File did not open u dumdum");
		return 0;
	}

	//This allows the file to be read until there are no
	//more characters in the file that can be read
	while(fgetc(input)!= EOF)
	{
		//Do something
	}
	fclose(input);
	return 0;
}
