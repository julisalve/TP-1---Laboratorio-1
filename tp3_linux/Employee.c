#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static int isValidLetra(char *item, int cant);


Employee* employee_new()
{
	return malloc(sizeof(Employee));
//	Employee *this;
//	this= malloc(sizeof(Employee));
//	if(this == NULL)
//	    {
//	        printf("\nNo hay mas lugar para cargar empleados");
//
//	    }
//
//	    else
//	    {
//	        this->id = 0;
//	        strcpy(this->nombre, "");
//	        this->horasTrabajadas = 0;
//	        this->sueldo = 0;
//	    }
//	return this;
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
//id = atoi(idStr);
//
//horasTrabajadas = atoi(horasTrabajadasStr);
//	sueldo = atoi(sueldoStr);

//	printf("id char %s, id numero %d \n horas trab string %s , hs trabajads numero %d \n sueldo str %s .- sueldo numero %d \n - nombre %s \n",idStr,id, horasTrabajadasStr,horasTrabajadas,sueldoStr,sueldo,nombreStr);
//int a;
//a=	employee_setId(this,id);
//	printf("lo q devuelve la funcion set id%d\n",a);
//	a=employee_setSueldo(this, sueldo);
//	printf("lo q devuelve la funcion set sueldo%d\n",a);
//	a=	employee_setNombre(this, nombreStr);
//	printf("lo q devuelve la funcion set nombre%d\n",a);

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





//static int isValidNumero(int *numero)
//{
//	int retorno=-1;
//	if(numero<=9 && numero >=0)
//	{
//
//	}
//	return retorno;
//}


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
//				printf("id ingresado %d - id this %d\n",id,this->id);
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
//
///**
// * \brief Valida si el dato es alfanumerico y devuelve el exito o el facaso.
// * \param *resultado son las letras y/o numeros obtenidas
// * \param *mensaje es el mensaje a ser mostrado.
// * \param *mensajeError es el mensaje  de error
// * \param minimo es la cantidad de letras y/o numeros minimos que puede ingresar el usuario
// * \param maximo es la cantidad de letras y/o numeros maximos que puede ingresar el usuario
// * \param reintentos es la cantidad de veces que el usuario puede reintentar .
// * \return devuelve el -1 en caso de no ser letras y/o numeros, o el 0 en caso de exito.
// *
// */
//int esAlfaNumerico(char *resultado,
//			char *mensaje,
//			char *mensajeError,
//			int minimo,
//			int maximo,
//			int reintentos)
//{
//	int retorno =-1;
//	int i=0;
//	char buffer[4096];
//	strncpy(buffer,resultado,maximo+1);//strncpy(buffer,resultado,maximo+1);
//   	int cantidad;
//   	int contador=0;
//   	cantidad=strlen(buffer);
//   	while((buffer[0] != '\0' && buffer[i]== ' ') || (buffer[i] >= 'a' && buffer[i] <= 'z')|| (buffer[i] >= 'A' && buffer[i] <= 'Z')||(buffer[i] >= '0' && buffer[i] <= '9'))
//		  {
//			contador++;
//			i++;
//		   }
//if(cantidad==contador)
//	{
//	strncpy(resultado,buffer,maximo+1);
//	retorno = 0;
//	}
//else
//{
//	printf("%s",mensajeError);
//}
//	return retorno;
//}
//


