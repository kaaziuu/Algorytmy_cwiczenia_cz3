//
// Created by xkey on 24.01.2021.
//

#ifndef ZADANIE6_LIB_H
#define ZADANIE6_LIB_H
#include <stdlib.h>
struct neighborhood;

typedef struct node
{
    struct node *predecessor;
    int fullCost;
    int id;
    struct neighborhood *neighborhood;
} node;

typedef struct neighborhood
{
    node *node;
    int cost;
    struct  neighborhood *next;
}neighborhood;

typedef struct graph
{
    node *node;
    struct graph *before;
    struct graph *next;
} graph;

graph *createGraph(graph *head, int *s, int *f);

void findPath(graph *head, int s,  int f);
#endif //ZADANIE6_LIB_H
