/*************************************************************************
Header File Name		: Controller.h
Author	Date			: Apostolos Karvelas 1115201800312 19/3/2019
Purpose					: Header file of Controllers functions
**************************************************************************/
#ifndef __CONTROLLER__
#define __CONTROLLER__

typedef struct {
	int TimeBusy;			/*xronos poy htan apasxolhmenos*/
	int TimeInactive;		/*xronos poy htan adranhs*/
	int ArithmoPelaton;		/*arithmos pelatwn poy e3ypethse*/
	int enapomenonXronos;	/*enapomeinentas xronos*/
} TController;

void ControllerDimiourgia(TController *Controller); /*arxikopoiei ta melh tou struct*/
void ControllerNewCustomer(TController *Controller);/*metrhths pelatwn*/
void ControllerSetXrono(TController *Controller, int xronosEksipiretisis); /*arxikopoihsh enapomeinanta xrono*/
void ControllerNoWork(TController *Controller);/*au3hsh xronoy adraneias*/
void ControllerBusy(TController *Controller); /*xrono apasxolhshs*/
int ControllerFree(TController Controller);/*elegxei diathesimothta*/
int ControllerGetArithmosPelatwn(TController Controller);/*arithmos pelatwn*/
int ControllerGetEnapomenonXronos(TController Controller);/*enapomeinantas xronos*/
int ControllerGetInactiveXronos(TController Controller);/*xronos adraneias*/
int ControllerGetBusyXronos(TController Controller);/*xronos apasxolhshs*/

#endif
