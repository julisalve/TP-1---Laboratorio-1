#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/** \brief Pide espacio en memoria para un nuevo empleado
 *
 * \param
 * \return Puntero a Employee
 *
 */

Employee* employee_new()
{
	Employee *this;
	this= malloc(sizeof(Employee));
	if(this!=NULL)
	{
		this->id=0;
		this->horasTrabajadas=0;
		this->sueldo=0;
		strcpy(this->nombre,"");
	}
	else
	{
		printf("NO hay lugar libre \n");
	}
	return this;
}


/** \brief Setea parametros a un empleado nuevo
 *
 * \param idStr
 * \param nombreStr
 * \param horasTrabajadasStr
 * \param sueldoStr
 * \return el nuevo empleado con sus campos completos
 *
 */
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


/** \brief BOrra de la memoria a un empleado
 *
 * \param this
 * \return el espacio liberado
 *
 */
void employee_delete(Employee*this)
{
	free(this);
}


/** \brief Setea id a un empleado
 *
 * \param this
 * \param item es el id pasado
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_setId(Employee* this,int item)
{
	int retorno =-1;
	if(this!=NULL)
		{
			this->id=item;
			retorno=0;
		}

		return retorno;
}


/** \brief Obtiene id de un empleado
 *
 * \param this
 * \param id
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_getId(Employee* this,int* id)
{
	int retorno=-1;

	if(this!=NULL && id>=0)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}


/** \brief Setea nombre a un empleado
 *
 * \param this
 * \param nombre
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno =-1;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}


/** \brief Obtiene el nombre de un empleado
 *
 * \param this
 * \param nombre
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;

		if(this!=NULL && nombre!=NULL)
		{
			strcpy(nombre,this->nombre);
			retorno=0;
		}
		return retorno;
}


/** \brief Setea horas trabajadas a un empleado
 *
 * \param this
 * \param horasTrabajadas
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno =-1;
		if(this!=NULL)
		{
			this->horasTrabajadas=horasTrabajadas;
			retorno=0;
		}
		return retorno;
}


/** \brief Obtiene horas trabajads de un empleado
 *
 * \param this
 * \param horasTrabajadas
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;

	if(this!=NULL && horasTrabajadas>0)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}


/** \brief Setea sueldo a un empleado
 *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno =-1;
		if(this!=NULL )
		{
			this->sueldo=sueldo;
			retorno=0;
		}

		return retorno;
}



/** \brief Obtiene sueldo de un empleado
 *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;

	if(this!=NULL && sueldo>0)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}



/** \brief Busca un empleado por id
 *
 * \param pArrayListEmployee
 * \param id
 * \return devuelve NULL en caso de que no exista empleado con el id indicado, o develve el empleado en caso de exito
 *
 */
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

/** \brief Ordena ID de manera ascendente
 *
 * \param datoUno
 * \param datoDos
 * \return devuelve 1 en caso de orden ascendente, -1 en orden descendente, o -1 en caso contrario
 *
 */
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


/** \brief Ordena por NOmbre de manera ascendente
 *
 * \param datoUno
 * \param datoDos
 * \return devuelve 1 en caso de orden ascendente, -1 en orden descendente, o -1 en caso contrario
 *
 */
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

/** \brief Ordena horas trabajadas de manera ascendente
 *
 * \param datoUno
 * \param datoDos
 * \return devuelve 1 en caso de orden ascendente, -1 en orden descendente, o -1 en caso contrario
 *
 */
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



/** \brief Ordena sueldo de manera ascendente
 *
 * \param datoUno
 * \param datoDos
 * \return devuelve 1 en caso de orden ascendente, -1 en orden descendente, o -1 en caso contrario
 *
 */
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
