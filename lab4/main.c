#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define N 50

int main(int argc, char *argv[])
{	
	char temp_arr[N];
	int k;

	FILE *input;
	if(argc != 2)
	{
		printf("Не было введено имя файла\n");
		exit(1);
	}
	if ((input=fopen(argv[1], "r")) == NULL)
	{
		printf("Не удается открыть входной файл\n");
		exit(1);
	}
	/*if (output=fopen(argv[2], "r") == NULL)
	{
		printf("Не удается открыть выходной файл\n");
		exit(1);
		}*/
	while(!feof(input)) 
	{
		fgets(temp_arr, N, input);
		printf("%s",temp_arr);
	}
	printf("\n");
	return 0;
}