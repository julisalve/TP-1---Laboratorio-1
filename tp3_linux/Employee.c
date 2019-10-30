#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidNumero(char *item);
static int isValidLetra(char *item);

Employee* employee_new()
{
	return malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee *retorno=NULL;
	Employee* this;
	this= new_Employee();
			if(this!=NULL &&
					employee_setId(this,idStr)==0 &&
					employee_setNombre(this, nombreStr)==0 &&
					employee_setHorasTrabajadas(this, horasTrabajadasStr)==0 &&
					employee_setSueldo(this, sueldoStr)==0)
			{
					retorno=this;
			}
			else
			{
				employee_delete(this);
			}
	return *retorno;
}


void employee_delete(Employee*this)
{
	free(this);
}


int employee_setId(Employee* this,int id)
{
	int retorno =-1;
		if(this!=NULL && isValidNumero(id)) //hacer la funcion de validar el numero positivo y ademas pasar el id
		{
			this->id=id;
			retorno=0;
		}

		return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno=1;

	if(this!=NULL && id>=0)
	{
		id=this->id;
		retorno=0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno =-1;
	if(this!=NULL && isValidLetra(nombre)) //hacer la funcion de validar el numero positivo y ademas pasar el id
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
		if(this!=NULL && isValidNumero(horasTrabajadas)) //hacer la funcion de validar el numero positivo y ademas pasar el id
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
		horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno =-1;
		if(this!=NULL && isValidNumero(sueldo)) //hacer la funcion de validar el numero positivo y ademas pasar el id
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
		sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}





static int isValidNumero(char *item)
{
	int retorno=-1;
	return retorno;
}


static int isValidLetra(char *item)
{
	int retorno=-1;
	return retorno;
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
