//
// Created by xkey on 24.01.2021.
//
#define INTMAX 2147483647

#include "lib.h"
#include <stdio.h>


void printG(graph *head) {
    graph *current = head;
    neighborhood * neighbor = NULL;
    while (current) {
        printf("graf ID = %d( ", current->node->id);
        neighbor = current->node->neighborhood;
        while (neighbor)
        {
            printf(" %d ", neighbor->node->id);
            neighbor = neighbor->next;
        }
        printf(")\n");
        current = current->next;
    }
    printf("\n");
}

graph *addEmptyNode(graph *head, int id) {
    if (head != NULL) {
        graph *current = head;
        while (current->next) {
            current = current->next;
        }
        graph *newEl = malloc(sizeof(graph));
        newEl->before = current;
        newEl->next = NULL;
        newEl->node = (node *) malloc(sizeof(node));
        newEl->node->predecessor = NULL;
        newEl->node->fullCost = INTMAX;
        newEl->node->neighborhood = NULL;
        newEl->node->id = id;
        current->next = newEl;

    } else {
        head = (graph *) malloc(sizeof(graph));
        head->before = NULL;
        head->next = NULL;
        head->node = (node *) malloc(sizeof(node));
        head->node->fullCost = INTMAX;
        head->node->neighborhood = NULL;
        head->node->predecessor = NULL;
        head->node->id = id;

    }
    return head;
}

void addNeighborhood(int fromId, int toId, int cost, graph *head) {
    graph *current = head;
    graph *to = NULL;
    while (current->node->id != fromId) {
        if (current->node->id == toId) {
            to = current;
        }
        current = current->next;
    }
    if (to == NULL) {
        to = current;
        while (to->node->id != toId) {
            to = to->next;
        }
    }

    neighborhood *neighbor = current->node->neighborhood;
    neighborhood *new = (neighborhood *) malloc(sizeof(neighborhood));
    new->cost = cost;
    new->node = to->node;
    new->next = NULL;
    if (neighbor) {
        while (neighbor->next) {
            neighbor = neighbor->next;
        }
        neighbor->next = new;

    } else {
        current->node->neighborhood = new;
    }

}

graph *createGraph(graph *head, int *s, int *f) {
    int N, i, idTo, cost;
    printf("podaj liczbe krawedzi \n");
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        head = addEmptyNode(head, i);
    }
    printG(head);
    for (i = 0; i < N; i++) {
        while (1) {
            printf("proszę o podanie id docelowego punktu dla %d (-1 jesli chcesz przjesc do nastepnego) \n", i);
            scanf("%d", &idTo);
            if (idTo != -1 && idTo < N && idTo != i) {
                printf("prosze o podanie kosztu dojscia \n");
                scanf("%d", &cost);
                addNeighborhood(i, idTo, cost, head);
            } else if (idTo == -1) {
                break;
            } else {
                printf("nie właściwe ID\n");
            }
        }

    }
    printG(head);

    while (1) {
        printf("podaj id startowego grafu \n");
        scanf("%d",s);
        printf("podaj id koncowego grafu \n");
        scanf("%d",f);
        if(*s >=0 && *s < N && *f>=0 && *f<N)
        {
            break;
        }
        printf("prosze podaj prawidlowe ID\n");
    }

    return head;

}


graph *findById(graph *head, int id)
{
    while (head && head->node->id  != id)
    {
        head = head->next;
    }
    return  head;
}

graph *removeById(graph *head, int id)
{
    graph  *current = head;
    if(head && head->node->id != id)
    {
        while (current && current->node->id != id)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            current->before->next = current->next;
            if(current->next)
                current->next->before = current->before;
//            free(current);
        }
    }
    else if(head && head->node->id == id)
    {
        head = head->next;
//        free(current);
    }

    return  head;
}


graph *findTheSmallestCost(graph *head)
{
    graph *current = head;
    graph *theSmallest = head;
    while (current)
    {
        if(current->node->fullCost < theSmallest->node->fullCost)
        {
            theSmallest = current;
        }
        current = current->next;
    }
    return theSmallest;

}


graph *addToGraph(graph *head, node *add)
{
    graph  *newGraph = (graph*)malloc(sizeof (graph));
    newGraph->node = add;
    newGraph->next = NULL;
    if(head)
    {
        graph *current = head;
        while (current->next)
        {
            current = current->next;
        }
        newGraph->before = current;
        current->next = newGraph;
    }
    else{
        head = newGraph;
    }
    return head;
}

void printPath(graph *head, int s,  int f)
{

    graph *lastGraph = findById(head, f);
    node *current = lastGraph->node;
    for(; current; current = current->predecessor)
    {
        printf("%d->", current->id);
    }
    printf("\n pelen koszt podrozy to %d\n", lastGraph->node->fullCost);

}

void findPath(graph *head, int s,  int f)
{
    graph *S = NULL;
    graph *Q = head;
    graph *current = findById(Q, s);
    neighborhood  *neighbor = NULL;
    current->node->fullCost = 0;
    while (Q)
    {
        current = findTheSmallestCost(Q);
        Q = removeById(Q, current->node->id);
        S=addToGraph(S, current->node);
        neighbor = current->node->neighborhood;

        while (neighbor)
        {
            if(neighbor->node->fullCost > (current->node->fullCost + neighbor->cost))
            {
                neighbor->node->fullCost = current->node->fullCost + neighbor->cost;
                neighbor->node->predecessor = current->node;
            }
            neighbor = neighbor->next;
        }

    }
    printPath(S, s, f);

}