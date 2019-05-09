#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "utn_strings.h"

/**
 * \brief Recibe un string por referencia para devolverlo escrito.
 * \param1 Array a escribir.
 * \param2 Mensaje para solicitar el array.
 * \param3 Mensaje en caso de error.
 * \return 0 si todo salio bien.
 *         -1 si el array ingresado es invalido.
 */

int getString(char* stringSent, char* message, char*errorMessage)
{
    if(stringSent!=NULL)
    {
        char bufferStr[20];
        printf("%s",message);
        fgets(bufferStr,sizeof(bufferStr),stdin);
        strncpy(stringSent,bufferStr,sizeof(bufferStr));
        return 0;
    }else
    {
        return -1;
    }
}


/**
 * \brief Recibe un int por referencia para devolverlo escrito.
 * \param1 Int a escribir.
 * \param2 Mensaje para solicitar el int.
 * \param3 Mensaje en caso de error.
 * \return 0 si todo salio bien.
 *         -1 si el int ingresado es invalido.
 */


int getInt (int *numeroIngresado, char* mensaje, char* mensajeError)
{
    int respuesta;
    int retorno=-1;
    printf("%s",mensaje);
    if(scanf("%d",&respuesta) == 1)
    {
        __fpurge(stdin);
        *numeroIngresado = respuesta;
        retorno=0;
    }
    else
    {
        printf("%s",mensajeError);
        __fpurge(stdin);
        //__fpurge(stdin);
    }
    return retorno;
}


/**
 * \brief Recibe un float por referencia para devolverlo escrito.
 * \param1 Float a escribir.
 * \param2 Mensaje para solicitar el float.
 * \param3 Mensaje en caso de error.
 * \return 0 si todo salio bien.
 *         -1 si el float ingresado es invalido.
 */

int getFloat (float *numeroIngresado, char* mensaje, char* mensajeError)

{
    float number;
    int ret=-1;
    printf("%s",mensaje);
    if(scanf("%f",&number)==1)
    {
        __fpurge(stdin);
        *numeroIngresado =number;
        ret=0;
    }
    else
    {
        __fpurge(stdin);
        printf("%s",mensajeError);
    }
    return ret;
}


/**
 * \brief Recibe un string por referencia para devolverlo escrito.
 *        El mismo solo puede contener letras o espacios.
 * \param1 Array a escribir.
 * \param2 Mensaje para solicitar el array.
 * \param3 Mensaje en caso de error.
 * \param4 Cantidad de reintentos permitidos.
 * \return 0 si todo salio bien.
 *         -1 si el array ingresado es invalido o
 *            los reintentos son igual o menor a 0.
 */


int getStringLetras (char* stringSent, char* mensaje, char* mensajeError,int reintentos)
{
    int i;
    char bufferStr[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(bufferStr,mensaje,mensajeError)&&(stringSent!=NULL))
        {
            for(i=0;i<strlen(bufferStr);i++)
            {
                if(isalpha(bufferStr[i]))
                {
                    __fpurge(stdin);
                    strncpy(stringSent,bufferStr,sizeof(bufferStr));
                    retorno=0;
                }
            }
            if(retorno)
            {
                __fpurge(stdin);
                printf(mensajeError);
                reintentos--;
            }
        }
        else
        {
            if(reintentos != 0)
            {
                __fpurge(stdin);
                printf(mensajeError);
                reintentos--;
            }
        }
    }
    return retorno;
}


