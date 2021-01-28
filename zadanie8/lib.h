//
// Created by xkey on 28.01.2021.
//

#ifndef ZADANIE8_LIB_H
#define ZADANIE8_LIB_H
#include <stdlib.h>
struct neighborhood;

typedef struct node
{
    struct node *predecessor;
    int visited;
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

graph *createGraph(graph *head, int *s);

void DFS(node *head);
#endif //ZADANIE8_LIB_H
