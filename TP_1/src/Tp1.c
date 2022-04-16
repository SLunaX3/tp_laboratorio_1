/*
 ============================================================================
 Name        : Tp1.c
 Author      : Luna, Sonia
 División    : 1G
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Tp1Calculos.h"
#include "Tp1funciones.h"

int main()
{
	setbuf(stdout, NULL);

	int opcion;
	float km=0;
	float precioAA=0;
	float precioLatam=0;
	char* msjErrorVuelos="ERROR Ingrese nuevamente valor \n";
	float precioDebitoAA, precioDebitoLatam;
	float precioCreditoAA, precioCreditoLatam;
	float precioBtCAA, precioBtCLatam;
	float precioUnitAA, precioUnitLatam;
	float precioDif=-1;

	do
	{
		opcion = menu(km, precioAA, precioLatam);
		switch(opcion)
		{
		case 1:
			km = utn_getNumero( "Ingresar Kilómetros: \n", msjErrorVuelos, 1);
			break;
		case 2:
			if(km==0)
			{
				printf("No se ingresó los kilómetros de viaje. \n\n");
				continue;
			}
			precioAA = utn_getNumero("Ingrese precio Aerolineas Argentinas\n", msjErrorVuelos, 1);

			precioLatam = utn_getNumero("Ingrese precio Latam\n", msjErrorVuelos, 1);
			break;
		case 3:
			if(km==0)
			{
				printf("No se ingresó los kilómetros de viaje. \n\n");
				continue;
			}
			if(precioAA==0||precioLatam==0)
			{
				printf("No se ingresó los precios de viaje. \n\n");
				continue;
			}

			realizarCalculos(km, precioAA, &precioDebitoAA, &precioCreditoAA, &precioBtCAA, &precioUnitAA);
			realizarCalculos(km, precioLatam, &precioDebitoLatam, &precioCreditoLatam, &precioBtCLatam, &precioUnitLatam);

			precioDif = precioAA-precioLatam;
			if(precioDif<0)
			{
				precioDif= -precioDif;
			}
			printf("CALCULOS REALIZADOS \n\n");
			break;
		case 4:
			if(precioDif==-1)
			{
				printf("No se realizaron los cálculos de precios. \n\n");
				continue;
			}

			printf("KMs Ingresados: %.2f km \n\n", km);

			mostrarPrecios("Aerolineas", precioAA, precioDebitoAA, precioCreditoAA, precioBtCAA, precioUnitAA);

			mostrarPrecios("Latam", precioLatam, precioDebitoLatam, precioCreditoLatam, precioBtCLatam, precioUnitLatam);
			printf("La diferencia de precio es: $%.2f \n\n", precioDif);
			break;
		case 5:
			cargaForzada();
			break;
		case 6:
			printf("Gracias por usar nuestra aplicación***\n");
			break;
		default:
			printf("Ingrese una opción válida del 1 al 6 \n\n");

		}
	}
	while(opcion!=6);


	return EXIT_SUCCESS;
}
