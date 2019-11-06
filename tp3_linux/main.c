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
        		controller_ListEmployee(listaEmpleados);
           	 break;
            case 2:
                controller_loadFromBinary("data.bin", listaEmpleados);// incompleto
                controller_ListEmployee(listaEmpleados);
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
            	printf("Aplicacion cerrada \n");
                break;
          }
    }while(opcion != 10);

}


//int f1(int *a, int b,int (*foo)(int,int)) {
//	*a = *a * 2;
//	*a = foo(*a,b);
//	return (*a);
//}
//
//int f2(int a, int b) {
//	 a = b*b;
//	 return a;
//}
//
//
//enum colors {lets,find,course};
//int main()
//{
//	printf("%d %d %d",course,lets,find);
//	return 0;
//}


/*
int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}*/



//TP 4
//this =malloc(sizeof(LInkedList));
//
//
//if(thus!=NULL) {returnaUX THIS->SIZE
//
//int salto;
//node *pNodo=NULL;
//IF(this!=NULL && nodeindex>=0 && nodeindex<this -> size)
//pnodo = this ->pFisrtNOde;
//for(saltos=0;saltos<nodeindex;saltos++)
//pnodo = pnodo->pnextnodo
//RETURN pNodo
//
//
// node * pNOdo;
// node *pnodoanterior
//if(this!=NULL && nodeindex>=0 && nodeindex <=this ->size)
// pnodo=malloc(sizeof(pnodo));
// if(pnodo!=NULL) return -1;
//returnaux=0;
// this->size++;
//pnodo->pelement = pelement;
//if(nodeindex==0)
//pnodo ->pnext = this ->firstnode
//this ->firstnode = pnodo
//else
//pnodoant = getnose(this,nodeindex-1)
//pnodo->pnext = pnodoanter->pnext;
//pnodoante->pnext =pnodo;


// borrar lista
//delete borrar memoria
//size si esta en cero
//push poner un elemento en donde se quiera
//pop devolver el elemento de cualqier posicion . get del size y sacarlo remove
//contanis(ver si existe un elemento en la lissta)
//contains all (pasa array de elementos y verificar que la sublista es sublista del la lista original
// agregar remove node.
