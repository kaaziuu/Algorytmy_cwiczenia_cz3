
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
    int i, j, current;
    for (i = 0; i < n; i++) {
        current = i;
        for(j=i-1;j>=0;j--)
        {
            if(x[current] < x[j] )
            {
                swap(x, current, j);
                current =j;
//                printArr(x, n);

            }
            else{
                break;
            }
        }


    }
    printArr(x, n);
}
