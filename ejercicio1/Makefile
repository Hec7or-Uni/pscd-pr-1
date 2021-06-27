#definición de variables
CC=g++
CPPFLAGS=-I. -std=c++11      #opciones de compilación
LDFLAGS=-pthread             #opciones de enlazado (linkado)
RM=rm -f

all: practica_1_V1 practica_1_V2
#-----------------------------------------------------------
# Compilacion
practica_1_V1.o: practica_1_V1.cpp
	${CC} -c practica_1_V1.cpp ${CPPFLAGS}
#linkado
practica_1_V1: practica_1_V1.o
	${CC} practica_1_V1.o -o practica_1_V1 ${LDFLAGS}
#-----------------------------------------------------------
# Compilacion
practica_1_V2.o: practica_1_V2.cpp
	${CC} -c practica_1_V2.cpp ${CPPFLAGS}
#linkado
practica_1_V2: practica_1_V2.o
	${CC} practica_1_V2.o -o practica_1_V2 ${LDFLAGS}
#-----------------------------------------------------------	
# LIMPIEZA de todo lo generado. OjO: se borrarán sin preguntar
# RM es una de las variables predefinidas en make: invoca borrado de fichero del SO
clean:
	${RM} practica_1_V1.o practica_1_V1
	${RM} practica_1_V2.o practica_1_V2
