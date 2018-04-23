/*
Programa:	matrices.c
Sinopsis:	Implementar algunas operaciones sencillas con matrices

@author:	Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include <stdio.h>
#include <math.h>
#define FILAS 3
#define COLUMNAS 3


//Prototipos empleados
void muestraMatriz (int matriz[FILAS][COLUMNAS]);
void sumaMatrices (int matriz1[FILAS][COLUMNAS], int matriz2[FILAS][COLUMNAS], int resultado[FILAS][COLUMNAS]);

int main() {
	//Podemos declarar e inicializar a la vez
	//Como vector de vectores
	int matriz1[FILAS][COLUMNAS]={{1,2,3},{4,5,6}, {7,8,9}};
	int matriz2[FILAS][COLUMNAS]={{9,8,7},{6,5,4},{3,2,1}};
	int resultado[FILAS][COLUMNAS];	//Resultado de cálculos

	//Mostramos las matrices
	muestraMatriz (matriz1);
	muestraMatriz (matriz2);

	//Realizamos la suma
	sumaMatrices (matriz1, matriz2, resultado);
	
	//Mostramos resultado
	muestraMatriz (resultado);



	return 0;
}
/**
void muestraMatriz (int *matriz)	
Funcion:	muestraMatriz
Sinposis:	muestra por pantalla el contenido de una matriz bidimensional
		organizada en filas y columnas
@param		int *matriz	E/ La matriz bidimensional a representar
@return		nada
*/
void muestraMatriz (int matriz[FILAS][COLUMNAS]) {
	int fil, col;		//Variables contador de bucle
	
	printf("\nContenido de matriz");
	printf("\n-------------------\n");
	//Recorre la matriz y muestra cada componente en formato m[i][j]=valor
	for (fil=0; fil<FILAS; fil++) {
		for (col=0;col<COLUMNAS;col++) {
			printf("\tm[%d][%d]=%d", fil,col, matriz[fil][col]);
		}
		printf("\n");
	}
	return;
}


/**
void sumaMatrices int matriz1[FILAS][COLUMNAS], int matriz2[FILAS][COLUMNAS], int resultado[FILAS][COLUMNAS])

Funcion:	muestraMatriz
Sinposis:	Suma elemento a elemento dos matrices de las mismas dimensiones
@param		int matriz1[FILAS][COLUMNAS]	E/ La matriz primer sumando
@param		int matriz2[FILAS][COLUMNAS]	E/ La matriz segundo sumando
@param		int resultado[FILAS][COLUMNAS] 	S/ La matriz resultante
@return		nada
*/

void sumaMatrices(int matriz1[FILAS][COLUMNAS], int matriz2[FILAS][COLUMNAS], int resultado[FILAS][COLUMNAS]) {
	int fil, col;	//Variables de control de bucle para filas y columnas

	for (fil=0;fil<FILAS;fil++) {
		for (col=0;col<COLUMNAS;col++) {
			//Cáculo de cada componente por suma de homólogos
			resultado[fil][col]=matriz1[fil][col]+matriz2[fil][col];
		}
	}

	return;
}

