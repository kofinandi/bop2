#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define ARRAY_MAX 5

using namespace std;

int compare(const void* a, const void* b) {
	double* da = (double*)a, * db = (double*)b;
	if (*da < *db)return -1;
	else if (*da == *db) return 0;
	else return 1;
}

int main() {
	double* d = new double[ARRAY_MAX];
	int i;
	for (i = 0; i < ARRAY_MAX; i++) {
		printf("Enter a number:");
		scanf("%lf", &d[i]);
	}
	qsort(d, ARRAY_MAX, sizeof(double), compare);
	for (i = 0; i < ARRAY_MAX; i++) {
		printf("%lf ", d[i]);
	}
	delete[] d;
	return 0;
}