#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static int isValidLetra(char *item, int cant);


Employee* employee_new()
{
	return malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee *retorno=NULL;
	Employee* this;
	int id;
	int horasTrabajadas;
	int sueldo;
	this= employee_new();
	if(this!=NULL)
	{
	if(pasarANumeroInt(idStr, &id)!=0)
	{
		printf("ERROR, el id no es un numero \n");
	}
	if(pasarANumeroInt(horasTrabajadasStr,&horasTrabajadas)!=0)
	{
		printf("ERROR, las horas trabajadas no es un valor numerico \n");
	}
	if(pasarANumeroInt(sueldoStr,&sueldo)!=0)
	{
		printf("ERROR, el sueldo no es un valor numerico \n");
	}
	if( employee_setId(this,id)==0 && employee_setNombre(this, nombreStr)==0 && employee_setHorasTrabajadas(this, horasTrabajadas)==0 && employee_setSueldo(this, sueldo)==0)
	{
		retorno=this;
	}
	else
	{
		employee_delete(this);
	}
	}
	return retorno;
}


void employee_delete(Employee*this)
{
	free(this);
}


int employee_setId(Employee* this,int item)
{
	int retorno =-1;
	if(this!=NULL) //hacer la funcion de validar el numero positivo y ademas pasar el id
		{
			this->id=item;
			retorno=0;
		}

		return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno=1;

	if(this!=NULL && id>=0)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno =-1;
	if(this!=NULL && isValidLetra(nombre, 4096)) // hacer la funcion de validar el numero positivo y ademas pasar el id
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=1;

		if(this!=NULL && nombre!=NULL)
		{
			strcpy(nombre,this->nombre);
			retorno=0;
		}
		return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno =-1;
		if(this!=NULL) //hacer la funcion de validar el numero positivo y ademas pasar el id
		{
			this->horasTrabajadas=horasTrabajadas;
			retorno=0;
		}
		return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=1;

	if(this!=NULL && horasTrabajadas>0)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno =-1;
		if(this!=NULL ) //hacer la funcion de validar el numero positivo y ademas pasar el id
		{
			this->sueldo=sueldo;
			retorno=0;
		}

		return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=1;

	if(this!=NULL && sueldo>0)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}



static int isValidLetra(char *item, int cant)
{
	int retorno=-1;
//	int i;
//	for(i=0;i<cant;i++)
//	{
//		while((item[i] != '\0' && item[i]== ' ') || (item[i] >= 'a' && item[i] <= 'z')|| (item[i] >= 'A' && item[i] <= 'Z'))
//		{
//			retorno=EXIT_SUCCESS;
//		}
//
//	}
//	printf("retorno del isvalidletra : %d",retorno);
	return retorno;
}


Employee* buscarIdEmpleado(LinkedList* pArrayListEmployee, int id)
{
	Employee*this=NULL;
	int i;
	if(pArrayListEmployee!=NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee);i++)
			{
				this = ll_get(pArrayListEmployee, i);
				if(this->id == id)
				{
					return this;
				}
			}
	}
	return this;
}


int employee_sortPorId( void * datoUno, void *datoDos)
{
	int idUno;
	int idDos;
	idUno=((Employee*)datoUno)->id;
	idDos=((Employee*)datoDos)->id;
	if(idUno > idDos)
	{
		return 1;
	}
	else if(idUno < idDos)
	{
		return -1;
	}
	return 0;
}

int employee_sortPorNombre( void * datoUno, void *datoDos)
{

	if(strncmp(((Employee *)datoUno)->nombre,((Employee *)datoDos)->nombre,50)>0)
	{
		return 1;
	}
	else if(strncmp(((Employee *)datoUno)->nombre,((Employee *)datoDos)->nombre,50)<0)
	{
		return -1;
	}
	return 0;
}

int employee_sortPorHorasTrabajadas( void * datoUno, void *datoDos)
{
	int horasUno;
	int horasDos;
	horasUno=((Employee*)datoUno)->horasTrabajadas;
	horasDos=((Employee*)datoDos)->horasTrabajadas;
	if(horasUno > horasDos)
	{
		return 1;
	}
	else if(horasUno < horasDos)
	{
		return -1;
	}
	return 0;
}

int employee_sortPorSueldo( void * datoUno, void *datoDos)
{
	int sueldoUno;
	int sueldoDos;
	sueldoUno=((Employee*)datoUno)->sueldo;
	sueldoDos=((Employee*)datoDos)->sueldo;
	if(sueldoUno > sueldoDos)
	{
		return 1;
	}
	else if(sueldoUno < sueldoDos)
	{
		return -1;
	}
	return 0;
}
