#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)// recibe un elemento, lo construye y lo agrega al array.
{
	int retorno =-1;
	int r;
	char id[4096];
	char nombre[4096];
	char horasTrabajadas[4096];
	char sueldo[4096];
	int flagPrimerRenglon=0;
	Employee *nuevoEmpleado;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
					id,
					nombre,
					horasTrabajadas,
					sueldo);
			if(flagPrimerRenglon==0)
			{
				flagPrimerRenglon=1;
				continue;
			}
			else if(flagPrimerRenglon==1 && r==4)
			{
				nuevoEmpleado= employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(nuevoEmpleado!=NULL)
				{
					ll_add(pArrayListEmployee,nuevoEmpleado);
					retorno=EXIT_SUCCESS;
				}
			}
		}
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int r;
	Employee *nuevoEmpleado;
	int flagPrimerRenglon=0;
	if(pArrayListEmployee!=NULL && pFile!=NULL)
	{
		nuevoEmpleado=employee_new();
		if(nuevoEmpleado!=NULL)
		{
			do{
				r=fread(nuevoEmpleado,sizeof(Employee),1,pFile);
				if(flagPrimerRenglon==0)
				{
					flagPrimerRenglon=1;
					continue;
				}
				if (r==1 && flagPrimerRenglon==1)
				{
					ll_add(pArrayListEmployee,nuevoEmpleado);
					retorno=EXIT_SUCCESS;
				}
			}while(!feof(pFile));
		}
	}
	return retorno;
}
