#define _CRT_SECURE_NO_WARNINGS
#include"execute.h"

int main()
{
	printf("\n=========================================WELCOME TO CODE GENERATOR====================================\n\t\t1.Do you want to directly execute assembly language code\n\t\t2.Do you want to convert assembly language to c language and execute\n\t\tENTER YOUR CHOICE ");
	int choice;
	scanf("%d", &choice);
	if (choice == 1){
		execute_assembly_code();
		printf("----ended-----\n");
		scanf("%d", &choice);
		return 0;
	}
	execute_assembly_code();
	FILE *ilf, *m,*metadata,*cfile,*stf;
	ilf = fopen("intermediatelang.txt", "r");
	m = fopen("memory.txt", "r");
	stf = fopen("symboltable.txt", "r");
	metadata = fopen("metadata.txt", "r");
	cfile = fopen("clang.txt", "w");
	fputs("#include<stdio.h>\n", cfile);
	fputs("int main()\n{\n", cfile);
	fputs("int AX,BX,CX,DX,EX,FX,GX,HX;\n",cfile);
	load_memory(m);
	load_intermediatelang(ilf,metadata);
	read_symbol_table(stf,metadata,cfile);
	read_lbls(metadata);

	if (choice!=1)
		execute(il,cfile);
	convert_to_c(il, cfile);
	fclose(cfile);
	cfile = fopen("clang.txt", "r");
	char c = fgetc(cfile);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(cfile);
	}

	fclose(cfile);
	int end;
	scanf("%d", &end);
	return 0;
}