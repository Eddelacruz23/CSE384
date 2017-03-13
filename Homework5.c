#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

//http://www.c4learn.com/c-programs/write-a-program-to-copy-the-contents-of-one-file-into-another-using-fputc.html

void filecopy(char * name);

void Directions(char * name);

int main(int argc, char* argv[])
{
	char* nameoftheFile = argv[1];

	Directions(nameoftheFile); 
	filecopy(nameoftheFile);
}

void Directions(char * name){
	printf("%s \n \n \n", name);
	printf("(insert path here) -d = Customize your backup location \n -m = Disable meta-data duplication \n -t = append the duplication time to specific file name \n \n \n");
}


void filecopy(char * name)
{

	FILE *secondfile;
	FILE *firstfile;
	char y;



	firstfile = fopen(name, "r");
	if(firstfile == NULL) 
	{
		printf("ERROR : THE ORGIN FILE CANNOT BE FOUND");
		exit(EXIT_FAILURE);
	} 

	secondfile = fopen("x", "w");

	if(secondfile == NULL)
	{
		fclose(firstfile);
		printf("ERROR : THE TARGET FILE CANNOT BE FOUND");
		exit (EXIT_FAILURE);
	}
	
	do{
	fputc(y, secondfile);		
	}while((y=fgetc(firstfile)) != EOF);


	printf(" WAS EXECUTED CORRECTLY "); 

	fclose(firstfile);
	fclose(secondfile);
}