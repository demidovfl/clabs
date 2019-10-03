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
	FILE *input;
	if(argc != 3)
	{
		printf("Введите параметры для входа\n");
		exit(1);
	}

	if ((input=fopen(argv[1], "rb")) == NULL)
	{
		printf("Не удается открыть входной файл\n");
		exit(1);	
	}

	while(!feof(input))
	{
		
	}
	
	
	printf("\n");
	fclose(input);
	printf("К концу каждой строки было добавлено:%s\n", argv[2]);
	return 0;
}
