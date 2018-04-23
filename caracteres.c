/*
Programa:	caracteres.c
Sinopsis:	Pequeña demo para aprender a definir vectores de caracteres
@author:	Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include <stdio.h>
#include <math.h>
#define MAX 5


//Muestra el contenido del vector por consola
void muestraVector (char *vector1);

//Módulo de un vector
float moduloVector (char *vector1);

//Cambio a mayúsculas
void aMayusculas(char * vector1);

int main () {
	char mensaje[MAX];	//vector de caracteres
	float modulo;		//variable para cálculo del módulo

	//Inicializar
	mensaje[0]='h';
	mensaje[1]='o';
	mensaje[2]='l';
	mensaje[3]='a';
	mensaje[4]=' ';

	//mostrar el vector
	muestraVector(mensaje);

	//mostra su módulo
	modulo=moduloVector(mensaje);
	printf("Módulo de mensaje: %f\n", modulo);
	
	//a mayúsculas
	aMayusculas(mensaje);
	muestraVector(mensaje);

	return 0;
}

/**
void muestraVector (char *vector)	
Funcion:	muestraVector
Sinposis:	muestra por pantalla el contenido de un vector, elemento a elemento
@param		char *vector	E/ El vetor a representar
@return		nada
*/
void muestraVector (char *vector) {
	int i;		//Variable contador de bucle
	
	printf("\nContenido de vector");
	printf("\n-------------------\n");
	//Recorre el vector y muestra cada componente en formato v[i]=valor
	for (i=0; i<MAX; i++) {
		printf("\tv[%d]=%c\n", i, vector[i]);
	}
	return;
}

/**
float moduloVector (char *vector)	
Funcion:	moduloVector
Sinposis:	Calcula la operación matemática de módulo de un vector
@param		int *vector	E/ El vetor a representar
@return		el valor escalar del módulo
*/

float moduloVector (char *vector) {
	int i;		//variable de control de bucle
	int modulo=0;	//resultado del cálculo
	
	for (i=0;i<MAX;i++) {
		modulo+=vector[i]^2;	//Suma de cuadrados de posiciones
	}
	return (sqrt(modulo));	//Raiz de la suma anterior

}
/**
void aMayusculas (char *vector1)
Funcion:	aMayusculas
Sinposis:	Convierte los caracteres de un vector a mayúsculas
@param		char *vector	E/S El vector a tratar
@return		nada


*/
void aMayusculas (char *vector1) {
	int i;	//variable control de bucle
	for (i=0;i<MAX;i++) {
		vector1[i]-=32;
	}
	return;

}
