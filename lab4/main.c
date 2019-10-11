#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 50

char* rena(const char* a, const char* b)
{
    size_t len = strlen(a) + strlen(b);
    char *ren = (char*)malloc(len * sizeof(char) + 1);
    *ren = '\0';
    return strcat(strcat(ren, a) ,b);
}

int main(int argc, char *argv[])
{	
	char temp_arr[N];
	char *name = rena(argv[1], ".test");
	FILE *input, *output;
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

	output = fopen(name, "wb");


	while(!feof(input)) 
	{
		fgets(temp_arr, N, input);
		if((temp_arr[0]>=97 & temp_arr[0]<=122) || (temp_arr[0]>=65 & temp_arr[0]<=90))
		{	
			printf("%s",temp_arr);
			fputs(temp_arr, output);
		}
	}
	fputs("\n", output);
	printf("\n");
	free(name);
	fclose(input);
	fclose(output);
	return 0;
} //