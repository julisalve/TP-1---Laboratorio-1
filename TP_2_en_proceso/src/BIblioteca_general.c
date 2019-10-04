#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Biblioteca_general.h"



/**\brief find the first empty position and returns the index position in array.
 *
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \return int Return (EXIT_ERROR -1) if Error [Invalid length or NULL pointer]- (i) index of the first empty position if OK.
 *
 */

int findFirstEmptyPosition(Employee *list, int len)
{
	int retorno = EXIT_ERROR;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty ==TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/**\brief Imprime datos de un id en particular
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param id es el id solicitado
 * \return int DEvuelve(EXIT_ERROR -1) en caso de que el array sea nulo o sea invalido el tamaño o devuelve la posicion del id en caso de exito
 *
 */
int imprimirDatosEmpleadoPorId(Employee *list, int len, int id)
{
	int retorno =EXIT_ERROR;
	int indice =findEmployeeById(list,len, id);
	if(list != NULL && len > 0)
	{
		if(indice>=0)
		{
			retorno = indice;
			printf("Id: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d \n",list[indice].id,list[indice].name,list[indice].lastName,list[indice].salary,list[indice].sector);
		}
	}
	return retorno;
}


/**\brief Modifica el dato que se desee de los campos de la estructura del srray
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param index posicion del array
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o EXIT SUCCESS (0) en caso de exito
 *
 */
int modificacionEmpleadoPorIdCamposPuntuales(Employee *list, int len, int index)
{
	int retorno =EXIT_ERROR;
	char datoAModificar;
	Employee bEmpleado;


	if(getChar(&datoAModificar,
			"Seleccione dato a modificar: a)nombre, b)apellido, c)salario d) sector \n",
			"NO es una opcion valida \n",
			'a',
			'z',
			2)!=0)
	{
		printf("ERROR");
	}
	else
	{
		switch(datoAModificar)
		{
		case 'a':

			if(getNombre(bEmpleado.name,
					"Ingrese el nombre \n",
					"NO es un nombre valido \n",
					2,
					16,
					2)!=0)
			{
				printf("ERROR \n");
			}
			else
			{
				strncpy(list[index].name,bEmpleado.name,50);
				retorno =EXIT_SUCCESS;
			}
			break;
		case 'b':

			if(getApellido(bEmpleado.lastName,
					"Ingrese el apellido \n",
					"NO es un apellido valido \n",
					2,
					16,
					2)!=0)
			{
				printf ("Error\n");
			}
			else
			{
				strncpy(list[index].lastName,bEmpleado.lastName,50);
				retorno =EXIT_SUCCESS;
			}

			break;
		case 'c':

			if(getFloat(&bEmpleado.salary,
					"Ingrese el salario \n",
					"NO es un dato valido \n",
					0.01,
					1000000.0,
					2)!=0)
			{
				printf ("Error\n");
			}
			else
			{
				list[index].salary=bEmpleado.salary;
				retorno =EXIT_SUCCESS;
			}

			break;

		case 'd':

			if(getInt(&bEmpleado.sector,
					"Ingrese el sector 1) produccion, 2) ventas, 3) administracion \n",
					"NO es un sector valido\n",
					1,
					3,
					2)!=0)
			{
				printf ("Error\n");
			}
			else
			{
				list[index].sector=bEmpleado.sector;
				retorno =EXIT_SUCCESS;
			}

			break;

		default:
			printf("Error, opcion invalida \n");
			break;
		}

	}

	return retorno;

}



/**\brief Suma flotantes y tiene un contador de lugares ocupados para poder luego sacar promedio
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param float *suma
 * \param int *contadorIsEmptyFalso
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o EXIT SUCCESS (0) en caso de exito
 *
 */
float sumaSalariosYPromedio(Employee *list,int len,float *suma, int *contadorIsEmptyFalso)
{
	int retorno=EXIT_ERROR;
	int i;
	*suma=0;
	*contadorIsEmptyFalso=0;
	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty== FALSE)
			{
				*suma=*suma+list[i].salary;
				*contadorIsEmptyFalso=*contadorIsEmptyFalso+1;
			}
		}retorno=EXIT_SUCCESS;
	}
	return retorno;
}



/**\brief Calcula cantidad de empleados que superan el promedio de los salarios
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param float promedio
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o el promedio
 *
 */
int cantidadEmpleadosQueSuperanPromedioSalario(Employee *list,int len,float promedio)
{
	int retorno=EXIT_ERROR;
	int i;
	int cantidadEmpleadosQueSuperanPromedioSalario=0;
	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].salary>promedio)
			{
				cantidadEmpleadosQueSuperanPromedioSalario++;
			}
		}retorno=cantidadEmpleadosQueSuperanPromedioSalario;
	}
	return retorno;

}



/**\brief Ordena un array de empleados de manera ascendente
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o (EXIT_SUCCESS 0) en caso de exito
 *
 */
