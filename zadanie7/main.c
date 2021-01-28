//
// Created by xkey on 28.01.2021.
//
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647

int main() {
    int size, connect, help;
    printf("podaj ilosc elementow ");
    scanf("%d", &size);
    int tab[size][size];
    int i, j, n;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            tab[i][j] = INT_MAX;
        }
        tab[i][i] = 0;
    }

    // ustawienie polaczen
    printf("podaj liczbę połączeń \n");
    i = 0;
    while (i < size) {
        printf("podaj numer elemetu z ktorym chcesz polaczyc %d( %d zenby isc dalej )\n", i, i);
        scanf("%d", &connect);
        if (connect != -1 && connect != i) {
            printf("podaj wartos laczenia \n");
            scanf("%d", &help);
            tab[i][connect] = help;
        } else if (connect == i) {
            i++;
        }
    }


    // ALGORYTM Floyda-Warshalla
    for (n = 0; n < size; n++) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (tab[i][n] == INT_MAX || tab[n][j] == INT_MAX) continue;
                if ((tab[i][n] + tab[n][j]) < tab[i][j]) tab[i][j] = (tab[i][n] + tab[n][j]);
            }
        }
    }


    // Wypisanie dorgi
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("[%d][%d]=",i,j);
            if(tab[i][j]==INT_MAX)
                printf("brak dorgi\n");
            else
                printf("%d\n",tab[i][j]);
        }
    }

    return 0;
}