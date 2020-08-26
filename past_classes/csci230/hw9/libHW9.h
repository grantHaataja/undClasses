//Grant Haataja
//Assignment 9

#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<dlfcn.h>

//define functions
int SCAN(char *fileName, FILE *(*stream));
struct _data *LOAD(FILE *stream, int size, char *fileName);
void SEARCH(struct _data *BlackBox, char *name, int size);
void FREE(struct _data *BlackBox, int size, char *fileName);

