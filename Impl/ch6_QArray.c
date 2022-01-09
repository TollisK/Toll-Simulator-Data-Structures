/*************************************************************************
Implementation File	: QArray.c
Author Date			: Y. Cotronis 07/03/2016
Purpose				: ATD QUEUE with counter - array
Revision			: Apostolos Karvelas 1115201800312 19/3/2019
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ch6_QArray.h"


void OuraDimiourgia(TOuras *oura )
{
	oura->embros =  0;
	oura->piso = 0;
	oura->metritis = 0;
	oura->CountIn = 0;
	oura->CountOut = 0;
}

int OuraKeni(TOuras oura)
{
	return ( oura.metritis == 0 );
}

int OuraGemati(TOuras oura) /* OXI sthn diepafi-edv bohthitikh */
{
		return oura.metritis == QSIZE;
}

int OuraProsthesi(TOuras *oura, TSOuras stoixeio)
{
	if (OuraGemati(*oura))
		return 0;
	else
	{
		TSOurasSetValue(&(oura->pinakas[oura->piso]),stoixeio); /* abstraction of = for any type */
		oura->piso = ( oura->piso + 1 )% QSIZE;
		oura->metritis++;
	}
	oura->CountIn ++;
	return 1;
}

int OuraApomakrynsh(TOuras *oura, TSOuras *stoixeio)
{
	if (OuraKeni(*oura))
		return 0;
	else
	{
		TSOurasSetValue(stoixeio, oura->pinakas[oura->embros]); /* abstraction of = for any type */
		oura->embros = ( oura->embros + 1 )% QSIZE;
		oura->metritis--;
	}
	oura->CountOut ++;
	return 1;
}

int OuraGetSize(TOuras oura){
	return oura.piso - oura.embros;
}

int GetCountIn(TOuras oura){
	return oura.CountIn;
}

int GetCountOut(TOuras oura){
	return oura.CountOut;
}
