/*
 * tp.h
 *
 *  Created on: 14 may. 2022
 *      Author: sblun
 */

#ifndef TP_H_
#define TP_H_

int searchFree(Passenger* list, int len, int* pIndex);

int addData(Passenger* pasajero);

int loadPassenger (Passenger* list, int len);

int lastId(Passenger* list, int len);

int sortPassengersByName(Passenger* list, int len, int order);

#endif /* TP_H_ */
