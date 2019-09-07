
#include <stdio.h>
#include <stdlib.h>
#include "TP_1.h"

/**
 *\brief Pide un numero flotante al usuario y devuelve el exito o no de la obtencion del numero.
 *\param *resultado Es el numero obtenido.
 *\param *mensaje Es el mensaje que se muestra.
 *\param *mensajeError Es el mensaje que muestra en caso de no poder obtener un numero flotante.
 *\return Devuelve 0 si se pudo tomar un numero flotante o un -1 en caso contrario.
 *
 */

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
        fflush(stdin); //EN LINUX ES  __fpurge
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



/**
 *\brief Suma numeros flotantes y devuelve el exito de la suma.
 *\param primerNumero Es el primer numero a sumar.
 *\param segundoNumero Es el segundo numero a sumar.
 *\param *suma Es la suma de los dos numeros anteriores.
 *\return Devuelve 0 si se pudo realizar la suma.
 *
 */

int sumarFloat(float primerNumero, float segundoNumero,float *suma)
{
    int retorno=EXIT_SUCCESS;
    *suma=primerNumero+segundoNumero;
    return retorno;
}


/**
 *\brief Resta numeros flotantes y devuelve el exito de la resta.
 *\param primerNumero Es el primer numero a sumar.
 *\param segundoNumero Es el segundo numero a sumar.
 *\param *resta Es la resta del primer numero menos el segundo.
 *\return Devuelve 0 si se pudo realizar la resta.
 *
 */
int restarFloat(float primerNumero, float segundoNumero,float *resta)
{
    int retorno=EXIT_SUCCESS;
    *resta=primerNumero-segundoNumero;
    return retorno;
}


/**
 *\brief Divide numeros flotantes y devuelve el exito o no de la division.
 *\param primerNumero Es el primer numero, tomado como dividendo.
 *\param segundoNumero Es el segundo numero, tomado como divisor.
 *\param *division Es la division del primer numero y el segundo.
 *\return Devuelve 0 si se pudo realizar la dision, caso contrario devuelve -1 .
 *
 */
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

/**
 *\brief Multiplica numeros flotantes y devuelve el exito de la multiplicacion.
 *\param primerNumero Es el primer numero a multiplicar.
 *\param segundoNumero Es el segundo numero a multiplicar.
 *\param *multiplicacion Es la multiplicacion de los numeros anteriores.
 *\return Devuelve 0 si se pudo realizar la multiplicacion.
 *
 */
int multiplicarFloat(float primerNumero, float segundoNumero,float *multiplicacion)
{
    int retorno = EXIT_SUCCESS;
    *multiplicacion=primerNumero*segundoNumero;
    return retorno;
}



/**
 *\brief Calcula el factorial de numeros flotantes y devuelve el exito de la operacion.
 *\param primerNumero Es el primer numero.
 *\param segundoNumero Es el segundo numero.
 *\param *factorialPrimerNumero Es el factorial del primer numero.
 *\param *factorialSegundoNumero Es el factorial del segundo numero.
 *\return Devuelve 0 si se pudieron realizar las operaciones.
 *
 */
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
