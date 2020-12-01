#CSCI 451 - Assignment 11
#Grant Haataja
#
#Makefile
#
#to run program please run "./program0 input.data output.data" 
#in the command line after compiling

#define executable files
EXEC = program0 program1 program2 program3

#target for all programs in project
all: program0 program1 program2 program3
	
program0: program0.c
	gcc program0.c -o program0
	
program1: program1.c
	gcc program1.c -o program1
	
program2: program2.c
	gcc program2.c -o program2
	
program3: program3.c
	gcc program3.c -o program3

#clean up the mess
clean:
	rm -f $(EXEC) *.o *.tar* *.dat *.so output.data

#make a tarball of all the contents of the folder
targz:
	rm -f *.tar*
	tar -czvf hw11-GrantHaataja.tar.gz *.c Makefile *.data
