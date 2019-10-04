#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Biblioteca_general.h"

#define QTY_EMPLEADOS 1000

static int generarId();

int main (void)
{
	int retorno;
	int opcion;
	int flagOpcionUno=0;
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	char respuesta [3];
	char confirmacion[3];
	Employee aEmpleados[QTY_EMPLEADOS];
	int posicionEmpleadoAModificar;
	float sumaSalario;
	int contadorParaPromedio;
	float promedioSalario;
	int empleadosQueSuperanPromedioSalario;
	int ordenamiento;
	initEmployees(aEmpleados, QTY_EMPLEADOS);
	do
	{
		system("clear");
		printf("1) Alta empleado \n");
		printf("2) Modificacion de datos \n");
		printf("3) Baja empleado\n");
		printf("4) Informes \n");
		printf("5) Salir \n");
		getInt(&opcion,
				"Elija una opcion \n",
				"NO es una opcion valida\n",
				1,
				5,
				2);
		switch(opcion)
		{
		case 1:
			id=generarId();
			if(getNombre(nombre,
					"Ingrese el nombre \n",
					"NO es un nombre valido\n",
					2,
					20,
					2)!=0)
			{
				printf("Error \n");
				break;
			}
			if(getApellido(apellido,
					"Ingrese apellido \n",
					"NO es un apellido valido \n",
					2,
					20,
					2)!=0)
			{
				printf("Error \n");
				break;
			}
			if(getFloat(&salario,
					"Ingrese salario \n",
					"NO es un dato valido \n",
					0.01,
					100000000000.00,
					2)!=0)
			{
				printf("Error \n");
				break;
			}
			if(getInt(&sector,
					"Ingrese un sector: 1) produccion, 2) ventas, 3) administracion \n",
					"NO es un sector valido\n",
					1,
					3,
					2)!=0)
			{
				printf("Error \n");
				break;
			}
			addEmployee(aEmpleados, QTY_EMPLEADOS,id,nombre,apellido,salario,sector);
			flagOpcionUno=1;
			printf("ALTA REALIZADA CON EXITO.\n");
			break;

		case 2:
			if (flagOpcionUno!=1)
			{
				printf("Error, primero debe dar de alta a un empleado \n");
			}
			else
			{
				printfEmployees(aEmpleados,QTY_EMPLEADOS);
				getInt(&id,
						"Seleccione un ID para modificar\n",
						"NO es un ID valido",
						0,
						1001,
						2);
				while(findEmployeeById(aEmpleados, QTY_EMPLEADOS, id)==-1)
				{
					getInt(&id,
							"NO existe el ID. Seleccione un ID valido\n",
							"NO es un ID valido",
							0,
							1001,
							2);
				}
				imprimirDatosEmpleadoPorId(aEmpleados,QTY_EMPLEADOS, id);
				posicionEmpleadoAModificar=findEmployeeById(aEmpleados,QTY_EMPLEADOS,id);
				esSiONo(confirmacion,
						"¿Desea modificar este id? si o no? \n",
						"NO es una respuesta valida \n",
						2,
						4,
						2);
				if(strncmp(confirmacion,"si",4)==0)
				{
					do
					{
						modificacionEmpleadoPorIdCamposPuntuales(aEmpleados, QTY_EMPLEADOS, posicionEmpleadoAModificar);
						printf("MODIFICACION REALIZADA CON EXITO.\n");
						esSiONo(respuesta,
								"¿Desea seguir modificando este id? si o no? \n",
								"NO es una respuesta valida \n",
								2,
								4,
								2);

					}while(strncmp(respuesta,"si",3)==0);
				}}

			break;

		case 3:
			if (flagOpcionUno!=1)
			{
				printf("Error, primero debe dar de alta a un empleado \n");
			}
			else
			{
				printfEmployees(aEmpleados,10);
				if(getInt(&id,
						"Seleccione un ID para dar de baja\n",
						"NO es un ID valido",
						0,
						1000,
						2)!=0)
				{
					printf("Error \n");
					break;
				}
				while(findEmployeeById(aEmpleados, QTY_EMPLEADOS, id)==-1)
				{
					getInt(&id,
							"NO existe el ID ELEGIDO. Seleccione otro.\n",
							"NO es un ID valido",
							0,
							1000,
							2);
				}
				imprimirDatosEmpleadoPorId(aEmpleados,QTY_EMPLEADOS, id);
				if(esSiONo(confirmacion,
						"¿Desea dar la baja si o no? \n",
						"No es una respuesta valida \n",
						2,
						4,
						2)!=0)
				{
					printf("Error \n");
					break;
				}
				if(strncmp(confirmacion,"si",4)==0)
				{
					removeEmployee(aEmpleados,QTY_EMPLEADOS,id);
					printf("BAJA REALIZADA CON EXITO.\n");
				}
				else
				{
					break;
				}
			}
			break;

		case 4:
			if (flagOpcionUno!=1)
			{
				printf("Error, primero debe dar de alta a un empleado \n");
			}
			else
			{

				getInt(&ordenamiento,"Elija forma de ordenamiento: 1) ASCENDETNE, 2) DESCENDENTE\n","NO en valido \n",1,2,2);
				if(ordenamiento==1 || ordenamiento ==2)
				{
					sortEmployees(aEmpleados, QTY_EMPLEADOS,ordenamiento);
					printf("A) Empleados ordenados por Apellido y sector \n");
					printfEmployees(aEmpleados, QTY_EMPLEADOS);
				}
				else
				{
					printf ("NO es una forma de ordenamiento valida \n");
				}
				sumaSalariosYPromedio(aEmpleados,QTY_EMPLEADOS,&sumaSalario,&contadorParaPromedio);
				promedioSalario=sumaSalario/contadorParaPromedio;
				empleadosQueSuperanPromedioSalario=cantidadEmpleadosQueSuperanPromedioSalario(aEmpleados,QTY_EMPLEADOS,promedioSalario);
				printf("\nB) Suma de los salarios: %.2f.\n\nC) Promedio de los salarios: %.2f.\n\nD) Cantidad de empleados que superan el salario promedio: %d. \n\n",sumaSalario,promedioSalario,empleadosQueSuperanPromedioSalario);
			}
			break;

//		case 5:
//			printf("APLICACION CERRADA.\n");
//			break;
		}
		if(opcion!=5)
		{
			esSiONo(respuesta,
							"¿Desea realizar otra operacion? si o no \n",
							"NO es una respuesta valida \n",
							2,
							4,
							2);
					retorno= EXIT_SUCCESS;

					if(strncmp(respuesta,"no",3)==0)
					{
						printf("HASTA LUEGO.\n");
						break;
					}
		}
		else
		{
			printf("APLICACION CERRADA.\n");
			break;
		}


	}while(strncmp(respuesta,"si",3)==0);
	return retorno;
}



/**\brief Give a different and ascendent id each time that function is called
 *
 * \param void
 * \return int Return the number or the id
 *
 */
static int generarId()
{
	static int contadorId=0;
	contadorId++;
	return contadorId;
}


