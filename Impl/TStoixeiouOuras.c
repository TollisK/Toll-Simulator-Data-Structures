/*************************************************************************
Implementation File	: TStoixeiouOyras.c
Author	Date		: Y. Cotronis 07/03/2016
Purpose 			: Ylopoihsh typou stoixeiou ths oyras
Revision			: Apostolos Karvelas 1115201800312 19/3/2019
**************************************************************************/
#include <stdio.h>
#include "TStoixeiouOuras.h"

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras data)
{
	*stoixeioPtr = data;  /* basic type assignment */
}

void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos)
{
	stoixeioPtr->XronosEisodou=xronos;
}

int PelatisGetXronoEisodou(TSOuras stoixeio)
{
	return stoixeio.XronosEisodou;
}

int PelatisGetXronoEksipiretisis (TSOuras stoixeio){
	return stoixeio.XronosEksipiretisis;
}

void PelatisSetXronoEksipiretisis (TSOuras *stoixeioPtr, int duration){
	stoixeioPtr->XronosEksipiretisis = duration;
}
