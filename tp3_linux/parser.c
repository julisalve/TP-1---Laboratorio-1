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
	if(pFile!=NULL)
//	if(pArrayListEmployee!=NULL)
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
//			if(r==4)
			{
				nuevoEmpleado= employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			if(nuevoEmpleado!=NULL)
				{
					ll_add(pArrayListEmployee,nuevoEmpleado);
					retorno=EXIT_SUCCESS;
				}
//				else
//				{
//					printf("Error en la carga\n");
//				}
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
	if(pArrayListEmployee!=NULL)
	{
		nuevoEmpleado=employee_new();
		fread(nuevoEmpleado,sizeof(Employee),1,pFile);
		if(nuevoEmpleado!=NULL)
		{
			do{
				r=fread(nuevoEmpleado,sizeof(Employee),1,pFile);
				if (r==1)
				{
					ll_add(pArrayListEmployee,nuevoEmpleado);
					retorno=EXIT_SUCCESS;
				}
			}while(!feof(pFile));
		}
		else
		{
			printf("Error en la carga\n");
		}
		if(r==1)
		{
			printf("Carga exitosa. \n");
		}
		fclose(pFile);
	}
	return retorno;
}