int sortEmployeesUp(Employee *list, int len)
{
	int i;
	int retorno = EXIT_ERROR;
	Employee bEmpleados;
	int fSwap;
	if(list != NULL && len>0)
	{
		retorno = EXIT_SUCCESS;
		do
		{
			fSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(strncmp(list[i].lastName,list[i+1].lastName,50)>0)
				{
					fSwap = 1;
					bEmpleados=list[i];
					list[i]=list[i+1];
					list[i+1]=bEmpleados;
				}
				else if(strncmp(list[i].lastName,list[i+1].lastName,50)==0)

				{
					if(list[i].sector>list[i+1].sector)
					{
						fSwap = 1;
						bEmpleados=list[i];
						list[i]=list[i+1];
						list[i+1]=bEmpleados;
					}
					else if(list[i].sector==list[i+1].sector)
					{
						if(strncmp(list[i].name,list[i+1].name,50)>0)
						{
							fSwap = 1;
							bEmpleados=list[i];
							list[i]=list[i+1];
							list[i+1]=bEmpleados;
						}
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}

/**\brief Ordena un array de empleados de manera descendente
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o (EXIT_SUCCESS 0) en caso de exito
 *
 */
int sortEmployeesDown(Employee *list, int len)
{
	int i;
	int retorno = EXIT_ERROR;
	Employee bEmpleados;
	int fSwap;
	if(list != NULL && len>0)
	{
		retorno = EXIT_SUCCESS;

		do
		{
			fSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(strncmp(list[i].lastName,list[i+1].lastName,50)<0)
				{
					fSwap = 1;
					bEmpleados=list[i];
					list[i]=list[i+1];
					list[i+1]=bEmpleados;
				}
				else if(strncmp(list[i].lastName,list[i+1].lastName,50)==0)

				{
					if(list[i].sector<list[i+1].sector)
					{
						fSwap = 1;
						bEmpleados=list[i];
						list[i]=list[i+1];
						list[i+1]=bEmpleados;
					}
					else if(list[i].sector==list[i+1].sector)
					{
						if(strncmp(list[i].name,list[i+1].name,50)<0)
						{
							fSwap = 1;
							bEmpleados=list[i];
							list[i]=list[i+1];
							list[i+1]=bEmpleados;
						}
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}



/**\brief Obtiene un nombre compuesto por letras
 *
 * \param resultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o (EXIT_SUCCESS 0) en caso de exito
 *
 */
int getNombre(char *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];
	reintentos++;
	do
	{
		getString(buffer,
				mensaje,
				mensajeError,
				minimo,
				maximo,
				reintentos);
		reintentos--;
	}while(esLetra(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)!=0 && reintentos>=0);

	if(esLetra(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)==0)
	{
		strncpy(resultado,buffer,maximo+1);
		retorno = 0;}
	return retorno;
}

/**\brief Obtiene un apellido compuesto por letras
 *
 * \param resultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o (EXIT_SUCCESS 0) en caso de exito
 *
 */
int getApellido(char *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno=-1;
	char buffer[4096];
	reintentos++;
	do
	{
		getString(buffer,

				mensaje,
				mensajeError,
				minimo,
				maximo,
				reintentos);
		reintentos--;
	}while(esLetra(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)!=0 && reintentos >=0);

	if(esLetra(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)==0)
	{
		strncpy(resultado,buffer,maximo+1);
		retorno = 0;}
	return retorno;
}


/**
 * \brief Solicita un flotante al usuario y devuelve el exito o el facaso.
 * \param *resultado es el flotante obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el flotante.
 * \param *mensajeError es el mensaje  de error
 * \param minimo es el numero minimo que puede ingresar el usuario
 * \param maximo es el numero maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el flotante.
 * \return devuelve el -1 en caso de no haber podido obtener el numero, o el 0 en caso de exito.
 *
 */

float getFloat(float *resultado,
		char *mensaje,
		char *mensajeError,
		float minimo,
		float maximo,
		int reintentos)
{
	int retorno= EXIT_ERROR;
	float buffer;
	if(resultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			maximo>minimo &&
			reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno =0; //EXIT_SUCCESS;
					*resultado=buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Solicita un entero al usuario y devuelve el exito o el facaso.
 * \param *resultado es el entero obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el entero
 * \param *mensajeError es el mensaje  de error
 * \param minimo es el numero minimo que puede ingresar el usuario
 * \param maximo es el numero maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el entero.
 * \return devuelve el -1 en caso de no haber podido obtener el numero, o el 0 en caso de exito.
 *
 */
int getInt(int *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(resultado !=NULL &&
			mensaje !=NULL &&
			mensajeError != NULL &&
			minimo<maximo &&
			reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);//fflush(stdin); //en windows funciona __fflush para limpiar
			if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
			{
				retorno =EXIT_SUCCESS;
				*resultado=buffer; //caso de exito
				break; //de aca salgo del while y evito poner el else
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}return retorno;
}

/**
 * \brief Solicita una cadena de caracteres al usuario y devuelve el exito o el facaso.
 * \param *resultado es el string obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el string
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad minima de carateres que puede tener el string
 * \param maximo es la cantidad maxima de carateres que puede tener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el string.
 * \return devuelve el -1 en caso de no haber podido obtener el string, o el 0 en caso de exito.
 *
 */

int getString(char *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];
	if(resultado!=NULL &&
			mensaje !=NULL &&
			mensajeError !=NULL &&
			maximo>minimo &&
			reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			__fpurge(stdin); //fflush(stdin) EN WINDOWS . limpia el teclado
			fgets(buffer,sizeof(buffer),stdin); //toma lo del teclado de manera segura
			buffer[strlen(buffer)-1]='\0'; //en buffer se toma hasta lo anterior en \0
			if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
			{
				strncpy(resultado,buffer,maximo+1);
				retorno =EXIT_SUCCESS;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Solicita un dato char al usuario y devuelve el exito o el facaso.
 * \param *resultadoChar es el char obtenido
 * \param *mensajeChar es el mensaje a ser mostrado para solicitar el char
 * \param *mensajeErrorChar es el mensaje  de error
 * \param minimo es el char minimo que puede ingresar el usuario
 * \param maximo es el char maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el char.
 * \return devuelve el -1 en caso de no haber podido obtener el dato, o el 0 en caso de exito.
 *
 */
char getChar (char *resultadoChar,
		char *mensajeChar,
		char *mensajeErrorChar,
		char minimo,
		char maximo,
		int reintentos)
{
	int retorno = EXIT_ERROR;
	char bufferChar;
	if(resultadoChar != NULL &&
			mensajeChar != NULL &&
			mensajeErrorChar != NULL &&
			minimo<maximo &&
			reintentos >=0)
	{
		do
		{
			printf("%s",mensajeChar);
			__fpurge(stdin);//fflush(stdin);
			if(scanf("%c",&bufferChar)==1)
			{
				if(bufferChar >= minimo && bufferChar <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultadoChar = bufferChar;
					break;
				}
			}
			printf("%s", mensajeErrorChar);
			reintentos--;
		}while (reintentos >=0 );
	}
	return retorno;
}

/**
 * \brief VAlida que todos los datos de un aray sean letras
 * \param *resultado es el char obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el char
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cant minima de caracteres que puede tener el string
 * \param maximo es el cant maxima de caracteres que puede tener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar la cargar.
 * \return devuelve el -1 en caso de que no sean todos los caracteres letras o el 0 en caso de exito.
 *
 */
int esLetra(char *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno =EXIT_ERROR;
	int i=0;
	char buffer[4096];
	strncpy(buffer,resultado,maximo+1);
	int cantidad;
	int contador=0;
	cantidad=strlen(buffer);
	while((buffer[i] != '\0' && buffer[i]== ' ') || (buffer[i] >= 'a' && buffer[i] <= 'z')|| (buffer[i] >= 'A' && buffer[i] <= 'Z'))
	{
		contador++;
		i++;
	}
	if(cantidad==contador && reintentos>=0)
	{
		strncpy(resultado,buffer,maximo+1);
		retorno = EXIT_SUCCESS;
	}
	else
	{
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Solicita una respuesta la cual puede ser si o no
 * \param *resultado es el string obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el string
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad minima de caracteres que puede tener el string
 * \param maximo es la cantidad maxima de caracteres que puede tener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el string.
 * \return devuelve el -1 en caso de no haber podido obtener el dato, o el 0 en caso de exito.
 *
 */
int esSiONo(char *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno =EXIT_ERROR;
	char buffer[4096];
	do
	{	getString(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos);

	if(strncmp(buffer,"si",maximo+1)==0 || strncmp(buffer,"no",maximo+1)==0)
	{
		strncpy(resultado,buffer,maximo+1);
		retorno = EXIT_SUCCESS;
		break;
	}
	else
	{
		printf("%s",mensajeError);
		reintentos--;
	}
	}while(reintentos>=0);
	return retorno;
}




/**
 * \brief IMprime de manera completa el array
 * \param *list array
 * \param len tamaño del array
 * \return devuelve el -1 en caso de que el array sea nulo o el tamaño invalido, o devuelve el 0 en caso de exito.
 *
 */
int imprimirArrayEmpleadosCompleto(Employee*list, int len){
	int i;
	int retorno = EXIT_ERROR;
	if(list != NULL && len>0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			printf("Estado : %d - Id: %d - Nombre: %s - Apellido: %s - SalarioDNI: %.2f - Sector: %d \n",list[i].isEmpty,list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);

		}
	}
	return retorno;
}
