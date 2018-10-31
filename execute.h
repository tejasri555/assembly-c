#include"Header.h"
int registers[8];


void execute(struct intermediatelang interlang[])
{
	int i = 0, ifflag = 0;
	while (i<inno)
	{
		switch (interlang[i].opcode)
		{
		case 2:
			memcpy(&memory + interlang[i].parameters[0], &registers[interlang[i].parameters[1]], sizeof(int));
			i++;
			break;
		case 1:
			memcpy(&memory + interlang[i].parameters[1], &registers[interlang[i].parameters[0]], sizeof(int));
			i++;
			break;
		case 3:
			registers[interlang[i].parameters[0]] = registers[interlang[i].parameters[1]] + registers[interlang[i].parameters[2]];
			i++;
			break;
		case 4:
			registers[interlang[i].parameters[0]] = registers[interlang[i].parameters[1]] - registers[interlang[i].parameters[2]];
			i++;
			break;
		case 5:
			registers[interlang[i].parameters[0]] = registers[interlang[i].parameters[1]] * registers[interlang[i].parameters[2]];
			i++;
			break;
		case 6:
			i = interlang[i].parameters[0] - 1;
			break;
		case 7:
			if (interlang[i].parameters[2] == 8)
			{
				if (registers[interlang[i].parameters[0]] == registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			else if (interlang[i].parameters[2] == 9)
			{
				if (registers[interlang[i].parameters[0]] < registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			else if (interlang[i].parameters[2] == 10)
			{
				if (registers[interlang[i].parameters[0]] > registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			else if (interlang[i].parameters[2] == 11)
			{
				if (registers[interlang[i].parameters[0]] <= registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			else if (interlang[i].parameters[2] == 12)
			{
				if (registers[interlang[i].parameters[0]] >= registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			break;
		case 13:printf("%d ", registers[interlang[i].parameters[0]]);
			i++;
			break;
		case 14:
			printf("\n\nenter input values:\n");
			scanf("%d", &registers[interlang[i].parameters[0]]);
			i++;
			break;
		case 16:
			if (ifflag == 1)
			{
				i = interlang[i].parameters[0] - 1;
			}
			else
			{
				ifflag = 0;
				i++;
			}
			break;
		default:i++;
		}
	}
}
char * get_reg_variable(int index)
{
	if (index == 0)
		return "AX";
	if (index == 1)
		return "BX";
	if (index == 2)
		return "CX";
	if (index == 3)
		return "DX";
	if (index == 4)
		return "EX";
	if (index == 5)
		return "FX";
	if (index == 6)
		return "GX";
	if (index == 7)
		return "HX";
}
void execute(struct intermediatelang interlang[],FILE *cfile)
{
	int i = 0, ifflag = 0;
	while (i<inno)
	{
		switch (interlang[i].opcode)
		{
		case 2:
			memcpy(&memory + interlang[i].parameters[0], &registers[interlang[i].parameters[1]], sizeof(int));
			i++;
			break;
		case 1:
			memcpy(&memory + interlang[i].parameters[1], &registers[interlang[i].parameters[0]], sizeof(int));
			i++;
			break;
		case 3:
			registers[interlang[i].parameters[0]] = registers[interlang[i].parameters[1]] + registers[interlang[i].parameters[2]];
			i++;
			break;
		case 4:
			registers[interlang[i].parameters[0]] = registers[interlang[i].parameters[1]] - registers[interlang[i].parameters[2]];
			i++;
			break;
		case 5:
			registers[interlang[i].parameters[0]] = registers[interlang[i].parameters[1]] * registers[interlang[i].parameters[2]];
			i++;
			break;
		case 6:
			i = interlang[i].parameters[0] - 1;
			break;
		case 7:
			if (interlang[i].parameters[2] == 8)
			{
				if (registers[interlang[i].parameters[0]] == registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			else if (interlang[i].parameters[2] == 9)
			{
				if (registers[interlang[i].parameters[0]] < registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			else if (interlang[i].parameters[2] == 10)
			{
				if (registers[interlang[i].parameters[0]] > registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			else if (interlang[i].parameters[2] == 11)
			{
				if (registers[interlang[i].parameters[0]] <= registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			else if (interlang[i].parameters[2] == 12)
			{
				if (registers[interlang[i].parameters[0]] >= registers[interlang[i].parameters[1]])
				{
					ifflag = 1;
					i++;
				}
				else
					i = interlang[i].parameters[3] - 1;
			}
			break;
		case 13:
			printf("%d ", registers[interlang[i].parameters[0]]);
			i++;
			break;
		case 14:
			printf("\n\nenter input values:\n");
			scanf("%d", &registers[interlang[i].parameters[0]]);
			i++;
			break;
		case 16:
			
			if (ifflag == 1)
			{
				i = interlang[i].parameters[0] - 1;
			}
			else
			{
				ifflag = 0;
				i++;
			}
			break;
		default:i++;
		}
	}
}
void convert_to_c(struct intermediatelang interlang[], FILE *cfile)
{
	int i = 0, ifflag = 0;
	char *s,*label = (char *)malloc(sizeof(char) * 10);
	while (i<inno)
	{
		switch (interlang[i].opcode)
		{
		case 1:
			fprintf(cfile, "%c=%s;\n", get_mem_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]));
			i++;
			break;
		case 2:
			fprintf(cfile, "%s=%c;\n", get_reg_variable(interlang[i].parameters[0]), get_mem_variable(interlang[i].parameters[1]));
			i++;
			break;
		case 3:
			fprintf(cfile, "%s=%s+%s;\n", get_reg_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]), get_reg_variable(interlang[i].parameters[2]));
			i++;
			break;
		case 4:
			fprintf(cfile, "%s=%s-%s;\n", get_reg_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]), get_reg_variable(interlang[i].parameters[2]));
			i++;
			break;
		case 5:
			fprintf(cfile, "%s=%s*%s;\n", get_reg_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]), get_reg_variable(interlang[i].parameters[2]));
			i++;
			break;
		case 6:
			s = (char *)malloc(sizeof(char) * 10);
			s=get_label(interlang[i].parameters[0]-1);
			fprintf(cfile, "goto %s;\n", s);
			i++;
			break;
		case 7:
			if (interlang[i].parameters[2] == 8)
			{
				fprintf(cfile, "if(%s == %s){\n", get_reg_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]));
			}
			else if (interlang[i].parameters[2] == 9)
			{
				fprintf(cfile, "if(%s < %s){\n", get_reg_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]));

			}
			else if (interlang[i].parameters[2] == 10)
			{
				fprintf(cfile, "if(%s > %s){\n", get_reg_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]));
			}
			else if (interlang[i].parameters[2] == 11)
			{
				fprintf(cfile, "if(%s <= %s){\n", get_reg_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]));

			}
			else if (interlang[i].parameters[2] == 12)
			{
				fprintf(cfile, "if(%s >= %s){\n", get_reg_variable(interlang[i].parameters[0]), get_reg_variable(interlang[i].parameters[1]));
			}
			i++;
			break;
		case 13:
			fprintf(cfile, "printf(\"%%d \",%s);\n", get_reg_variable(interlang[i].parameters[0]));
			i++;
			break;
		case 14:
			fprintf(cfile, "scanf(\"%%d\",&%s);\n", get_reg_variable(interlang[i].parameters[0]));
			i++;
			break;
		case 15:
			fprintf(cfile, "\n}\n");
			i++;
			break;
		case 16:
			fprintf(cfile, "}\n");
			fprintf(cfile, "else\n");
			fprintf(cfile, "{\n");
			i++;
			break;
		case 17:
			fprintf(cfile, "%s:\n",get_label(interlang[i].parameters[0]-1));
			i++;
		}
	}
	fputs("return 0;\n}\n", cfile);
	fclose(cfile);
}
int execute_assembly_code()
{

	for (int i = 0; i < 800; i++)
	{
		int y = 0;
		memcpy(&memory + i, &y, sizeof(int));
	}
	FILE *fp;
	fp = fopen("sample.txt", "r");
	f = fopen("intermediatelang.txt", "w");
	sf = fopen("symboltable.txt", "w");
	m = fopen("memory.txt", "w");
	metadata = fopen("metadata.txt", "w");
	char ch;
	char *key = (char *)malloc(sizeof(char) * 10);
	fscanf(fp, "%s", key);

	while (strcmp(key, "DATA") == 0 || strcmp(key, "CONST") == 0)
	{
		nsym++;
		if (strcmp(key, "DATA") == 0)
		{
			char *sym = (char *)malloc(sizeof(char) * 10);
			fscanf(fp, "%s", sym);
			int size = findsymsize(sym);
			st[ind].sym = sym[0];
			st[ind].add = add;
			st[ind].size = size;
			add += size;
		}
		else
		{
			char sym;
			int val;
			fgetc(fp);
			fscanf(fp, "%c", &sym);
			fgetc(fp);
			fscanf(fp, "%d", &val);
			memcpy(&memory + add, &val, sizeof(int));
			st[ind].sym = sym;
			st[ind].add = add;
			st[ind].size = 0;
			add += 1;
		}
		fgetc(fp);
		fscanf(fp, "%s", key);
		ind++;
	}
	printf("======================================================================================================================\n");
	printf("symbol address size\n");
	printf("======================================================================================================================\n");

	displaysymboltable();
	printf("\n");
	printf("=======================================================================================================================\n");
	printf("Inno Opcode Parameters\n");
	printf("=====================================================================================================================\n");

	struct intermediatelang interlang[50];
	char *lab = (char *)malloc(sizeof(char) * 20);
	while (fscanf(fp, "%s", key) != '\0' && strcmp(key, "END"))
	{
		int opcode = getopcode(key);
		char *param = (char *)malloc(sizeof(char) * 10);
		int j = 0, add;
		char t;
		switch (opcode)
		{
		case 1:
			interlang[inno].inno = inno + 1;
			t = fgetc(fp);
			while (t != '\n' && t != '\0')
			{
				int i = 0;
				t = fgetc(fp);
				while (t != ',' && t != '\n' && t != '\0')
				{
					param[i++] = t;
					t = fgetc(fp);
				}
				param[i] = '\0';
				if (j == 0 && (strcmp(param, "AX") == 0 || strcmp(param, "BX") == 0 || strcmp(param, "CX") == 0 || strcmp(param, "DX") == 0 || strcmp(param, "EX") == 0 || strcmp(param, "FX") == 0 || strcmp(param, "GX") == 0 || strcmp(param, "HX") == 0))
					interlang[inno].opcode = 1;
				else
					interlang[inno].opcode = 2;
				interlang[inno].parameters[j++] = getparamno(param);
			}
			interlang[inno].len = j;
			inno++;
			break;
		case 17:
			interlang[inno].inno = inno + 1;
			interlang[inno].opcode = opcode;
			interlang[inno].parameters[0] = inno + 1;
			interlang[inno].len = 1;
			lbl[lblind].add = inno + 1;
			key[strlen(key) - 1] = '\0';
			lbl[lblind].name = (char *)malloc(sizeof(char) * 10);
			strcpy(lbl[lblind].name, key);
			lblind++;
			inno++;
			break;
		case 6:
			interlang[inno].inno = inno + 1;
			interlang[inno].opcode = opcode;
			fscanf(fp, "%s", lab);
			interlang[inno].parameters[0] = lab_add(lab);
			interlang[inno].len = 1;
			inno++;

			break;
		case 7:
			interlang[inno].inno = inno + 1;
			interlang[inno].opcode = opcode;
			fgetc(fp);
			fscanf(fp, "%s", param);
			interlang[inno].parameters[0] = getparamno(param);
			fscanf(fp, "%s", param);
			interlang[inno].parameters[2] = getopcode(param);
			fscanf(fp, "%s", param);
			interlang[inno].parameters[1] = getparamno(param);
			interlang[inno].len = 3;
			push(inno);
			fscanf(fp, "%s", param);
			inno++;
			break;
		case 16:
			interlang[inno].inno = inno + 1;
			interlang[inno].opcode = opcode;
			interlang[inno].len = 0;
			add = pop();
			interlang[add].parameters[interlang[add].len] = (interlang[inno].inno) + 1;
			interlang[add].len++;
			push(inno);
			inno++;
			break;
		case 15:
			interlang[inno].inno = inno + 1;
			interlang[inno].opcode = opcode;
			interlang[inno].len = 0;
			add = pop();
			interlang[add].parameters[interlang[add].len] = inno + 1;
			interlang[add].len++;
			inno++;
			break;
		default:
			interlang[inno].inno = inno + 1;
			interlang[inno].opcode = opcode;
			t = fgetc(fp);
			while (t != '\n' && t != '\0')
			{
				int i = 0;
				t = fgetc(fp);
				while (t != ',' && t != '\n' && t != '\0')
				{
					param[i++] = t;
					t = fgetc(fp);
				}
				param[i] = '\0';
				interlang[inno].parameters[j++] = getparamno(param);
			}
			interlang[inno].len = j;
			inno++;
		}
	}
	display(interlang);
	/*for (int i = 0; i < 800; i++)
	{
	int y;
	memcpy(&y, &memory + i, sizeof(int));
	fprintf(m, "%d ", y);
	printf("%d ", y);
	}*/
	fclose(m);
	execute(interlang);
	int end;
	
	return 0;
}
