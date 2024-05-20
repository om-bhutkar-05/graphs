#include"header.h"

void initialize(graph *g,int vertices){
    g->numvertices=vertices;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
        g->vertices[i][j]=0;
      }
    }
}
void addedge(graph *g,int source,int destination,int weight){
    g->vertices[source][destination]=weight;
    g->vertices[destination][source]=weight;
}

void print(graph *g){
    for (int i = 0; i < g->numvertices; i++)
    {
      for (int j = 0; j < g->numvertices; j++)
      {
       printf("%d ",g->vertices[i][j]);
      }
      printf("\n");
    }
    
}

void isadjacent(graph *g,int v1,int v2){
if(g->vertices[v1][v2]>0){
    printf("true\n");
}
else{
    printf("false\n");
}
}

int getdegree(graph *g,int vertex){
    int degree=0;
    for(int i=0;i<g->numvertices;i++){
        if(g->vertices[vertex][i]>0){
            degree++;
        }
    }
    return degree;
}

void dfs(graph *g , int v, int* visited) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < g->numvertices; i++)
    {
       if(g->vertices[v][i]!=0 && !visited[i]){

        dfs(g,i,visited);
       }
    }

}

void bfs(graph *g , int v, int* visited) {
visited[v]=1;
int q[100];
int front=0;
int rear=0;
 q[rear++]=v;

 while(rear!=front){
    for(int i=0;i<g->numvertices;i++){
        if(g->vertices[v][i]!=0 && !visited[i]){
            visited[i]=1;
            q[rear++]=i;
        }
    }
 printf(" %d ",q[front++]);
v=q[front];
 }
}

int isconnected(graph *g){
    int visited[100];
    for (int i = 0; i < g->numvertices; i++)
    {
        visited[i]=0;
    }
    dfs(g,0,visited);
    for (int i = 0; i < g->numvertices; i++)
    {
        if(visited[i]==0){
            return 0;
        }
    }
    
return 1;
}
#define V 100
int minKey(int key[], bool mstSet[])
{

    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

int printMST(int parent[], graph *g)
{
    printf("g->vertices \tWeight\n");
    for (int i = 1; i < g->numvertices; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               g->vertices[i][parent[i]]);
}
 
void primMST(graph *g)
{

    int parent[V];
   
    int key[V];
 
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
 
    key[0] = 0;
   
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
         

        int u = minKey(key, mstSet);
 
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
 
            if (g->vertices[u][v] && mstSet[v] == false && g->vertices[u][v] < key[v])
                parent[v] = u, key[v] = g->vertices[u][v];
    }
    printMST(parent, g);
}

int comparator(const void* p1, const void* p2) 
{ 
    const int (*x)[3] = (const int (*)[3])p1; 
    const int (*y)[3] = (const int (*)[3])p2; 
  
    return (*x)[2] - (*y)[2]; 
} 

void makeSet(int parent[], int rank[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        parent[i] = i; 
        rank[i] = 0; 
    } 
} 
  
int findParent(int parent[], int component) 
{ 
    if (parent[component] == component) 
        return component; 
  
    return parent[component] = findParent(parent, parent[component]); 
} 
  
void unionSet(int u, int v, int parent[], int rank[], int n) 
{ 
    u = findParent(parent, u); 
    v = findParent(parent, v); 
  
    if (rank[u] < rank[v]) { 
        parent[u] = v; 
    } 
    else if (rank[u] > rank[v]) { 
        parent[v] = u; 
    } 
    else { 
        parent[v] = u; 
        rank[u]++; 
    } 
} 
 void kruskalAlgo(graph *g) 
{ 
    int num_edges = 0;
    for (int i = 0; i < g->numvertices; i++) {
        for (int j = i + 1; j < g->numvertices; j++) {
            if (g->vertices[i][j] != 0) {
                num_edges++;
            }
        }
    }
  
    int (*edges)[3] = malloc(num_edges * sizeof(edges[0]));
    if (edges == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    int idx = 0;
    for (int i = 0; i < g->numvertices; i++) {
        for (int j = i + 1; j < g->numvertices; j++) {
            if (g->vertices[i][j] != 0) {
                edges[idx][0] = i;
                edges[idx][1] = j;
                edges[idx][2] = g->vertices[i][j];
                idx++;
            }
        }
    }

    qsort(edges, num_edges, sizeof(edges[0]), comparator);
  
    int parent[100]; 
    int rank[100]; 
  
    makeSet(parent, rank, g->numvertices); 
  
    int minCost = 0; 
  
    printf("Following are the edges in the constructed MST\n"); 
    for (int i = 0; i < num_edges; i++) { 
        int v1 = findParent(parent, edges[i][0]); 
        int v2 = findParent(parent, edges[i][1]); 
        int wt = edges[i][2]; 
  
        if (v1 != v2) { 
            unionSet(v1, v2, parent, rank, g->numvertices); 
            minCost += wt; 
            printf("%d -- %d == %d\n", edges[i][0], edges[i][1], wt); 
        } 
    } 
  
    printf("Minimum Cost Spanning Tree: %d\n", minCost); 
}
