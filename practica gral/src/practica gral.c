/*
 ============================================================================
 Name        : practica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int main(void)
{
int *a;
int *aAux;
	int i;
	for(i=0;i<5;i++)
	{
		a=malloc(sizeof(int)*5);
		if(a==NULL)
		{
			printf("NO hay lugar \n");
		}
		else
		{
			*(a+i)=i+1;
		}
		printf("vector %d \n",*(a+i));
	}
aAux=realloc(a,sizeof(int)*10);
if(aAux==NULL)
{
	printf("NO hay lugar \n");
}
else
{
	a=aAux;
}
for(i=5;i<10;i++)
{
	*(a+i)=i+1;
	printf("vector %d \n",*(a+i));
}
	for(i=0;i<10;i++)
	{
		free((a+i));
		printf("vector %d \n",*(a+i));
	} // ver si free esta liberando bien el espacio.
return EXIT_SUCCESS;
}



typedef struct
{
	int codigo;
	char marca[20];
	char modelo[20];
	int capacidad;
}ePendrive;


//
//int guardarEnArchivoBinario(ePendrive* ,char *path)
//{
//FILE *pFileBin =NULL;
//ePendrive* pPenDrive;
//int i;
//pFileBin=fopen(path,"wb");
//if(pFileBin!=NULL && pPenDrive!=NULL)
//{
//	for(i=0;i<ll_len())
//}
//
//
//}
