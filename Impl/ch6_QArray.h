/*************************************************************************
Header File Name		: QArray.h
Author Date				: Y. Cotronis 07/03/2016
Purpose					: Header file of ATD Queue - counter - array
Revision				: Apostolos Karvelas 1115201800312 19/3/2019
**************************************************************************/
#ifndef __CH2_QARRAY__
#define __CH2_QARRAY__
#include "TStoixeiouOuras.h"


#define QSIZE 1000

typedef struct {
	int embros;		/* position of first element */
	int piso;		/* position of last  element */
	int metritis;   /* counter - elements in queue */
	int CountIn;	/* counter - elements that went in oura*/
	int CountOut;	/* counter - elements that went out of oura*/
	TSOuras pinakas[QSIZE];	/* array of queue elements */
} TOuras;	   /* New Name of Type Queue */
int GetCountIn(TOuras oura);
int GetCountOut(TOuras oura);
void OuraDimiourgia(TOuras *oura);

int	OuraKeni	(TOuras oura);

int OuraProsthesi	(TOuras *oura, TSOuras stoixeio);
int OuraApomakrynsh (TOuras *oura, TSOuras *stoixeio);
int OuraGetSize  (TOuras oura);
#endif
