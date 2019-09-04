/*
 ============================================================================
 Name        : TP_1_ENTREGA_06_09_2019.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "TP_1.h"


int main()
{
    float primerOperando;
    float segundoOperando;
    int opcionMenu;
    int flagPrimerOperando=0;
    int flagSegundoOperando=0;
    int flagCalculosRealizados=0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorialPrimerNumero;
    float factorialSegundoNumero;

    do
    {
        system("cls");
        printf ("MENU \n\n");
        printf("1. Ingresar 1er operando (A=%.2f)\n",primerOperando);
        printf("2. Ingresar 2do operando (B=%.2f)\n",segundoOperando);
        printf("3. Calcular todas las operaciones.\n");
        printf("a) Calcular la suma \n");
        printf("b) Calcular la resta \n");
        printf("c) Calcular la division \n");
        printf("d) Calcular la multiplicacion \n");
        printf("e) Calcular el factorial \n");
        printf("4.Informar resultados \n");
        printf("5. Salir \n \n");
        printf("Ingrese una opcion del MENU \n");
        scanf("%d",&opcionMenu);


        while(opcionMenu!=1 && opcionMenu!=2 && opcionMenu!=5 && (flagPrimerOperando==0 || flagSegundoOperando==0))
        {
            if(opcionMenu==3 || opcionMenu==4)
            {
                printf("Aun no hay datos cargados. Por favor elija otra opcion del Menu \n");
                scanf("%d",&opcionMenu);
            }

            else if(opcionMenu>5 || opcionMenu<1)
            {
                printf("No es una opcion valida del Menu. Reingrese otra opcion. \n");
                scanf("%d",&opcionMenu);
            }
        }
        if(opcionMenu==1)
        {
            getFloat(&primerOperando,
                     "Ingrese el primer operando \n",
                     "No es un numero valido. Error. \n");
            flagPrimerOperando=1;
        }
        if(opcionMenu==2)
        {
            getFloat(&segundoOperando,
                     "Ingrese el segundo operando \n",
                     "No es un numero valido. Error. \n");
            flagSegundoOperando=1;
        }

//    while(flagPrimerOperando!=0 && flagSegundoOperando!=0)
//    {
        if(opcionMenu==3)
        {
            sumarFloat(primerOperando, segundoOperando,&suma);
            restarFloat(primerOperando,segundoOperando,&resta);
            dividirFloat(primerOperando, segundoOperando,&division);
            multiplicarFloat(primerOperando, segundoOperando,&multiplicacion);
            factorialDeFloat(primerOperando, segundoOperando,&factorialPrimerNumero, &factorialSegundoNumero);
            printf("Calculos realizados con exitos. \n \n");
            system("pause");
            flagCalculosRealizados=1;
        }
        if(opcionMenu==4 && flagCalculosRealizados==1)
        {
            printf("a) El resultado de A + B es: %.2f \n",suma);
            printf("b) El resultado de A - B es: %.2f \n",resta);
            if(dividirFloat(primerOperando, segundoOperando,&division)==0)
            {
                    printf("c) El resultado de A/B es: %.2f \n",division);
            }
            else
            {
                printf("c) No es posible dividir por cero. \n");
            }
            printf("d) El resultado de A * B es: %.2f \n",multiplicacion);
            printf("e) El factorial de %.2f es: %.2f y el factorial de %.2f es: %.2f\n\n",primerOperando,factorialPrimerNumero,segundoOperando,factorialSegundoNumero);
            system("pause");
        }
        else if(opcionMenu==4 && flagCalculosRealizados==0)
        {
            printf("Error. Primero debe realizar los calculos. \n");
            system("pause");
        }
    }
    while(opcionMenu!=5);


    if(opcionMenu==5) //si pongo 1er operando, 2 do y luego salgo ok printf. Si pongo mal las opciones primero y quiero salir no me toma el pritf.
    {
        printf("Calculadora apagada \n");
    }

    return 0;
}



