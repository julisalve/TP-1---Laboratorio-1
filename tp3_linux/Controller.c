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
	id=buscarMaximoIdGenerado(pArrayListEmployee)+1;
		sprintf(idStr,"%d",id);
		getString(nombreStr,"Ingrese un nombre \n","NO es un nombre valido \n",2,100,2);
		getString(horasTrabajadasStr,"Ingrese horas trabajadas \n","NO es un dato valido \n",1,1000,2);
		getString(sueldo,"Ingrese sueldo \n","NO es un sueldo valido \n",1,4096,2);
		nuevoEmpleado=employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldo);
		ll_add(pArrayListEmployee,nuevoEmpleado);
		printf("Alta exitosa: Id str %s \n Horas Trabajdas %s \n, Sueldos %s,\n",idStr,horasTrabajadasStr,sueldo);
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
	Employee *this;
	int id;
	int horasTrabajadas;
	int sueldo;
	int nuevasHorasTrabajadas;
	int nuevoSueldo;
	char bufferNombre[50];
	char nombre[50];
	int modificar = 0;
	int opcion;
	char respuesta[3];
	char continuarSubMenuModificar = 's';
	int i;
	getInt(&id,"Ingrese ID que desea modificar","NO es un id valido",1,1000000000,2);
	for(i=0; i<ll_len(pArrayListEmployee);i++)
	{
		this = (Employee*) ll_get(pArrayListEmployee, i);
		while(this->id != id)
		{
			getInt(&id,"No existe el id ingresado. Seleccione un ID\n","NO es un id valido\n",1,1000000000,2);
		}
		do
		{
			printf("Esta a punto de modificar el id %d - Nombre %s - Horas Trabajadas %d - Sueldo %d \n",this->id, this->nombre, this->horasTrabajadas, this->sueldo);
			getInt(&opcion,"Indique la opcion que desea modificar: 1) Nombre, 2) HOras Trabajadas, 3)Sueldo, 4)Volver al menu principal \n","No es una opcion valida",1,4,2);
switch(opcion)
{
case 1:
	employee_getNombre(this,nombre);
	getString(bufferNombre,"Ingrese un nombre\n","NO es un nombre valido \n",1,50,2);
}

		}while(strncmp(respuesta,"si",3)==0);



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

