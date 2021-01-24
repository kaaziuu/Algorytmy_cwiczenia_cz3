#include <stdio.h>
#include "lib.h"
int main() {
    graph  *map=NULL;
    int s,f;

    map = createGraph(map, &s, &f);

    findPath(map, s, f);
//    printf("Hello, World!\n");
    return 0;
}
