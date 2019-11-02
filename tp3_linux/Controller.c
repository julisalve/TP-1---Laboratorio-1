#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
		FILE* pFile;
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			parser_EmployeeFromText(pFile,pArrayListEmployee);
			printf("\n Operacion exitosa.\n");
		}
		else
		{
			printf("ERROR: El archivo no pudo abrirse. \n");
		}
		fclose(pFile);
	 return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE * pFileBin;
    pFileBin = fopen(path,"rb");
    if(pFileBin != NULL)
    		{
    			parser_EmployeeFromBinary(pFileBin,pArrayListEmployee);
    			printf("\n Operacion exitosa.\n");
    		}
    		else
    		{
    			printf("ERROR: El archivo no pudo abrirse. \n");
    		}
    		fclose(pFileBin);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int id;
	char nombreStr[4096];
	char horasTrabajadasStr[4096];
	char sueldo [4096];

	Employee *nuevoEmpleado;
	if(pArrayListEmployee!=NULL)
	{
		id=buscarMaximoIdGenerado(pArrayListEmployee,id)+1;
		getString(nombreStr,"Ingrese un nombre \n","NO es un nombre valido \n",2,100,2);
		getString(horasTrabajadasStr,"Ingrese horas trabajadas \n","NO es un dato valido \n",1,1000,2);
		getString(sueldo,"Ingrese sueldo \n","NO es un sueldo valido \n",2,100000,2);
		nuevoEmpleado=employee_newParametros(id,)
				// no hay que escribirlo en el archivo despues?? o con add??


	}
	return 1;
}

int buscarMaximoIdGenerado(LinkedList *pArrayListEmployee,int *id)
{
	int retorno=-1;
	int maximoId=0;
	int i;
	if(pArrayListEmployee!=NULL)
	{
		for(i=0;)
		{
			if(pArrayListEmployee[i])
		}

	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

