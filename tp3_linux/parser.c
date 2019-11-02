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
		char id[4096];
		char nombre[4096];
		char horasTrabajadas[4096];
		char sueldo[4096];
		int r;
		int flagPrimerRenglonDescripciones=0;
		Employee *nuevoEmpleado;

		if(pArrayListEmployee!=NULL)
		{
		do{
			r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
							id,
							nombre,
							horasTrabajadas,
							sueldo);
			if(flagPrimerRenglonDescripciones==0)
			{
				flagPrimerRenglonDescripciones=1;
				continue;
			}
			else if (flagPrimerRenglonDescripciones==1 && r==4)
			{
			nuevoEmpleado= employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			if(nuevoEmpleado!=NULL)
			{
			ll_add(pArrayListEmployee,nuevoEmpleado);
			retorno=EXIT_SUCCESS;
			printf("Carga exitosa. \n");
			}
			else
			{
				printf("Error en la carga\n");
			}
			}
		}while(!feof(pFile));
		fclose(pFile);
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
	int flagPrimerRenglonDescripciones=0;
	Employee *nuevoEmpleado;
	if(pArrayListEmployee!=NULL)
	{
		nuevoEmpleado=employee_new();
		if(nuevoEmpleado!=NULL)
		{
			do{
				r=fread(nuevoEmpleado,sizeof(Employee),1,pFile);
				if( flagPrimerRenglonDescripciones==0)
				{
					flagPrimerRenglonDescripciones=1;
					continue;
				}
				else if (flagPrimerRenglonDescripciones==1 && r==1)
				{
					ll_add(pArrayListEmployee,nuevoEmpleado);
					retorno=EXIT_SUCCESS;
					printf("Carga exitosa. \n");
				}
			}while(!feof(pFile));
		}
		else
		{
			printf("Error en la carga\n");
		}
		fclose(pFile);
	}
	return 1;
}
