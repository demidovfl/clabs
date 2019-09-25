#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include <mcheck.h>
#define max_len 1024

char** inp_arr(int count);
void out_arr(char **arr, int count);
void free_arr(char **arr, int count);

int main()
{	
	char **mas = NULL; 
	int count = 3;
	mtrace();
	mas = inp_arr(count);
	out_arr(mas, count);
	free_arr(mas, count);
	printf("hello\n");
	return 0;
}

char** inp_arr(int count)
{
	char buf[max_len];
	char **arr;  
	arr = (char **)malloc(sizeof(char *)*count);
    for (int i = 0; i < count ; i++)
    {
        scanf("%s", buf); 
        arr[i] = (char *)malloc(sizeof(char)*strlen(buf)); 
        strcpy(arr[i], buf); 
    }
    return arr; 
}

void out_arr(char **arr, int count)
{
    for (int i = 0; i < count ; i++)
    {
        printf("%s\n", arr[i]);
    }
}

void free_arr(char **arr, int count)
{
	for (int i = 0; i < count; i++)
	{
        free(arr[i]); 
    }
    free(arr); 
}
