//CSci 451 Homework 2 - Grant Haataja

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	//store the name of the executable as an argument to pass to execvp
	char *args[] = {argv[0], NULL};
	int exitStatus = 1;
	pid_t PID;
	
	//create child process
	PID = fork();
	//check if the child process is returned and then execute the child
	if (PID == 0) {
		execvp(argv[0], args);
		exit(exitStatus);	
	}
	//start a program to further increase the destruction of the system
	else {
		system("gnome-terminal");
		waitpid(PID, &exitStatus, 0);
	}

	return 0;
}
