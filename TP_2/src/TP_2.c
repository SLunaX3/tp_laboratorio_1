/*
 ============================================================================
 Name        : TP_2.c
 Author      : Luna, Sonia

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "tp.h"

#define MAX_PASS 2000
#define INIT_ID 1000

int main(void) {
	setbuf(stdout, NULL);

	char salir = 'n';

	Passenger lista [MAX_PASS];
	int nextPass = INIT_ID;




    do
    {
        switch(menuOpcionnes())
        {
        case 1: //ALTAS
             if(loadPassenger(lista, MAX_PASS)==1)
            {
                printf("Pasajero cargado con exito!!!\n");
            }
            else
            {
                printf("No se pudo cargar Pasajero\n");
            }
            break;
        case 2://MODIFICAR
            //modificarEmpleado(lista, TAM, sectores, TAMS);
            break;

        case 3://BAJA
            //bajaEmpleado(lista, TAM, sectores, TAMS);
            break;

        case 4://INFORMAR
            sortPassengers(lista, MAX_PASS, 1);
            listPassenger(lista, MAX_PASS);
            break;


        case 30:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');



	return EXIT_SUCCESS;
}
