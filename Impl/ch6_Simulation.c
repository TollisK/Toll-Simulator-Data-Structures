/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			: Apostolos Karvelas 1115201800312 19/3/2019
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "Controller.h"

#define OURES 3 /*O arithmos twn ourwn poy exei to programma*/

int main(void)
{	TOuras      	oura[OURES];		 /*oura pelatwn-aytokinhtvn */
	TController		Controller[OURES];	 /*controller*/
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis;/*xronos e3yphrethshs enos pelath*/
	unsigned int	elax,meg,pith;		 /*elaxisto kai megisto xrono e3yphrethsh*/
	unsigned int	xronos_prosomoiosis; /*synolikos xronos prosomoiwshs*/

	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	unsigned int	enapomenon_xronos;	 /*xronos gia to telos e3yphrethshs enos pelath*/
	unsigned int	arithmos_pelaton; 	 /*plh8os e3yphreth8entwn pelatwn*/
	unsigned int	xronos_anamonis[OURES];	 /*synolikos xronos anamonhs*/
	TSOuras		    Pelatis;		 	/* o pelaths sthn oyra*/
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	int       tamiasInactive=0,i,ourasize,elaxisto,location;
	time_t			t;

	printf("Dwste units of time prosomoiwshs (0 <=), pi8anothta afikshs in unit of time (0,1),ton elaxisto kai ton megisto xrono e3yphrethshs (>=1) in unit of times \n");
	scanf("%u %f %u %u",&xronos_prosomoiosis,&pithanotita_afiksis,&elax,&meg);
	getchar();
	printf("H prosomoiwsh xrhsimopoiei %d oures\n",OURES);
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("H diarkeia e3yphrethshs enos pelath einai meta3y toy %d kai %d units of time .\n",elax,meg);
	if(elax > meg){
		printf("Wrong data");
		return 0;
	}
	for(i=0;i<OURES;i++){
	ControllerDimiourgia(&(Controller[i]));
	OuraDimiourgia(&(oura[i]));
	xronos_anamonis[i]=0;
	}
	xronos = 0;
	enapomenon_xronos = 0;
	arithmos_pelaton = 0;
	srand(time(&t));

	while( xronos < xronos_prosomoiosis )
	{	/* Pelatis - Aytokinhto  */
		elaxisto = 0;
		location =0;
		randomAfixi = (float)rand()/(float)RAND_MAX;
		if ( randomAfixi < pithanotita_afiksis ){
			PelatisSetXronoEisodou(&Pelatis, xronos);
			elaxisto = OuraGetSize(oura[0]);
			for(i=1;i<OURES;i++){
				if(elaxisto>OuraGetSize(oura[i])){
					elaxisto = OuraGetSize(oura[i]);
					location = i;
				}
			}
			if (!OuraProsthesi(&(oura[location]), Pelatis)){
                  printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
                  getchar();
                  return 0;
        	};
    	};
    	/* Tamias-Elegxos */
    	for(i=0;i<OURES;i++){
		if ( ControllerFree(Controller[i]))	/*eley8eros tamias*/
			if (!OuraKeni(oura[i]))			/*yparxei pelaths*/
			{	OuraApomakrynsh(&(oura[i]),&Pelatis);		/*phgainei sto tamio*/
				PelatisSetXronoEksipiretisis (&Pelatis,rand()/(RAND_MAX/(meg+1-elax)) + elax);
				xronos_anamonis[i] += xronos - PelatisGetXronoEisodou(Pelatis);	/*ypologismos xronoy paramonhs sthn oura*/
				/* printf("Time is %d Time out %d\n", xronos, PelatisGetXronoEisodou(Pelatis)); */
				ControllerNewCustomer(&(Controller[i]));
				ControllerSetXrono(&(Controller[i]), PelatisGetXronoEksipiretisis(Pelatis)); /* kallyptei to trexon unit time */
			}else ControllerNoWork(&(Controller[i]));
		else ControllerBusy(&(Controller[i]));		/*o tamias apasxolhmenos me pelath */
		}
		xronos++; /*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	} /*while( xronos < xronos_prosomoiosis )*/
	for(i=0;i<OURES;i++){
		if (ControllerGetArithmosPelatwn(Controller[i]) == 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis[i])/((float)ControllerGetArithmosPelatwn(Controller[i]));
	printf("\nGia thn oura me noumero:%d",i);
	printf("\nEksyphreth8hkan %d pelates",ControllerGetArithmosPelatwn(Controller[i]));
	printf("\nDen e3yphreth8hkan %d pelates\n" , OuraGetSize(oura[i]));
	printf("O mesos xronos anamonhs htan %4.2f units of time.\n",mesos_xronos);
	printf("O tamias htan adranhs gia %d units of time\n", ControllerGetInactiveXronos(Controller[i]));
	printf("O tamias htan apasxolhmenos gia %d units of time\n",ControllerGetBusyXronos(Controller[i]));
	printf("Mphkan synolika %d autokinhta\n" ,GetCountIn(oura[i]));
	printf("Bghkan synolika %d autokinhta\n" ,GetCountOut(oura[i]));
	}
    getchar();
	return 0;
}
