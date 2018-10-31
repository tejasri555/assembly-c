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
struct label lbl[10];
int lblind = 0;
int stack[10];
int top = -1;
int inno = 0, nsym = 0;
void push(int n)
{
	stack[++top] = n;
}
int pop()
{
	int t = stack[top];
	top--;
	return t;
}
int add = 0, ind = 0;
struct symboltable
{
	char sym;
	int add;
	int size;
};
struct symboltable st[10];
int getopcode(char *key)
{
	for (int i = 0; i < 16; i++)
	{
		if (strcmp(key, opcodes[i]) == 0)
			return i + 1;
	}
	if (key[strlen(key) - 1] == ':')
		return 17;
	return -1;
}
int findsymsize(char *sym)
{
	int val = 0, i = 0;
	if (strlen(sym) != 1)
	{
		sym += 2;
		while (sym[i] != ']')
		{
			val = val * 10 + (sym[i] - '0');
			i++;
		}
		return val;
	}
	return 1;
}
int getparamno(char *param)
{

	if (strcmp(param, "AX") == 0)
		return 0;
	if (strcmp(param, "BX") == 0)
		return 1;
	if (strcmp(param, "CX") == 0)
		return 2;
	if (strcmp(param, "DX") == 0)
		return 3;
	if (strcmp(param, "EX") == 0)
		return 4;
	if (strcmp(param, "FX") == 0)
		return 5;
	if (strcmp(param, "GX") == 0)
		return 6;
	if (strcmp(param, "HX") == 0)
		return 7;
	for (int i = 0; i < ind; i++)
	{
		if (param[0] == st[i].sym && strlen(param) == 1)
			return st[i].add;
	}
	if (param[strlen(param) - 1] == ']')
	{
		for (int i = 0; i < ind; i++)
		{
			if (param[0] == st[i].sym)
			{
				int offset = 0, j = 0;
				param += 2;
				while (param[j] != ']')
					offset = offset * 10 + param[j++] - '0';
				return st[i].add + offset;
			}
		}
	}
	return -1;
}
void display1(intermediatelang il[])
{

	for (int i = 0; i < inno; i++)
	{
		printf("%d    %d    ", il[i].inno, il[i].opcode);
		for (int j = 0; j < il[i].len; j++)
		{
			printf("%d ", il[i].parameters[j]);

		}


		printf("\n");

	}

}
void display(intermediatelang il[])
{
	fprintf(metadata, "%d\t", inno);
	for (int i = 0; i < inno; i++)
	{
		printf("%d\t %d\t", il[i].inno, il[i].opcode);
		fprintf(f, "%d\t%d ", il[i].inno, il[i].opcode);
		for (int j = 0; j < il[i].len; j++)
		{
			printf("%d\t", il[i].parameters[j]);
			fprintf(f, "%d\t", il[i].parameters[j]);
		}
		fprintf(metadata, "%d\t", il[i].len);

		printf("\n");
		fprintf(f, "\n");
	}
	fprintf(metadata, "%d ", nsym);
	fprintf(metadata, "%d ", lblind);
	for (int i = 0; i < lblind; i++)
		fprintf(metadata, "%d %s ", (lbl[i].add) - 1, lbl[i].name);
	fclose(metadata);
	fclose(f);
}
void displaysymboltable()
{
	for (int i = 0; i < ind; i++)
	{
		printf("%c\t%d\t%d\n", st[i].sym, st[i].add, st[i].size);
		fprintf(sf, "%c\t%d\t%d\n", st[i].sym, st[i].add, st[i].size);
	}
	fclose(sf);
}
int lab_add(char *lab)
{
	//lab[strlen(lab) - 1] = '\0';
	for (int i = 0; i < lblind; i++)
	{

		if (strcmp(lbl[i].name, lab) == 0)
			return lbl[i].add;
	}
	return -1;
}




struct intermediatelang il[50];

char get_mem_variable(int index)
{
	for (int i = 0; i < nsym; i++)
	{
		if (i == index)
			return st[i].sym;
	}
	return '\0';
}
void load_memory(FILE *m)
{
	int y;
	for (int i = 0; i < 400; i++)
	{
		fscanf(m, "%d", &y);
		memcpy(&memory + i, &y, sizeof(int));
	}
}
void load_intermediatelang(FILE *ilf,FILE *metadata)
{
	char *s = (char *)malloc(sizeof(char) * 20);
	
	fscanf(metadata, "%d", &inno);
	int i = 0;
	while (i<inno)
	{
		fscanf(ilf, "%d", &il[i].inno);
		fscanf(ilf, "%d", &il[i].opcode);
		int len = 0;
		fscanf(metadata, "%d", &len);
		il[i].len = len;
		int j = 0;
		while (j<len)
		{
			fscanf(ilf, "%d", &il[i].parameters[j]);
			j++;
		}
		i++;
	}
	
}

void read_symbol_table(FILE *stf,FILE *metadata,FILE *cfile)
{
	char sym;
	int add, size, i = 0;
	fscanf(metadata, "%d", &nsym);
	while (i<nsym)
	{
		fscanf(stf, "%c", &sym);
		fscanf(stf, "%d", &add);
		fscanf(stf, "%d", &size);
		st[i].sym = sym;
		st[i].add = add;
		st[i].size = size;
		fscanf(stf, "%c", &sym);
		if (size !=0)
			fprintf(cfile, "int %c;\n",st[i].sym);
		else
			fprintf(cfile, "const int %c;\n",st[i].sym);
		i++;
	}
}
void read_lbls(FILE *metadata)
{
	fscanf(metadata, "%d", &lblind);
	for (int i = 0; i < lblind; i++)
	{
		fscanf(metadata, "%d",&lbl[i].add);
		//fgetc(metadata);
		lbl[i].name = (char *)malloc(sizeof(char) * 10);
		fscanf(metadata, "%s",lbl[i].name);
	}
}
char * get_label(int add)
{
	for (int i = 0; i < lblind; i++)
	{
		if (lbl[i].add == add)
			return lbl[i].name;
	}
	return "A";
}