#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include <mcheck.h>
#define max_len 1024

int i_count = 0;


char** inp_arr(int number)
{
	char buf[max_len];
	char **arr;  
	arr = (char **)malloc(sizeof(char *)*number);
    for (int i = 0; i < number ; i++)
    {
        scanf("%s", buf); 
        arr[i] = (char *)malloc(sizeof(char)*strlen(buf)); 
        strcpy(arr[i], buf); 
    }
    return arr; 
}

void out_arr(char **arr, int number)
{
    for (int i = 0; i < number ; i++)
    {
        printf("\nStr#%d: %s Длина строки:%ld\n",i+1, arr[i],strlen(arr[i]));
    }
}

void free_arr(char **arr, int number)
{
	for (int i = 0; i < number; i++)
	{
        free(arr[i]); 
    }
    free(arr); 
}

int sort_arr(const void *arr1,const void *arr2)
{
	char *a = *(char **)arr1; 
	char *b = *(char **)arr2;
	if (strlen(b)>strlen(a))
	{
		i_count++;
		return strlen(b)-strlen(a);
	}
	else{
		return strlen(b)- strlen(a);
	}
}

int biggest_str(char **arr, int number)
{	
	char *str=arr[0];
	for (int i = 0; i < number; ++i)
	{
		if(strlen(arr[i])>strlen(str))
		{
			arr[i]>str;
			str = arr[i];
		}

	}
	printf("Большая строка:%s, её длина:%ld\n",str,strlen(str));
}


int main()
{	
	char **arr = NULL;
	int number;
	printf("Введите количество строк:");
	scanf("%d",&number);
	mtrace();
	printf("Введите строки по одной\n");
	arr = inp_arr(number);
	qsort(arr, number, sizeof(char*),sort_arr);
	out_arr(arr, number);
	biggest_str(arr, number);
	free_arr(arr, number);
	printf("\nКоличество перестановок:%d\n",i_count );
	return 0;
}