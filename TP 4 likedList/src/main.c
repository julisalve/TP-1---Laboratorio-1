/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "../testing/inc/main_test.h"
//#include "../inc/LinkedList.h"
//
//
//int main(void)
//{
//	startTesting(1);  // ll_newLinkedList
//	startTesting(2);  // ll_len
//  	startTesting(3);  // getNode - test_getNode
//  	startTesting(4);  // addNode - test_addNode
//  	startTesting(5);  // ll_add //preguntar si llega hasta el size no hace la prueba, pero si uso ll_len si la hace.
//  	startTesting(6);  // ll_get
//	startTesting(7);  // ll_set
//	startTesting(8);  // ll_remove
//	startTesting(9);  // ll_clear
//	startTesting(10); // ll_deleteLinkedList
//	startTesting(11); // ll_indexOf
//	startTesting(12); // ll_isEmpty
//	startTesting(13); // ll_push
//	startTesting(14); // ll_pop
//	startTesting(15); // ll_contains
//	startTesting(16); // ll_containsAll
//	startTesting(17); // ll_subList
//	startTesting(18); // ll_clone
//	startTesting(19); // ll_sort
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "general.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
 int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
            printf("\n\nMENU\n\n");
            printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
            printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
            printf("3. Alta de empleado\n");
            printf("4. Modificar datos de empleado\n");
            printf("5. Baja de empleado\n");
            printf("6. Listar empleados\n");
            printf("7. Ordenar empleados\n");
            printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
            printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
            printf("10. Salir\n");

            getInt(&opcion,
            		  "Elija una opcion\n",
            		  "No es una opcion valida \n",
            		  1,
            		  10,
            		  2);
   switch(opcion)
         {
        case 1:
        		controller_loadFromText("data.csv",listaEmpleados);
        		break;
            case 2:
                controller_loadFromBinary("data.bin", listaEmpleados);// incompleto
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
            case 10:
            	ll_deleteLinkedList(listaEmpleados);
            	printf("Aplicacion cerrada \n");
                break;
          }
    }while(opcion != 10);

}
































