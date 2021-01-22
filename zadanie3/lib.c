#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

void printArr(int x[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int *generateArr(int n) {
    int *arr = (int *) malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printArr(arr, n);
    return arr;

}


void swap(int x[], int i, int j) {
    int tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
}


void sort(int x[], int n) {
    int i, j, v, is, ie, tmp;
    for (i = n-2; i >= 0; i--) {
        v = x[i];
        is = i;
        ie = n;
        while ((ie - is) > 1) {
            tmp = (ie + is) / 2;
            if (v <= x[tmp])
                ie = tmp;
            else
                is = tmp;
        }

        for (j = i; j < is; j++) {
            x[j] = x[j + 1];
        }
        x[is] = v;
//        printArr(x, n);

    }
    printArr(x, n);
}
