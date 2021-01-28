#include <stdio.h>
#include "lib.h"
int main() {
    graph  *head=NULL;
    int s,f;

    head = createGraph(head, &s);

    DFS(head->node);
//    printf("Hello, World!\n");
    return 0;
}
