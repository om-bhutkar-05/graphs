#include"functions.c"

int main(){
    graph g;
    initialize(&g,5);
    addedge(&g,4,1,3);
    addedge(&g,4,0,5);
    addedge(&g,4,2,8);
    addedge(&g,4,3,1);
    addedge(&g,2,1,3);
    addedge(&g,2,3,2);
    addedge(&g,3,0,8); 
    int a[5];
    // primMST(&g);
    // int n=g->numvertices;
  kruskalAlgo(&g);
}