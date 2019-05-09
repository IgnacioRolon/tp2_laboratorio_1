#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#include <string.h>
#include "utn_strings.h"

static int generarId(void);

/**
 * \brief Recibe el array de empleados y lo inicializa.
 * \param1 Array del tipo de estructura creado en el .h (Employee).
 * \param2 Int con la longitud del array de Employees.
 * \return 0 para confirmar que la función se completo de forma correcta.
 *         -1 si se ingresó un array null o si la longitud es invalida.
 */

int initEmployees(Employee* list, int len)
{
    if(list != NULL && len > 0)
    {
        int i;
        for(i = 0;i < len;i++)
        {
            list[i].isEmpty = 1;
        }
        return 0;
    }else
    {
        return -1;
    }
}

/**
 * \brief Le solicita al usuario el ingreso de nombre, apellido, salario y sector
 *        y lo agrega al array de Employee.
 * \param1 Array del tipo de estructura creado en el .h (Employee).
 * \param2 Int con la longitud del array de Employees.
 * \return 0 para confirmar que la función se completo de forma correcta.
 *         -1 si se ingresó un array null o si la longitud es invalida
 *            o si alguno de los parametros recibio un valor invalido del usuario.
 */

int altaEmployee(Employee* list, int len)
{
    char bufferStr[52];
    char name[52];
    char lastName[52];
    float bufferFloat;
    int bufferInt;
    float salary;
    int sector;
    int id;
    int i;
    int retorno = -1;

    if(list != NULL && len > 0)
    {
        __fpurge(stdin);
        if(!getStringLetras(bufferStr, "\nIngrese el Nombre del Empleado: ", "Error, ingrese un nombre valido.\n ", 1))
        {
            strncpy(name, bufferStr, sizeof(bufferStr));
            __fpurge(stdin);
            if(!getStringLetras(bufferStr, "\nIngrese el Apellido del Empleado: ", "\nError, ingrese un apellido valido. ", 1))
            {
                strncpy(lastName, bufferStr, sizeof(bufferStr));
                __fpurge(stdin);
                if(!getFloat(&bufferFloat, "\nIngrese su salario: ", "\nError, ingrese un salario valido"))
                {
                    salary = bufferFloat;
                    if(salary <= 0)
                    {
                        printf("El salario debe ser mayor a 0.\n");
                        return retorno;
                    }
                    __fpurge(stdin);
                    if(!getInt(&bufferInt, "\nIngrese el numero de sector: ", "\nError, ingrese un sector valido"))
                    {
                        sector = bufferInt;
                        id = generarId();
                        for(i=0;i<len;i++)
                        {
                            if(list[i].isEmpty == 1)
                            {
                                list[i].id = id;
                                strncpy(list[i].name, name, sizeof(name));
                                strncpy(list[i].lastName, lastName, sizeof(name));
                                list[i].salary = salary;
                                list[i].sector = sector;
                                list[i].isEmpty = 0;
                                printf("\nEmpleado agregado con exito.\n");
                                break;
                            }else
                            {
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief Genera un ID empezando por el primer ID (1)
 * \return Valor de ID siguiente al ultimo usado.
 */

static int generarId(void)
{
    static int id=1;
    return id++;
}

/**
 * \brief Recibe el array de empleados y muestra por pantalla los empleados ingresados.
 * \param1 Array del tipo de estructura creado en el .h (Employee).
 * \param2 Int con la longitud del array de Employees.
 * \return 0 para confirmar que la función se completo de forma correcta.
 *         -1 si se ingresó un array null o si la longitud es invalida.
 */

int printEmployees(Employee *list,int len)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        int i;
        int flag=1;
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("\nID: %d\nNombre: %sApellido: %sSalario: %.2f\nSector: %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
                flag=0;
            }
        }
        if(flag)
        {
            printf("\nNo se han registrado empleados.");
        }
    }
    return retorno;
}

/**
 * \brief Recibe el array de empleados y elimina un empleado de manera logica
 *        segun lo haya solicitado el usuario.
 * \param1 Array del tipo de estructura creado en el .h (Employee).
 * \param2 Int con la longitud del array de Employees.
 * \return 0 para confirmar que la función se completo de forma correcta.
 *         -1 si se ingresó un array null o si la longitud es invalida,
 *            si no se ingresaron empleados o si se ingreso una ID invalida.
 */

int removeEmployee(Employee* list, int len)
{
    int respuesta;
    int id;
    int i;
    int flag;
    int bufferInt;
    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty)
            {
                flag = 1;
            }else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("\nNo se han registrado empleados.");
            return retorno;
        }
        __fpurge(stdin);
        bufferInt = getInt(&respuesta, "\nIngrese el ID del Empleado a eliminar: ", "\nError: ID Invalido.");
        if(bufferInt == 0)
        {
            id = findEmployeeById(list, len, respuesta);
            if(list[id].isEmpty == 0 && id != -1)
            {
                list[id].isEmpty = 1;
                printf("\nEmpleado eliminado.");
            }else
            {
                printf("\nError: El ID ingresado no corresponde a ningun empleado.");
            }
        }
    }
    return retorno;
}

/**
 * \brief Recibe el array de empleados y modifica una entrada por su ID.
 * \param1 Array del tipo de estructura creado en el .h (Employee).
 * \param2 Int con la longitud del array de Employees.
 * \return 0 para confirmar que la función se completo de forma correcta.
 *         -1 si se ingresó un array null o si la longitud es invalida.
 */

int modifyEmployee(Employee* list, int len)
{
    int respuesta;
    int id;
    int flag;
    int i;
    float respuestaF;
    int bufferInt;
    char bufferStr[52];
    int retorno = -1;
    if(list != NULL || len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty)
            {
                flag = 1;
            }else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("\nNo se han registrado empleados.");
            return retorno;
        }
        bufferInt = getInt(&respuesta, "\nIngrese el ID del Empleado a modificar: ", "\nError: ID Invalido.");
        if(bufferInt == 0)
        {
            id = findEmployeeById(list, len, respuesta);
            if(list[id].isEmpty == 0 && id != -1)
            {
                printf("\n1) Nombre");
                printf("\n2) Apellido");
                printf("\n3) Salario");
                printf("\n4) Sector");
                __fpurge(stdin);
                getInt(&respuesta, "\nIngrese lo que desea modificar: ", "\nError: Valor invalido.");
                switch(respuesta)
                {
                    case 1:
                    {
                        __fpurge(stdin);
                        if(!getStringLetras(bufferStr, "\nIngrese el nuevo nombre: ", "\nError: Nombre invalido", 1))
                        {
                            strncpy(list[id].name,bufferStr,sizeof(list[id].name));
                            printf("\nNombre cambiado exitosamente");
                            retorno = 0;
                        }
                        break;
                    }
                    case 2:
                    {
                        __fpurge(stdin);

                        if(!getStringLetras(bufferStr, "\nIngrese el nuevo apellido: ", "\nError: Apellido invalido", 1))
                        {
                            strncpy(list[id].lastName, bufferStr, sizeof(list[id].lastName));
                            printf("\nApellido cambiado exitosamente");
                            retorno = 0;
                        }
                        break;
                    }
                    case 3:
                    {
                        __fpurge(stdin);
                        if(!getFloat(&respuestaF, "\nIngrese el nuevo salario: ", "\nError: Salario invalido."))
                        {
                            list[id].salary = respuestaF;
                            printf("\nSalario cambiado exitosamente");
                            retorno = 0;
                        }
                        break;
                    }
                    case 4:
                    {
                        __fpurge(stdin);
                        if(getInt(&respuesta, "\nIngrese el nuevo sector: ", "\nError: Sector invalido."))
                        {
                            list[id].sector = respuesta;
                            printf("\nSector cambiado exitosamente");
                            retorno = 0;
                        }
                        break;
                    }
                }
            }else
            {
                printf("\nError: El ID ingresado no corresponde a ningun empleado.");
            }
        }
    }
    return retorno;
}

