#CSCI 451 - Assignment 10
#Grant Haataja
#
#Makefile

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
	rm -f $(EXEC) *.o *.tar* *.so *.dat output.data

#make a tarball of all the contents of the folder
targz:
	rm -f *.tar*
	tar -czvf hw10-GrantHaataja.tar.gz *.c Makefile *.data
