#include "tp0.h"
#include <stdio.h>

void swap (int *x, int *y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}

int maximo(int vector[], int n){
	if(n <= 0) return -1;
	int pos = 0;
	for(int i = 0; i < n; i ++){
		if(vector[i] > vector[pos]) pos = i;
	}
	return pos;
}

int comparar(int vector1[], int n1, int vector2[], int n2) {
	for (int i=0,j=0; i<n1 || j<n2; i++, j++){
		if ((i == n1) && (j < n2)) return -1;
		if ((j == n2) && (i < n1)) return 1;
		if (vector1[i] < vector2[j]) return -1;
		if (vector1[i] > vector2[j]) return 1;
	}
    return 0;
}

void seleccion(int vector[], int n) {
	for(int i = n-1; i >= 0; i --){
		int max = maximo(vector, i+1);
		swap(&vector[max], &vector[i]);
	}
}