/*
 * TP_1.c
 *
 *  Created on: 4 sep. 2019
 *      Author: Juliana
 */
#include <stdio.h>
#include <stdlib.h>
#include "TP_1.h"


float getFloat(float *resultado,
               char *mensaje,
               char *mensajeError)
{
    int retorno= EXIT_ERROR;
    float buffer;
    while(resultado != NULL &&
            mensaje != NULL &&
            mensajeError != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin); //__fpurge. REEMPLAZAR EN LINUX
        if(scanf("%f",&buffer)==1)
        {
            retorno =EXIT_SUCCESS;
            *resultado=buffer;
            break;
        }
        printf("%s",mensajeError);
    }


    return retorno;
}


int sumarFloat(float primerNumero, float segundoNumero,float *suma)
{
    int retorno=EXIT_SUCCESS;
    *suma=primerNumero+segundoNumero;//no entienod el warning.
    return retorno;
}

int restarFloat(float primerNumero, float segundoNumero,float *resta)
{
    int retorno=EXIT_SUCCESS;
    *resta=primerNumero-segundoNumero;//no entienod el warning.
    return retorno;
}

int dividirFloat(float primerNumero, float segundoNumero,float *division)
{
    int retorno = EXIT_ERROR;

    if(segundoNumero!=0)
    {
        retorno=EXIT_SUCCESS;
        *division=primerNumero/segundoNumero;

    }
    return retorno;


}

int multiplicarFloat(float primerNumero, float segundoNumero,float *multiplicacion)
{
    int retorno = EXIT_SUCCESS;
    *multiplicacion=primerNumero*segundoNumero;
    return retorno;

}

int factorialDeFloat(float primerNumero, float segundoNumero,float *factorialPrimerNumero, float *factorialSegundoNumero)
{
    int retorno= EXIT_SUCCESS;
    int i;
    int j;
    if (primerNumero<0)
    {
        primerNumero=primerNumero*(-1);

    }
    if(segundoNumero<0)
    {
        segundoNumero=segundoNumero*(-1);
    }
    *factorialPrimerNumero=1;
    *factorialSegundoNumero=1;
    for(i=1; i<=primerNumero; i++)
    {
        *factorialPrimerNumero=*factorialPrimerNumero*i;
    }
    for(j=1; j<=segundoNumero; j++)
    {
        *factorialSegundoNumero=*factorialSegundoNumero*j;
    }
    return retorno;
}
