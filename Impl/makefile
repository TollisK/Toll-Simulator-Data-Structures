CC=gcc
myprog:ch6_QArray.o ch6_Simulation.o TStoixeiouOuras.o Controller.o
	$(CC) -o myprog ch6_QArray.o ch6_Simulation.o TStoixeiouOuras.o Controller.o
ch6_QArray.o:ch6_QArray.c
	$(CC) -c ch6_QArray.c
ch6_Simulation.o:ch6_Simulation.c
	$(CC) -c ch6_Simulation.c
TStoixeiouOuras.o:TStoixeiouOuras.c
	$(CC) -c TStoixeiouOuras.c
Controller.o:Controller.c
	$(CC) -c Controller.c

.PHONY: clean

