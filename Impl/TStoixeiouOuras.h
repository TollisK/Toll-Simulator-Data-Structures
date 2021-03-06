/*************************************************************************
Header File Name 		: TStoixeiouOyras.h
Author	Date			: Y. Cotronis 07/03/2016
Purpose					: Diepafi typou stoixeiou ths oyras
Revision				: Apostolos Karvelas 1115201800312 19/3/2019
**************************************************************************/
#ifndef __TStoixeiouOuras__
#define __TStoixeiouOuras__

typedef struct {
	int XronosEisodou; /* Minute of entering queue */
	int XronosEksipiretisis;
} TSOuras; /* name TSOuras is used in ATD Oura - not to be changed */

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras testdata);
/* name TSOurasSetValue is used in ATD Oura - not to be changed */

/* All names below indicate that Typos Stoixeiou is Pelatis (Car) */

void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos);
int  PelatisGetXronoEisodou(TSOuras stoixeio);
void PelatisSetXronoEksipiretisis (TSOuras *stoixeioPtr, int duration);
int PelatisGetXronoEksipiretisis (TSOuras stoixeio);
#endif
