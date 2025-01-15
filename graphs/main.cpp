#include<stdio.h>
#include"Queue.h"
#define I INT_MAX
using namespace std;

// BFS stand to Breadth First Search
void BFS(int G[][7], int start, int n) {
    int i = start, j;
    Queue q;
    int visited[7]={0};
    
    printf("%d ", i);
    visited[i] = 1;
    q.Enqueue(i);
    
    while(!q.IsEmpty()) {
        i = q.Dequeue();
        for(j=1;j<n;j++) {
            if(G[i][j]==1 && visited[j]==0) {
                printf("%d ", j);
                visited[j] = 1;
                q.Enqueue(j);
            }
        }
    }
}

// DFS stand to Depth First  Search
void DFS( int G[][7], int start, int n) {
    static int visited[7] = {0};
    
    if(visited[start]==0) {
        printf("%d ", start);
        visited[start] = 1;
        for(int j=1;j<n;j++) {
            if(G[start][j]==1 && visited[j]==0)
                DFS(G, j, n);
        }
    }
    
}


void Prims (int cost[8][8], int n) {
    int i,j,k=0,u=0,v=0,min=I;
    
    int near[8] = {I,I,I,I,I,I,I,I};
    int t[2][6];
    
    // searching who has minimum cost
    for(i=1;i<=n;i++) {
        for(j=i;j<=n;j++) {
            if(cost[i][j]<min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    
    // initialization t with result of  u and v, and also near in index u and v with 0
    t[0][0] = u;
    t[1][0] = v;
    near[u]=near[v]=0;
    
    // will make near = [-,0,1,6,6,6,6,0,6];
    for(i=1;i<=n;i++) {
        if(near[i]!=0){
            if(cost[i][u]<cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    
    //repeating code in above
    for(i=1;i<n-1;i++) {
        min = I;
        for(j=1;j<=n;j++) {
            if(near[j]!=0 && cost[j][near[j]]<min) {
                k = j;
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        
        for(j=1;j<=n;j++) {
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
                near[j] = k;
        }
    }

    //printing..
    for(i=0;i<n-1;i++)
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    
}


int main() {
    int cost[8][8] = {{I,I,I,I,I,I,I,I},
                    {I,I,25,I,I,I,5,I},
                    {I,25,I,12,I,I,I,10},
                    {I,I,12,I,8,I,I,I},
                    {I,I,I,8,I,16,I,14},
                    {I,I,I,I,16,I,20,18},
                    {I,5,I,I,I,20,I,I},
                    {I,I,10,I,14,18,I,I}};

    Prims(cost, 7);
    
    
    return 0;
}
