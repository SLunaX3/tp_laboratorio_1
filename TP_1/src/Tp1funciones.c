/*
 * Tp1funciones.C
 *
 *      Author: Luna, Sonia
 *      División: 1G
 *
 	 Documnetación también aquí para guía extra
 */


#include <stdio.h>
#include <stdlib.h>
#include "Tp1Calculos.h"
#include "Tp1funciones.h"

/// @brief Muestra opciones del menú principal
///
/// @param km La distancia del viaje en kilómetros
/// @param precioAA El precio de vuelo por Aerolineas Argentinas
/// @param precioLatam El precio de vuelo por Latam
/// @return Devuelve el valor de la opcion elegida del menú

int menu(float km, float precioAA, float precioLatam)
	{
		int opcion;

        printf("1. Ingresar Kilómetros: (km=%.2f) \n", km);
        printf("2. Ingresar Precio de Vuelos: (Aerolíneas=$%.2f, Latam=$%.2f) \n", precioAA, precioLatam);
        printf("3. Calcular todos los costos: \n");
        printf("4. Informar Resultados \n");
        printf("5. Carga forzada de datos \n");
        printf("6. Salir \n\n");
        printf("Ingrese opción: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        return opcion;
    }


/// @brief Muestra los precios de la aerolinea y valores de pagos  con el formato determinado
///
/// @param pNombre El nombre de la aerolinea a mostrar
/// @param precio El precio del vuelo
/// @param precioDebito El precio con descuento por pago en debito
/// @param precioCredito El precio con recargo por pago en credito
/// @param precioBtC El precio del vuelo en bitcoins
/// @param precioUnit El precio del vuelo por kilometro

void mostrarPrecios(char* pNombre, float precio, float precioDebito, float precioCredito, float precioBtC, float precioUnit)
{
	printf("Precio %s: $%.2f \n", pNombre, precio);

	printf("a) Precio con tarjeta de debito: $ %.2f \n", precioDebito);
	printf("b) Precio con tarjeta de credito: $ %.2f \n", precioCredito);
	printf("c) Precio pagando con bitcoin: %f BTC \n", precioBtC);
	printf("d) Mostrar precio unitario: $ %f \n\n", precioUnit);
}

/// @brief Permite y valdida el ingreso de datos
///
/// @param pMensaje Para pedirle al usuario que ingrese distancia de viaje
/// @param pMensajeError Para avisar que es un ingreso erroneo
/// @param minimo El valor mínimo requerido para que se valide el ingreso
/// @return Devuelve el numero ingresado y validado

float utn_getNumero(char* pMensaje, char* pMensajeError, int minimo)
{
	int bufferInt;
	int retorno= -1;
	if(pMensaje!=NULL && pMensajeError!=NULL)
	{
		do
		{
			printf("%s", pMensaje);
			scanf("%d", &bufferInt);
			if(bufferInt>=minimo)
			{
				retorno= bufferInt;
				break;
			}
			else
			{
				printf("%s \n", pMensajeError);
			}

		}while(1);
	}
	return retorno;
}

/// @brief Calcula los valores según cada método de pago
///
/// @param km La distancia de viaje en kilómetros
/// @param precio El precio del vuelo
/// @param pPrecioDebito Variable utilizada para modificar el valor de "precioDebito" por referencia
/// @param pPrecioCredito Variable utilizada para modificar el valor de "precioCredito" por referencia
/// @param pPrecioBtC Variable utilizada para modificar el valor de "precioBtC" por referencia
/// @param pPrecioUnitario Variable utilizada para modificar el valor de "precioUnitario" por referencia

void realizarCalculos(float km, float precio, float* pPrecioDebito, float* pPrecioCredito, float* pPrecioBtC, float* pPrecioUnitario)
{

	*pPrecioDebito = pagoDebito(precio);
	*pPrecioCredito = pagoCredito(precio);
	*pPrecioBtC = pagoBtC(precio);
	*pPrecioUnitario = precioXkm(km, precio);

}

/// @brief Calcula y muestra los valores con los datos predefinidos
///

void cargaForzada(void)
{
	float km = 7090;
	float precioAA = 162965;
	float precioLatam = 159339;
	float precioDebitoAA, precioCreditoAA, precioBtCAA, precioUnitAA;
	float precioDebitoLatam, precioCreditoLatam, precioBtCLatam, precioUnitLatam;

	realizarCalculos(km, precioAA, &precioDebitoAA, &precioCreditoAA, &precioBtCAA, &precioUnitAA);
	realizarCalculos(km, precioLatam, &precioDebitoLatam, &precioCreditoLatam, &precioBtCLatam, &precioUnitLatam);
	float precioDif = precioAA-precioLatam;
	if(precioDif<0)
	{
		precioDif= -precioDif;
	}

	printf("KMs Ingresados: %.2f km \n\n", km);

	mostrarPrecios("Aerolineas", precioAA, precioDebitoAA, precioCreditoAA, precioBtCAA, precioUnitAA);

	mostrarPrecios("Latam", precioLatam, precioDebitoLatam, precioCreditoLatam, precioBtCLatam, precioUnitLatam);
	printf("La diferencia de precio es: $%.2f \n\n", precioDif);

}


