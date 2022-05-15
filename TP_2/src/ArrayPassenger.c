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

#define TAM_NOMBRE 51
#define TAM_CODE 10


/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len)
{
    int todoOk = -1;

    if( list != NULL && len > 0)
    {
    	todoOk = 0;

        for(int i=0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Agrega en un array de pasajeros existente los valores recibidos como parámetro en la primer
posición libre.
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{

	int todoOk = -1;
	int indice;
	int newId = lastId(list, len);

	searchFree(list, len, &indice);

	if(list!= NULL && len>0 && name!= NULL && lastName!= NULL && flycode!= NULL)
	{

		todoOk = 0;

		if(indice >= 0)
		{
			strncpy(list[indice].name, name, TAM_NOMBRE);
			strncpy(list[indice].lastName, lastName, TAM_NOMBRE);
			list[indice].price = price;
			//list[indice].idTypePass = typePassenger;
			strncpy(list[indice].flycode, flycode, TAM_CODE);
			//list[indice].statusFlight = estadoVuelo;
			list[indice].isEmpty = 0;
			list[indice].id = newId;

			todoOk = 1;

		}

	}
	return todoOk;
}



/** \brief Busca un pasajero recibiendo como parámetro de búsqueda su Id.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	return NULL;
}


/** \brief Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	return -1;
}

/** \brief Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
descendente.
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order)
{
	return 0;
}

/** \brief Imprime el array de pasajeros de forma encolumnada.
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length)
{
return 0;
}




int menuOpcionnes()
{

    int opcion;

    system("cls");
    printf("     *** Lista de Pasajeros ***\n\n");
    printf("1. Alta pasajeros\n");
    printf("2. Modificar pasajero\n");
    printf("3. Baja pasajero\n");
    printf("4. Informe:\n");
    printf("5. Alta forzada de pasajeros\n");
    printf("30. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

