/*
Programa:	vectores.c
Sinopsis:	Pequeña demo para aprender a definir e inicializar vectores
@author:	Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include <stdio.h>
#define MAX 9

int main () {
	//Vector que contiene las muertes por cada mil conejos 
	//segun la semana de vida, durante las 9 primeras

	unsigned int muertes[MAX];  //declaración del vector
	unsigned int otro[MAX]={3,0,1,5,2,9,7,6,4}; //declaración con inicialización
	unsigned int semana;	//variable para control de bucles

	//Inicializamos el vector. Muertes por semana
	muertes[0]=3;
	muertes[1]=0;
	muertes[2]=1;
	muertes[3]=5;
	muertes[4]=2;
	muertes[5]=9;
	muertes[6]=7;
	muertes[7]=6;
	muertes[8]=4;

	//También así:
	//muertes[MAX]={3,0,1,5,2,9,7,6,4};
	
	//Escribimos uno de los valores.
	printf("\nMuertes de la semana 3: %d\n", muertes[2]);


	//Pero ya sabemos bucles....para el caso de inicializar al mismo valor
	/*for (semana=0; semana < MAX;semana++) {
		muertes[semana]=0;
	}
	*/

	//Copiaremos el vector muertes en el vector otros
	for (semana=0; semana < MAX;semana++) {
		//Copiamos el contenido de muertes en el vector otros
		otro[semana] = muertes[semana];
	}

	//Mostramos el contenido del vetor otros
	printf("\nContenido de otros:\n");
	for (semana=0; semana < MAX;semana++) {
		printf("Otro[%u]=%u\n", semana, otro[semana]);
	}



	return 0;
}
