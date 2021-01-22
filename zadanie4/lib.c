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

void sort3(int x[], int n) {
    int j, i;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (x[j] > x[j + 1]) {
                swap(x, j, j + 1);
            }
        }
//        printArr(x, n);

    }
    printArr(x, n);

}

void sort3a(int x[], int n) {
    int j, i, k, nk;
    k = n - 1;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < k; j++) {
            if (x[j] > x[j + 1]) {
                swap(x, j, j + 1);
                nk = j + 1;
            }
        }
        k = nk;
//        printArr(x, n);

    }
    printArr(x, n);

}

void sort3b(int x[], int n) {
    int j, i, s, ns;
    s = 0;
    for (i = 0; i < n - 1; i++) {
        ns = -1;
        for (j = s; j < n - 1; j++) {
            if (x[j] > x[j + 1]) {
                if (ns == -1)
                    ns = j;
                swap(x, j, j + 1);
            }
        }
        s = ns;
//        printArr(x, n);

    }
    printArr(x, n);

}

void sort3cd(int x[], int n) {
    int i, s;
    s = 0;
    int sorted = 0;
    int target = n - 1;
    int mod = 1;
    while (!sorted) {
        sorted=1;
        for (i = s; i != target; i += mod) {
            if(x[i] > x[i+1]) {
                swap(x, i, i + 1);
                sorted=0;
            }
//            printArr(x, n);


        }
        target = s;
        s=i;
        mod *= -1;
        if (mod==-1)
        {
            target -= 1;//z powodu warnku if != przy schodzeniu w dol target trzeba obnizyc o 1
        }
    }
    printArr(x, n);

}