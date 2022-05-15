/*
 * tp.c
 *
 *  Created on: 14 may. 2022
 *      Author: sblun
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "tp.h"

/// @brief Buscar lugar libre en el array para cargar nuevo pasajero
///
/// @param list Puntero al array Passenger
/// @param len Tamaño del array Passenger
/// @param pIndex Dónde guardar la posicion libre
/// @return
int searchFree(Passenger* list, int len, int* pIndex)
{
    int todoOk = 0;
    if( list != NULL && pIndex != NULL && len > 0)
    {
        *pIndex = -1;
        for(int i=0; i < len; i++)
        {
            if(list[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int addData(Passenger* pasajero)
{
    int todoOk = 0;
    if( pasajero != NULL)
    {
        printf("Ingrese Nombre: ");
        scanf("%s", &pasajero->name);

        printf("Ingrese Apellido: ");
        fflush(stdin);
        scanf("%s", &pasajero->lastName);

        printf("Ingrese Precio: ");
        scanf("%f", &pasajero->price);

        printf("Ingrese Tipo de Pasajero: ");
        scanf("%d", &pasajero->typePassenger);

        printf("Ingrese Código de Vuelo: ");
        scanf("%s", &pasajero->flycode);

        pasajero->isEmpty = 0;

        todoOk = 1;
    }
    return todoOk;
}



int loadPassenger (Passenger* list, int len)
{

	int todoOk = 0;
	int indice;
	Passenger newPsgr;

	system("cls");
	printf("    *** Alta Pasajeros ***\n\n");
	searchFree(list, len, &indice);

	if(indice == -1)
	{
		printf("No hay lugar en el sistema\n");
	}
	else
	{
		addData(&newPsgr);
		addPassenger(list, len, newPsgr.id, newPsgr.name, newPsgr.lastName, newPsgr.price, newPsgr.typePassenger, newPsgr.flycode);

		todoOk = 1;
	}

	return todoOk;
}


int lastId(Passenger* list, int len)
{
	int idMax = -1;

	for(int i=0; i>len; i++)
	{
		if(list[i].id>idMax && list[i].isEmpty!=0)
		{
			idMax = list[i].id;
		}
	}

	return idMax;
}


void mostrarPassenger(Passenger pass)
{

    printf("\t%4d\t%10s\t%10s\t%7.2f\t%4s\t%4d\n",
           pass.id,
           pass.name,
           pass.lastName,
           pass.price,
           pass.flycode,
           pass.typePassenger
          );
}

int listPassenger(Passenger* list, int len)
{
    int todoOk = 0;
    int flag = 0;
    if( list != NULL && len > 0)
    {
        //system("cls");
        printf("       *** Listado de Pasajeros ***\n");
        printf("   Id       Nombre       Apellido     Precio     Código de Vuelo   Tipo de Pasajero\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty == 0)
            {
                mostrarPassenger(list[i]);
                flag = 1;
            }
        }
        if(flag)//= 0
        {
            printf("    No hay empleados en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int sortPassengersByName(Passenger* list, int len, int order)
{
    int todoOk = 0;
    Passenger auxPass;

    if( list != NULL && len > 0)
    {
        for(int i=0; i < len - 1; i++)
        {
            for(int j= i+1; j < len; j++)
            {
            	if(order == 1)
            	{

					if((strcmp(list[i].lastName,list[j].lastName) > 0) && (list[i].typePassenger > list[j].typePassenger))
					{
						auxPass = list[i];
						list[i] = list[j];
						list[j] = auxPass;
					}
            	}
            	else if(order == 0)
            	{
					if((strcmp(list[i].lastName,list[j].lastName) < 0) && (list[i].typePassenger <list[j].typePassenger))
					{
						auxPass = list[i];
						list[i] = list[j];
						list[j] = auxPass;
					}
            	}
            	else
            	{

            		todoOk = 1;
            		printf("Orden inválido \n");
            	}
            }
        }

        todoOk = 1;
    }
    return todoOk;
}
