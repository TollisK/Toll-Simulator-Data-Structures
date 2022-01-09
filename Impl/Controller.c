/*************************************************************************
Implementation File	: Controller.c
Author	Date		: Apostolos Karvelas 1115201800312 19/3/2019
Purpose				: Counters for controller
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

void ControllerDimiourgia(TController *Controller){
	Controller->ArithmoPelaton = 0;
	Controller->enapomenonXronos = 0;
	Controller->TimeBusy = 0;
	Controller->TimeInactive = 0;
}

void ControllerNewCustomer(TController *Controller){
	Controller->ArithmoPelaton ++;
	Controller->TimeBusy ++;
}

void ControllerSetXrono(TController *Controller, int xronosEksipiretisis){
	Controller->enapomenonXronos = xronosEksipiretisis - 1;
}

void ControllerNoWork(TController *Controller){
	Controller->TimeInactive ++;
}

void ControllerBusy(TController *Controller){
	Controller->TimeBusy ++;
	Controller->enapomenonXronos --;
}
int ControllerFree(TController Controller){
	if(Controller.enapomenonXronos==0)
		return 1;
	else
		return 0;
}
int ControllerGetArithmosPelatwn(TController Controller){
	return Controller.ArithmoPelaton;
}
int ControllerGetEnapomenonXronos(TController Controller){
	return Controller.enapomenonXronos;
}
int ControllerGetInactiveXronos(TController Controller){
	return Controller.TimeInactive;
}
int ControllerGetBusyXronos(TController Controller){
	return Controller.TimeBusy;
}
