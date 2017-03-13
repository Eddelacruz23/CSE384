#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <stdbool.h> 
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>


//http://stackoverflow.com/questions/34418418/inotify-event-in-c
//http://stackoverflow.com/questions/5211993/using-read-with-inotify
//http://www.c4learn.com/c-programs/write-a-program-to-copy-the-contents-of-one-file-into-another-using-fputc.html
//http://stackoverflow.com/questions/13351172/inotify-file-in-c
//http://lxr.free-electrons.com/source/fs/notify/inotify/inotify_user.c?v=2.6.30


void boolFunction(int argc, char* argv[]);

void filecopy(char * name);

void Directions(char * name);

void watchdog(char* filename);

int main(int argc, char* argv[])
{
	struct stat structofFile;
	 const char* file = argv[1];
	 int x = -1;

	if (argc != 2 || stat(file, &structofFile) < 0)
	{
		printf("ERROR : THIS FILE DOES NOT EXIST OR NOT A FILE");
		return EXIT_FAILURE;
	}


    if(argv[1] != x)
    {
    	printf(" %s \n", argv[0]);
    }

	char* filename = argv[1];

	Directions(filename);
	filecopy(filename);
	boolFunction(argc, argv);
}

void boolFunction(int argc, char* argv[])
{
	int choice = getopt(argc, argv, "md:t");
	bool choice1, choice2, choice3;
	

	int x = -1;

	choice1 = false;
	choice2 = false;
	choice3 = false;



	while (choice!=x){

		switch(choice) {

		case 't':
			choice1 = true; 
		break;

		case 'm':
			choice2 = false;
		break;

		case'd':
			choice3 = true;
		break;

		choice = getopt(argc, argv, "md:t");

		}
	}
}

void Directions(char * name)
{
	printf("%s \n \n \n", name);
	printf("(insert path) -d = Customize your backup location \n -m = Disable meta-data duplication \n -t = append the duplication time to specific file name \n \n \n");
}

void watchdog(char* filename){

	int inotify = inotify_init();
	ssize_t bufsize;
	char* structure;
	char x[bufsize];
	char store[1000];
	int _inotify = inotify_add_watch(store, IN_DELETE, inotify);
	strcpy(filename, store);
	bool trul = true;
	ssize_t processEvent = (sizeof(struct inotify_event));
	bufsize = (720 *(processEvent + 50));


	while (trul)
	{
		int fileread = read(x, bufsize, inotify);
		printf("%f \n\n\n", fileread);

		if(fileread == -1 && trul)
		{
			printf("ERROR : FILE COULD NOT BE DECIPHERED\n\n\n");
			continue; 
		}


		for(structure = x; structure <= x + fileread;)
		{
			struct inotify_event* inotify_ = (struct inotify_event*) structure;

			if((inotify_ -> mask&IN_DELETE) == IN_DELETE)
			{
				printf("FILE DELETED");
				exit(EXIT_SUCCESS);
			}

			structure = structure + sizeof(struct inotify_event) + inotify_ -> len;
		}
	}	
} 


void filecopy(char * name)
{

	FILE *secondfile;
	FILE *firstfile;

	firstfile = fopen(name, "r");

	if(firstfile == NULL) 
	{
		printf("ERROR : THIS FILE CANNOT BE FOUND");
		exit(EXIT_FAILURE);
	} 

	secondfile = fopen("x", "w");

	if(secondfile == NULL)
	{
		fclose(firstfile);
		printf("ERROR : THIS FILE CANNOT BE FOUND");
		exit (EXIT_FAILURE);
	}
	

	char firstvariable;

	do{
	fputc(firstvariable, secondfile);		
	}while((firstvariable=fgetc(firstfile)) != EOF);


	printf("\n WAS EXECUTED CORRECTLY \n"); 

	fclose(firstfile);
	fclose(secondfile);
}

