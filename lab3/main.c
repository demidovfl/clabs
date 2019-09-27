#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include <mcheck.h>

struct detail
{
	char name[50];
	int price;
	int birthday;
};
typedef struct detail details;

void read_detail(details *dt)
{
	printf("Введите наименование детали: \n");
	scanf("%s",&dt->name);
	printf("Введите стоимость детали: \n");
	scanf("%d",&dt->price);
	printf("Введите год выпуска детали: \n");
	scanf("%d", &dt->birthday);
}

void inp_detail(details *dt)
{
	printf("Название:%s\n", dt->name);
	printf("Название:%d\n", dt->price);
	printf("Название:%d\n", dt->birthday);
}

static int cmp(const void *d1, const void *d2)
{
	details *dt1 = *(details**)d1;
	details *dt2 = *(details**)d2;
	return dt2->price - dt1->price;
}

int main()
{	int count;
	printf("Введите количество деталей: \n");
	scanf("%d",&count);
	details** dt = (details**)malloc(sizeof(details*)*count);
	for (int i = 0; i < count; i++)
	{
		dt[i] = (details*)malloc(sizeof(details));
		read_detail(dt[i]);
		printf("\n");
	}

	qsort(dt, count, sizeof(details*), cmp);

	for (int i = 0; i < count; i++)
	{	
		printf("Деталь#%d:\n", i+1);
		inp_detail(dt[i]);
	}

	for (int i = 0; i < count; i++)
	{
		free(dt[i]);
	}

	free(dt);

	return 0;
}