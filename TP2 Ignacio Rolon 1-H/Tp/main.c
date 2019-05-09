/******************************************************************
* Programa: Nomina de Empleados ABM (Trabajo Práctico Numero 2)
*
* Objetivo:
*   -Crear funciones que permitan realizar modificaciones a estructuras y arrays.
*   -Manejar arrays, estructuras y pasajes por referencia
*   -Realizar una biblioteca que contenga todas las funciones utilizadas.
*   -Documentar las funciones.
*
* Autor: Ignacio Rolón
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#include <ctype.h>
#include "utn_strings.h"
#define LEN_EMPLEADOS 1000

int main()
{
    int respuesta = 8;
    int respuestaOrden, bufferInt, i;
    Employee empleados[LEN_EMPLEADOS];
    initEmployees(empleados, LEN_EMPLEADOS);
    while(respuesta != 7)
    {
        printf("\n1) Agregar empleados");
        printf("\n2) Ver empleados");
        printf("\n3) Remover empleado");
        printf("\n4) Modificar empleado");
        printf("\n5) Ordenar empleados y mostrar");
        printf("\n6) Total y promedio de Salarios");
        printf("\n7) Salir");
        printf("\n");
        __fpurge(stdin);
        scanf("%d", &respuesta);
        //fflush(stdin);
        switch(respuesta)
        {
            case 1:
            {
                altaEmployee(empleados, LEN_EMPLEADOS);
                break;
            }
            case 2:
            {
                printEmployees(empleados, LEN_EMPLEADOS);
                break;
            }
            case 3:
            {
                printEmployees(empleados, LEN_EMPLEADOS);
                removeEmployee(empleados, LEN_EMPLEADOS);
                break;
            }
            case 4:
            {
                printEmployees(empleados, LEN_EMPLEADOS);
                modifyEmployee(empleados, LEN_EMPLEADOS);
                break;
            }
            case 5:
            {
                bufferInt = getInt(&respuestaOrden, "\nIngrese el tipo de orden. 0 para descendente y 1 para ascendente: ", "Error: El orden ingresado no es valido.");
                if(!bufferInt)
                {
                    sortEmployees(empleados, LEN_EMPLEADOS, respuestaOrden);
                }
                printEmployees(empleados, LEN_EMPLEADOS);
            }
            case 6:
            {
                float contadorSalarios = 0;
                float promedioSalarios = 0;
                int contadorEmpleados = 0;
                int sobreElPromedio = 0;

                for(i=0;i<LEN_EMPLEADOS;i++)
                {
                    if(empleados[i].isEmpty == 0)
                    {
                        contadorSalarios = contadorSalarios + empleados[i].salary;
                        contadorEmpleados++;
                    }
                }
                promedioSalarios = contadorSalarios / contadorEmpleados;
                for(i=0;i<LEN_EMPLEADOS;i++)
                {
                    if(empleados[i].isEmpty == 0 && empleados[i].salary > promedioSalarios)
                    {
                        sobreElPromedio++;
                    }
                }
                printf("Total de Salarios: %.2f", contadorSalarios);
                printf("Promedio de Salarios: %.2f", promedioSalarios);
                printf("Empleados con salario superior al promedio: %d", sobreElPromedio);

            }
        }
    }
}
