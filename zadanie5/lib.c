//
// Created by xkey on 22.01.2021.
//

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
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
    int i,j,gap;
    for(gap=n/2; gap>=1; gap/=2)
    {
        for(i=gap; i<n;i++)
        {
            for(j=i;i>=gap;j-=gap)
            {
                if(x[j-gap] > x[j])
                {
                    swap(x, j-gap, j);
                }else
                    break;
            }
        }
    }

    printArr(x, n);
}
