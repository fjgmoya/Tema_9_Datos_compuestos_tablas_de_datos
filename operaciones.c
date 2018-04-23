/*
Programa:	operaciones.c
Sinopsis:	Pequeña demo para implementar operaciones sencillas con vectores
		unidimensionales
@author:	Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include <stdio.h>
#include <math.h>
#define MAX 5


//Prototipos empleados


//** Operaciones monarias: un sólo vector *******************************

//Búsqueda de un valor en un vector, indicando la primera posición de ese valor
int indiceEnVector (int *vector1, int valor);

//Módulo de un vector
float moduloVector (int *vector1);

//Ordenar un vector: permite una ordenación sencilla en orden ascendente
void ordenaVector (int *vector1, int *ordenado);

//Muestra el contenido del vector por consola
void muestraVector (int *vector1);


//** Operaciones binarias con vectores
//Suma de vectores
void sumaVectores (int *vector1, int *vector2, int *resultado);


int main () {
	int mivector1[MAX]={3, 7, -1, 2, 5}; //inicializado de forma directa
	int mivector2[MAX];	//Operandos vectores
	int resultado[MAX];	//resultado de operaciones
	float modulo;		//módulo de un vector	
	int indice;		//índice o posición de un valor delntro del vector

	//Inicializamos los vectores
	
	//Este posición a posición
	mivector2[0] = 5;
	mivector2[1] = 0;
	mivector2[2] = -2;
	mivector2[3] = -7;
	mivector2[4] = 1;

	//Vemos el contenido de ambos
	muestraVector(mivector1);
	muestraVector(mivector2);

	//módulo de ambos vectores
	modulo=moduloVector(mivector1);
	printf("Módulo de vector1: %f\n", modulo);
	modulo=moduloVector(mivector2);
	printf("Módulo de vector2: %f\n", modulo);

	//buscamos el 2 en vector1
	indice=indiceEnVector(mivector1, 2);
	printf("Indice de 2 en vector1: %d\n", indice);


	//buscamos el 0 en vector1
	indice=indiceEnVector(mivector1, 0);
	printf("Indice de 0 en vector1: %d\n", indice);

	//ordenamos
	ordenaVector(mivector1, resultado);
	muestraVector(resultado);

	//sumamos vectores
	sumaVectores(mivector1, mivector2, resultado);
	muestraVector(resultado);

	return 0;
}

/**
void muestraVector (int *vector)	
Funcion:	muestraVector
Sinposis:	muestra por pantalla el contenido de un vector, elemento a elemento
@param		int *vector	E/ El vetor a representar
@return		nada
*/
void muestraVector (int *vector) {
	int i;		//Variable contador de bucle
	
	printf("\nContenido de vector");
	printf("\n-------------------\n");
	//Recorre el vector y muestra cada componente en formato v[i]=valor
	for (i=0; i<MAX; i++) {
		printf("\tv[%d]=%d\n", i, vector[i]);
	}
	return;
}
/**
float moduloVector (int *vector)	
Funcion:	moduloVector
Sinposis:	Calcula la operación matemática de módulo de un vector
@param		int *vector	E/ El vetor a representar
@return		el valor escalar del módulo
*/

float moduloVector (int *vector) {
	int i;		//variable de control de bucle
	int modulo=0;	//resultado del cálculo
	
	for (i=0;i<MAX;i++) {
		modulo+=vector[i]^2;	//Suma de cuadrados de posiciones
	}
	return (sqrt(modulo));	//Raiz de la suma anterior

}

/**
int indiceEnVector (int *vector)	
Funcion:	indiceEnVector
Sinposis:	Calcula la operación matemática de módulo de un vector
@param		int *vector	E/ El vetor a representar
@return		el índice entre 0 y MAX de la primera posición del valor buscado
		-1 en caso de no hallarlo
*/

int indiceEnVector (int *vector, int buscado) {
	int i;	//variable de control de bucle;
	int encontrado=0;	//ofrece 1 si al comparar el valor buscado con 
				//una posición del vector, ambos coinciden	
	
	//observa la condición de permanencia, que es doble condición
	for (i=0; (i< MAX && encontrado==0);i++) {	
		encontrado=vector[i]==buscado;	//descifralo
	}
	if (encontrado==1)
		return --i;	//i ya se ha actualizado. Posición anterior
	else
		return -1;	//-1 al no hallarlo	
}

/**
void ordenaVector (int *vector, int *ordenado)	
Funcion:	ordenaVector
Sinposis:	Ordena el contenido de un vector de forma creciente
		Ofrece como salida la posición inicial del vector ordenado

@param		int *vector	E/ El vector a ordenar
@param		int *ordenado 	S/ el vector ordenado 
@return nada
*/

void ordenaVector (int *vector, int *ordenado) {
	int i;		//Variable de control de bucle para recorrer posiciones
	int noorden;	//Variable para indicar el principio del vector no ordenado
	int minimo;		//Valor más pequeño encontrado
	int indice_minimo;	//Posición del más pequeño encontrado
	int auxiliar;		//variable auxiliar para un intercambio

	//En principio, partiremos de noorden=0 entendiendo que el vector no está ordenado.
	//Buscaremos el valor más pequeño de la parte no ordenada y lo depositaremos en pos
		
	//repetiremos esto mismo desde noroden+1, hasta llegar a MAX-1


	//volcamos a ordenado el vector como está
	for (i=0;i<MAX;i++) {
		ordenado[i]=vector[i];
	}
	//Bucle externo que controla el subvector ordenado
	for (noorden=0; noorden < MAX-1;noorden++) {
		//1. Encuentra el valor más pequeño
		minimo=ordenado[noorden];
		indice_minimo=noorden;
		for (i=noorden;i<MAX;i++) {
			if (ordenado[i]<minimo) {
				minimo=ordenado[i];
				indice_minimo=i;
			}
		}
		
		//2. Intercambiamos posiciones
		auxiliar= ordenado[noorden];
		ordenado[noorden]=minimo;
		ordenado[indice_minimo]=auxiliar;

	}
	return;
}

/**
void sumaVectorres (int *vector1, int *vector2, int *resultado)	
Funcion:	sumaVectores
Sinposis:	Realia la suma componente a componente

@param		int *vector1, int *vector2	E/ El vector a ordenar
		int *resultado 	S/ el vector suma
@return nada
*/
void sumaVectores (int *vector1, int *vector2, int *resultado) {
	int i;	//variable de control de bucle

	for (i=0;i<MAX;i++) {
		resultado[i]=vector1[i]+vector2[i];
	}	
	return;	

}


