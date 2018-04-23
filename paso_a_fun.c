/*
Programa:	paso_a_fun.c
Sinopsis:	Pequeña demo para aprender a usar vectores como parámetros
@author:	Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include <stdio.h>
#define MAX 9

//Inicializa el vector
void inicializa_vector (unsigned int vector[MAX]);

//Duplica el valor de las vector registradas
void duplica_vector(unsigned int vector[MAX]);

//Muestra el contenido del vector
void muestra_vector(unsigned int *vector);

int main() {
	//Vector que contiene las vector por cada mil conejos 
	//segun la semana de vida, durante las 9 primeras
	unsigned int vector[MAX];  //declaración del vector
	
	//Inicializamos
	inicializa_vector(vector);

	//Mostramos el vector
	muestra_vector(vector);

	//Duplicamos las vector
	duplica_vector(vector);

	//Volvemos a mostrarlo
	muestra_vector(vector);


	return 0;
}

/**
Función:	inicilaiza_vector
Sinopsis:	con los valores conocidos de mortalidad por semanas	

@param		unsigned int vector[MAX] E/S vector a inicializar 
@return		nada
*/
void inicializa_vector (unsigned int vector[MAX]) {
	
	//Inicializamos.
	vector[0]=3;
	vector[1]=0;
	vector[2]=1;
	vector[3]=5;
	vector[4]=2;
	vector[5]=9;
	vector[6]=7;
	vector[7]=6;
	vector[8]=4;
	return;
}
/**
Función:	muestra_vector
Sinopsis:	muestra el vector elemento a elemento por consola
@param		unsigned int *vector E/S vector a mostrar por consola 
@return		nada
*/
void muestra_vector (unsigned int *muertes) {
	unsigned int semana;

	printf("\n--------------------------");
	printf("\nContenido del vector");
	printf("\n--------------------------");
	for (semana=0; semana < MAX;semana++) {
		printf("\n\tSemana %u: %u casos", semana, *(muertes+semana));
	}
	printf("\n--------------------------\n");

	return;	
}


/**
Función:	duplica_vector
Sinopsis:	Duplica el valor de cada uno de los elementos del vector
@param		unsigned int vector[MAX] E/S vector a duplicar	
@return		nada
*/
void duplica_vector (unsigned int vector[MAX]) {
	unsigned int semana;
	
	for (semana=0; semana < MAX; semana++) {
		vector[semana]*=2;
	}
	return;
}

