
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char opcodes[17][10] = { "MOV", "MOV", "ADD", "SUB", "MUL", "JUMP", "IF", "EQ", "LT", "GT", "LTEQ", "GTEQ", "PRINT", "READ", "ENDIF", "ELSE", "LABEL" };
void * memory = malloc(800);
FILE *f, *sf, *m, *metadata;
struct intermediatelang
{
	int inno;
	int opcode;
	int parameters[6];
	int len;
};
struct label
{
	char *name;
	int add;
};


struct symboltable
{
	char sym;
	int add;
	int size;
};

struct label lbl[10];
struct symboltable st[10];
void *memory = malloc(1000);
struct intermediatelang il[50];
int registers[8];
int lblind = 0;
int stack[10];
int top = -1;
int inno = 0, nsym = 0;