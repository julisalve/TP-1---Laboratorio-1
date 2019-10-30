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

	pFile= fopen("data.csv","r"); //va la rta del archivo absoluta, describe todos el pad, desde el drirectorio raiz. RUTA RELATIVA poner el nombre del archivo
	char id[4096];
	char nombre[4096];
	char horasTrabajadas[4096];
	char sueldo [4096];

	if(pFile!=NULL)
	{
		printf("archivo abierto de manera exitosa \n");
		while(!feof(pFile)); // devuelve verdadero si llego al final
		{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,horasTrabajadas,sueldo); //2do es la mascara de cmo quiero leerlo. %S lee hasta ssalto de linea, tomaria hasta la primer linea no mas. [a-z] esta es la acetacion. [^] NO acepta. ESTO ES PARSEAR.. aCA DIGO QUIEOR CUALQUIER COSA MENOS UNA COMA.
		//flag primer lectura que no se cargue en ningun elemento porque tiene el titulo.
		printf("%s \n");
		}
	}
	fclose(pFile);
    return 1;
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

    return 1;
}
