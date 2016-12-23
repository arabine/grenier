
/*
Groar - main.c
Entry point for the unitary test
*/

#include "groar.h"

int main(int argc, char **argv)
{
	int ret;
	unsigned char *ptr_data;

	if(argc != 2)
	{
		printf("Bad options.\n");
		exit(1);
	}

	ptr_data = openOggFile(argv[1]);
	if(ptr_data == NULL)
	{
		printf("!!! Error : Can't allocate memory.\n");
		exit(1);
	}

	ret = groar(ptr_data);

	printf("groar returned : %d\n", ret);
	free(ptr_data);
	getch();
	return 0;
}