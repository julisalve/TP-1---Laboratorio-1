#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "general.h"

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
			fclose(pFile);
		}
		else
		{
			printf("ERROR: El archivo no pudo abrirse. \n");
		}

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
    			fclose(pFileBin);
    		}
    		else
    		{
    			printf("ERROR: El archivo no pudo abrirse. \n");
    		}

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
	char idStr[4096];
	char nombreStr[4096];
	char horasTrabajadasStr[4096];
	char sueldo [4096];

	Employee *nuevoEmpleado;
	if(pArrayListEmployee!=NULL)
	{
	id=buscarMaximoIdGenerado(pArrayListEmployee);
	printf("id %d \n",id);
	sprintf(idStr,"%d",id);
		getString(nombreStr,"Ingrese un nombre \n","NO es un nombre valido \n",2,100,2);

		printf("nombre %s",nombreStr);
		getString(horasTrabajadasStr,"Ingrese horas trabajadas \n","NO es un dato valido \n",1,1000,2);

		printf("hola 1 horas trabajadas %s",horasTrabajadasStr);
		getString(sueldo,"Ingrese sueldo \n","NO es un sueldo valido \n",2,1000000,2);

		printf("hola 2  sueldo %s",sueldo);
		printf("id str %s , horas trabajdas %s , sueldos str %s,\n",idStr,horasTrabajadasStr,sueldo);

		nuevoEmpleado=employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldo);
		ll_add(pArrayListEmployee,nuevoEmpleado);
	}
	return 1;
}

int buscarMaximoIdGenerado(LinkedList *pArrayListEmployee)
{
	int retorno=-1;
	int maximoId=0;
	int i;
	Employee *pEmpleado;
	if(pArrayListEmployee!=NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee); i++)
	    {
	        pEmpleado = ll_get(pArrayListEmployee, i);
	        if(pEmpleado->id>maximoId)
	        {
	        	maximoId=pEmpleado->id;
	        }

		}retorno=maximoId;
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
//	 Employee *this;
//	    int idEmpleado, horasTrabajadas, sueldo;
//	    int nuevasHorasTrabajadas, nuevoSueldo;
//	    char nombreAux[51], nombre[51];
//	    int modificar = 0;
//	    int opcionMenu= 0;
//	    char confirma = 0;
//	    char continuarSubMenuModificar = 's';
//	    int i;
//	    printf("\tMODIFICAR EMPLEADO\n");
//	    idEmpleado = getIntOnly("Ingrese ID: ");
//	    for(i=0; i<ll_len(pArrayListEmployee) ; i++)
//	    {
//	        this = (Employee*) ll_get(pArrayListEmployee, i);
//	        if(this->id == idEmpleado)
//	        {
//
//	            modificar = 1;
//	            break;
//	        }
//
//	    }
//
//	    if(modificar == 1)
//	    {
//	        do
//	        {
//	            system("cls");
//	            printf("\t MENU MODIFICAR\n\n");
//	            printf("\n  Id  -  Nombre  -   Horas  - Sueldo ");
//	            printf("\n%4d%10s%10d    %8d\n\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
//
//	            printf("1. Modificar nombre\n");
//	            printf("2. Modificar horas trabajadas\n");
//	            printf("3. Modificar sueldo\n");
//	            printf("4. Regresar al menu anterior\n\n");
//
//	            opcionMenu = getIntOnly("Ingrese una opcion: \n");
//
//	            switch(opcionMenu)
//	            {
//	            case 1:
//	                employee_getNombre(this, nombre);
//	                getValidStringRango("\nIngrese nombre: ","\nError. Solo se admiten letras",nombreAux,50);
//	                confirma = getValidChar("\nRealmente quiere modificarlo?: (s/n)","\nReingrese", 's','n');
//
//	                if(confirma == 's')
//	                {
//	                    employee_setNombre(this,nombreAux);
//	                    printf("\nEl nombre ha sido modificado");
//	                }
//	                else
//	                {
//	                    printf("\nLa modificacion ha sido cancelada");
//	                }
//
//	                system("pause");
//
//	                break;
//
//	            case 2:
//	                employee_getHorasTrabajadas(this, &horasTrabajadas);
//	                nuevasHorasTrabajadas =getValidInt("\nIngrese horas trabajadas: ", "\nError. Solo se permiten numeros");
//	                confirma = getValidChar("\nRealmente quiere modificarlo?: (s/n) ","\nReingrese", 's','n');
//
//	                if(confirma == 's')
//	                {
//	                    employee_setHorasTrabajadas(this,nuevasHorasTrabajadas);
//	                    printf("\nLas horas trabajadas han sido modificado");
//	                }
//	                else
//	                {
//	                    printf("\nLa modificacion ha sido cancelada");
//	                }
//
//	                system("pause");
//
//	                break;
//
//	            case 3:
//	                nuevoSueldo =getValidInt("\nIngrese el nuevo sueldo: ", "\nError. Solo se permiten numeros");
//	                employee_getSueldo(this,&sueldo);
//	                confirma = getValidChar("\nRealmente quiere modificarlo?: (s/n) ","\nReingrese", 's','n');
//
//	                if(confirma == 's')
//	                {
//	                    employee_setSueldo(this,nuevoSueldo);
//	                    printf("\nEl sueldo ha sido modificado");
//	                }
//	                else
//	                {
//	                    printf("\nLa modificacion ha sido cancelada");
//	                }
//                break;
//	            case 4:
//	                continuarSubMenuModificar = 'n';
//	                break;
//	            }
//	        }
//	        while(continuarSubMenuModificar == 's');
//	    }
//	    return 1;
//
//
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

    Employee *pEmpleado;
    int i;
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        pEmpleado = ll_get(pArrayListEmployee, i);
        printf("%4d %15s %4d %6d\n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas, pEmpleado->sueldo);
    }
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
//	FILE *pFile;
//	Employee *nuevoEmpleado;
//
//	if(pArrayListEmployee!=NULL)
//	{
//	fopen(path,"w");
//	fwrite(,sizeof(Employee),1,pFile);
//	}

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

