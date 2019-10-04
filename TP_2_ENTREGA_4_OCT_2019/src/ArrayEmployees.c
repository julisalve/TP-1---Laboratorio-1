
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "ArrayEmployees.h"
#include"Biblioteca_general.h"


/**\brief To indicate that all position in the array are empty,
 * 		  this function put the flag (isEmpty) in TRUE in all
 * 		  position of the array
 *
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \return int REturn (EXIT_ERROR -1) if Error [INvalid length or NULL pointer] - (EXIT_SUCCESS 0) if OK
 *
 */

int initEmployees(Employee *list, int len)
{
	int i;
	int retorno = EXIT_ERROR;
	if(list != NULL && len > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=TRUE;
		}
	}
	return retorno;
}



/**\brief add in a existing list of employees the values received as parameters
 * 		  in the first empty position
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \param id int
 * \param name [] char
 * \param lastName [] char
 * \param salary float
 * \param sector int
 * \return int Return (EXIT_EROR -1) if Error [INvalid length or NULL pointer or without free space] - (EXIT_SUCCESS 0) if OK
 *
 */

int addEmployee(Employee *list, int len,int id, char name [], char lastName [], float salary, int sector)
{
	int retorno = EXIT_ERROR;
	int i;
	i = findFirstEmptyPosition(list,len);
	if(list != NULL && len > 0 && i!=EXIT_ERROR)
	{
		list[i].id = id;
		strncpy(list[i].name,name,50);
		strncpy(list[i].lastName,lastName,50);
		list[i].salary = salary;
		list[i].sector = sector;
		list[i].isEmpty= FALSE;
		retorno = EXIT_SUCCESS;
	}else
	{
		printf("No hay lugares libres");
	}
	return retorno;
}




/**\brief find an Employee by Id and returns the index position in array
 *
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \param id int
 * \return int Return (EXIT_ERROR -1) if Error [Invalid length or NULL pointer received or employee not found] or (i) employee index position if OK.
 *
 */


int findEmployeeById(Employee *list, int len, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty!= TRUE && id==list[i].id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



/**\brief Remove an employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \param id int
 * \return int Return (EXIT_ERROR -1) if Error [Invalid length or NULL pointer or employee not found] or (EXIT_SUCCESS 0) if OK.
 *
 */

int removeEmployee(Employee *list, int len,int id)
{
	int retorno =EXIT_ERROR;
	int posicionEmpleado= findEmployeeById(list, len,id);

	if(list != NULL && len > 0 && posicionEmpleado >=0)
	{
		list[posicionEmpleado].isEmpty= TRUE;
		retorno=EXIT_SUCCESS;
	}
	return retorno;
}


/**\brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \param order int [1]indicate UP - [0] indicate DOWN
 * \return int Return (EXIT_ERROR -1) if Error [Invalid length or NULL pointer] or (EXIT_SUCCESS 0) if OK.
 *
 */
int sortEmployees(Employee *list, int len, int order)
{

	int retorno = EXIT_ERROR;
	if(list != NULL && len>0)
	{
		retorno = 0;
		if(order==1)
		{
			sortEmployeesUp(list, len);
		}
		else if(order==2)
		{
			sortEmployeesDown(list, len);
		}
	}
	return retorno;
}

/**\brief print the content of employees array
 *
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \return int Return (EXIT_ERROR -1) if Error [Invalid length or NULL pointer] or (EXIT_SUCCESS 0) if OK.
 *
 */
int printfEmployees(Employee*list, int len)
{
	int i;
	int retorno = EXIT_ERROR;
	if(list != NULL && len>0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty== FALSE)
			{
				printf("Id: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}

		}
	}
	return retorno;
}


