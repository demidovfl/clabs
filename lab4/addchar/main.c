#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 50


char* sum(const char* a, const char* b)
{
    size_t len = strlen(a) + strlen(b);
    char *ren = (char*)malloc(len * sizeof(char) + 1);
    *ren = '\0';
    return strcat(strcat(ren, a) ,b);
}

int main(int argc, char *argv[])
{	
	char temp_arr[N];
	char *name = sum(argv[1], ".rezult");
	FILE *input, *output;
	if(argc != 3)
	{
		printf("Введите параметры для входа\n");
		exit(1);
	}

	if ((input=fopen(argv[1], "r+")) == NULL)
	{
		printf("Не удается открыть входной файл\n");
		exit(1);	
	} 
	output = fopen(name, "wb");
	printf("К данным строкам будет добавлен символ %s :\n", argv[2]);
	while(!feof(input))
	{	
		fgets(temp_arr, N, input);
		printf("%s ", temp_arr);
		int pos = strlen(temp_arr)-1;
		if (temp_arr[pos] == '\n')
		{
			temp_arr[pos] = '\0';
		}
		strcat(temp_arr, argv[2]);
		fputs(temp_arr, output);
		fputc(10, output);

	}
	
	printf("\n");
	fclose(input);
	fclose(output);
	printf("К концу каждой строки было добавлено:%s\n", argv[2]);
	return 0;
}