/**
 * \brief Recibe el array de empleados y busca el ID ingresado.
 * \param1 Array del tipo de estructura creado en el .h (Employee).
 * \param2 Int con la longitud del array de Employees.
 * \param3 Int con el ID a buscar.
 * \return La posición donde se encuentra el empleado en el array
 *         -1 si no encontró o si se ingresaron valores invalidos.
 */


int findEmployeeById(Employee* list, int len, int id)
{
    int i;
    int retorno = -1;
    if(list != NULL && len > 0 && id > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Recibe el array de empleados y busca el ID ingresado.
 * \param1 Array del tipo de estructura creado en el .h (Employee).
 * \param2 Int con la longitud del array de Employees.
 * \param3 Int con el orden a buscar. (0 para descendente y 1 para ascendente).
 * \return La posición donde se encuentra el empleado en el array
 *         -1 si no encontró o si se ingresaron valores invalidos.
 */

int sortEmployees(Employee* list, int len, int order)
{
    int j = 0;
    int flag;
    int retorno =-1;
    Employee buffer;
    if(list != NULL && len > 0)
    {
        if(order == 1)
        {
            do
            {
                flag = 0;
                for(j=0;j<len-1;j++)
                {
                    if(list[j].isEmpty == 1 || list[j+1].isEmpty == 1)
                    {
                        continue;
                    }
                    if(strncmp(list[j].lastName, list[j+1].lastName, 50) > 0)
                    {
                        buffer = list[j];
                        list[j] = list[j+1];
                        list[j+1] = buffer;
                        flag = 1;
                    }else if(list[j+1].lastName == list[j].lastName)
                    {
                        if(list[j].sector > list[j+1].sector)
                        {
                            buffer = list[j];
                            list[j] = list[j+1];
                            list[j+1] = buffer;
                            flag = 1;
                        }
                    }
                }
            }while(flag == 1);
            printf("Ordenados exitosamente de forma ascendente.");
            retorno = 0;
        }else if(order == 0)
        {
            do
            {
                flag = 0;
                for(j=0;j<len-1;j++)
                {
                    if(list[j].isEmpty == 1 || list[j+1].isEmpty == 1)
                    {
                        continue;
                    }
                    if(strncmp(list[j+1].lastName, list[j].lastName, 50) > 0)
                    {
                        buffer = list[j];
                        list[j] = list[j+1];
                        list[j+1] = buffer;
                        flag = 1;
                    }else if(list[j+1].lastName == list[j].lastName)
                    {
                        if(list[j].sector < list[j+1].sector)
                        {
                            buffer = list[j];
                            list[j] = list[j+1];
                            list[j+1] = buffer;
                            flag = 1;
                        }
                    }
                }
            }while(flag == 1);
            printf("Ordenados exitosamente de forma descendente.");
            retorno = 0;
        }else
        {
            printf("El orden ingresado no es valido.");
        }
    }
    return retorno;
}
