/*
 * TpCalculos.H
 *
 *      Author: Luna, Sonia
 *      División: 1G
 */

#ifndef TP1CALCULOS_H_
#define TP1CALCULOS_H_

/// @brief Calcula el pago del precio en debito aplicando el %10 de descuento predeterminado
///
/// @param precio El precio del vuelo según la aerolínea
/// @return Devuelve el precio El precio del vuelo con el descuento
float pagoDebito(float);

/// @brief Calcula el pago del precio en debito aplicando el %25 de recargo predeterminado
///
/// @param precio El precio del vuelo según la aerolínea
/// @return Devuelve el precio El precio del vuelo con el recargo
float pagoCredito(float);

/// @brief Calcula el pago del precio de los pagos en bitcoins
///
/// @param precio El precio del vuelo según la aerolínea
/// @return Devuelve el precio El precio del vuelo en bitcoins
float pagoBtC(float);

/// @brief Calcula el precio por kilometro
///
/// @param precio El precio del vuelo
/// @param km La distancia ingresada del vuelo en kilómetros
/// @return Devuelve el precio por kilometro
float precioXkm(float, float);

#endif /* TP1CALCULOS_H_ */
