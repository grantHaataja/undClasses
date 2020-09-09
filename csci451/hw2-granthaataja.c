//CSci 451 Homework 2 - Grant Haataja

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	char *args[] = {argv[0], NULL};
	
	fork();
	system("firefox");
	fork();
	execvp(argv[0], args);

}
