/*
 * TpCalculos.C
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


/// @brief Calcula el pago en debito aplicando el %10 de descuento predefinido
///
/// @param precio El precio del vuelo
/// @return Devuelve el precio El precio del vuelo con el descuento
float pagoDebito(float precio)
{
	float precioDebito;
	precioDebito=precio*0.9;
	return precioDebito;
}

/// @brief Calcula el pago en debito aplicando el %25 de recargo predefinido
///
/// @param precio del vuelo
/// @return Devuelve el precio del vuelo con el recargo
float pagoCredito(float precio)
{
	float precioCredito;
	precioCredito=precio*1.25;
	return precioCredito;
}

/// @brief Calcula el precio de los pagos en bitcoins
///
/// @param precio El precio del vuelo
/// @return Devuelve el precio el precio del vuelo en bitcoins
float pagoBtC(float precio)
{
	float precioBtC;
	precioBtC=precio/4623262.09;
	return precioBtC;
}

/// @brief calcula precio por kilometro
///
/// @param precio El precio del vuelo
/// @param km La distancia del vuelo en kilómetros
/// @return Devuelve precio el precio por kilometro
float precioXkm(float precio, float km)
{
	float precioUnit;
	precioUnit= precio/km;
	return precioUnit;
}

