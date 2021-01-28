//
// Created by xkey on 28.01.2021.
//

#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

void printG(graph *head) {
    graph *current = head;
    neighborhood *neighbor = NULL;
    while (current) {
        printf("graf ID = %d( ", current->node->id);
        neighbor = current->node->neighborhood;
        while (neighbor) {
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
        newEl->node->visited = 0;
        newEl->node->neighborhood = NULL;
        newEl->node->id = id;
        current->next = newEl;

    } else {
        head = (graph *) malloc(sizeof(graph));
        head->before = NULL;
        head->next = NULL;
        head->node = (node *) malloc(sizeof(node));
        head->node->visited = 0;
        head->node->neighborhood = NULL;
        head->node->predecessor = NULL;
        head->node->id = id;

    }
    return head;
}


void addNeighborhood(int fromId, int toId, graph *head) {
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

graph *createGraph(graph *head, int *s) {
    int N, i, idTo;
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
                addNeighborhood(i, idTo, head);
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
        scanf("%d", s);
        if (*s >= 0 && *s < N) {
            break;
        }
        printf("prosze podaj prawidlowe ID\n");
    }

    return head;

}




void DFS(node *head) {
    head->visited = 1;
    neighborhood *current = head->neighborhood;
    printf("i'm in %d\n", head->id);
    while (current){
        if(current->node->visited == 0)
            DFS(current->node);
        current = current->next;
    }
}