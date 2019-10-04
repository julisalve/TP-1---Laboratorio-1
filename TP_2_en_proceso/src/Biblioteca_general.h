
#ifndef BIBLIOTECA_GENERAL_H_
#define BIBLIOTECA_GENERAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TRUE 1
#define FALSE 0
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0


int findFirstEmptyPosition(Employee *list, int len);
int imprimirDatosEmpleadoPorId(Employee *list, int len, int id);
int modificacionEmpleadoPorIdCamposPuntuales(Employee *list, int len, int index);
float sumaSalariosYPromedio(Employee *list,int len,float *suma, int *contadorIsEmptyFalso);
int cantidadEmpleadosQueSuperanPromedioSalario(Employee *list,int len,float promedio);
int sortEmployeesUp(Employee *list, int len);
int sortEmployeesDown(Employee *list, int len);

int getNombre(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
int getApellido(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
float getFloat(float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos);
int getInt(int *resultado,
		  char *mensaje,
		  char *mensajeError,
		  int minimo,
		  int maximo,
		  int reintentos);
int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
char getChar (char *resultadoChar,
			  char *mensajeChar,
			  char *mensajeErrorChar,
			  char minimo,
			  char maximo,
			  int reintentos);

int esLetra(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);
int esSiONo(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);



int imprimirArrayEmpleadosCompleto(Employee*list, int len);


#endif /* BIBLIOTECA_GENERAL_H_ */
