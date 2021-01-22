#include "lib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    srand(time(NULL));
    int n;
    printf("podaj liczbe elementow w tablicy \n");
    scanf("%d", &n);
    int *x = generateArr(n);
//    int x[5] = {52, 38, 0, 16, 86};
    sort3cd(x, n);
    return 0;
}
