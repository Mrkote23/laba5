
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNING

#include "stdio.h"
#include <stdlib.h>
#include "conio.h"
#include "malloc.h"
#include <locale>
#include <queue>


using namespace std;






void bfs(int v, int** arr, bool* num, int m) {


	queue <int> q;
	q.push(v);
	num[v] = true;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		printf("%d, ", v);


		for (int j = 0; j < 6; j++) {
			if ((arr[v][j] == 1) && (num[j] == false)) { q.push(j); num[j] = true; }

		}
	}


}



void main() {


	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int n;

	printf("¬ведите размер массива: ");
	scanf("%d", &n);

	int** arr1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr1[i] = (int*)malloc(n * sizeof(int));
	}

	bool* numa = (bool*)malloc(n * sizeof(bool));



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			arr1[i][j] = rand() % 2;


		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			arr1[j][i] = arr1[i][j];
			if (i == j) { arr1[i][j] = 0; }
			printf("%d  ", (arr1[i][j]));

		}
		printf("\n");
	}




	printf("\n\n\n");


	for (int i = 1; i < n; i++) {

		numa[i] = false;

	}


	bfs(0, arr1, numa, n);





}



