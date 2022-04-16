/*
 * Tpfunciones.H
 *
 *      Author: Luna, Sonia
 *      División: 1G
 */

#ifndef TP1FUNCIONES_H_
#define TP1FUNCIONES_H_

/// @brief Muestra opciones del menú principal
///
/// @param km La distancia del viaje en kilómetros
/// @param precioAA El precio de vuelo por Aerolineas Argentinas
/// @param precioLatam El precio de vuelo por Latam
/// @return Devuelve el valor de la opcion elegida del menú
int menu(float, float, float);

/// @brief Muestra los precios de la aerolinea y valores de pagos con el formato determinado
///
/// @param pNombre El nombre de la aerolinea a mostrar
/// @param precio El precio del vuelo según la aerolinea
/// @param precioDebito El precio por aerolínea con descuento por pago en debito
/// @param precioCredito El precio por aerolínea con recargo por pago en credito
/// @param precioBtC El precio por aerolínea en bitcoins
/// @param precioUnit El precio del vuelo por kilometro
void mostrarPrecios(char*, float, float, float, float, float);

/// @brief Permite y valdida el ingreso de datos
///
/// @param pMensaje Para pedirle al usuario que ingrese distancia de viaje
/// @param pMensajeError Para avisar que es un ingreso erroneo
/// @param minimo El valor mínimo requerido para que se valide el ingreso
/// @return Devuelve el numero ingresado y validado
float utn_getNumero(char*, char*, int);

/// @brief Calcula los valores según cada método de pago
///
/// @param km La distancia ingresada del viaje en kilómetros
/// @param precio El precio del vuelo según la aerolínea
/// @param pPrecioDebito Variable utilizada para modificar el valor de "pPrecioDebito" por referencia
/// @param pPrecioCredito Variable utilizada para modificar el valor de "pPrecioCredito" por referencia
/// @param pPrecioBtC Variable utilizada para modificar el valor de "pPrecioBtC" por referencia
/// @param pPrecioUnitario Variable utilizada para modificar el valor de "pPrecioUnitario" por referencia
void realizarCalculos(float, float, float*, float*, float*, float*);

/// @brief Calcula y muestra los valores con los datos predefinidos
///
void cargaForzada(void);

#endif /* TP1FUNCIONES_H_ */
