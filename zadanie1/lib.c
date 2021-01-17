//
// Created by xkey on 17.01.2021.
//

#include "lib.h"

void printArr(int x[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
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
    int i, j, currentMin;
    for (i = 0; i < n; i++) {
        currentMin = i;
        for(j=i+1;j<n;j++)
        {
            if(x[j] < x[currentMin])
            {
                currentMin = j;
            }
        }
        swap(x, i, currentMin);

    }
    printArr(x, n);
}
