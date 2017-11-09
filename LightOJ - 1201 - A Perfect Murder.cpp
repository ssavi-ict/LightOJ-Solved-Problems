/*
The idea is simple . Just Bi-Color the graph. Suppose you did color with 1 & 2. 
Now as given in the input graph form another graph where node with color 1 will connect its adjacent nodes with color 2. 
Why just color 2? Is not it possible to have color 1 as an adjacent? 
No.
Because adjacent of all nodes with color 1 will be colored with color 2 and vice versa. 
Now run a Bipartite Matching. Figure out the result and subtract from total number of Nodes you have. 

Why this idea works??
Simple . 
In this problem you need to select maximum number nodes with minimized adjacent nodes.
So run a mathcing will always result the minimized match as the cost of edges are 1. 
So reducing total nodes into Total_Nodes - Matching() will produce the correct result. 
*/

#include<bits/stdc++.h>

using namespace std;

#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))
#define MAX 1005

vector < int > edges[MAX], graph[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];
int Color[MAX];
int n, m, u, v;

bool dfs(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    int len = edges[u].size(), i, v;
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(Right[v]==-1) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int match() {
    SET(Left);
    SET(Right);
    int i, ret = 0;
    bool done;
    do {
        done = true;
        CLR(visited);
        for(i=0; i<MAX; i++) {
            if(Left[i]==-1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i=0; i<MAX; i++) ret += (Left[i]!=-1);
    return ret;
}

void init()
{
    for(int i=0; i<=1002; i++){
        graph[i].clear();
        edges[i].clear();
        Color[i] = 0;
        visited[i] = false;
    }
}

void DO_Bicolor(int node, int color)
{
    visited[node] = true;
    Color[node] = color;
    for(int i=0; i<graph[node].size(); i++){
        int x = graph[node][i];
        if(!visited[x]){
            DO_Bicolor(x, color^1);
        }
    }
}


int main(){
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++){
        init();
        scanf("%d %d", &n, &m);
        for(int i=1; i<=m; i++){
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1; i<=n; i++){
            if(!visited[i]) DO_Bicolor(i, 0);
        }

        for(int i=1; i<=n; i++){
            if(Color[i]==0){
                for(int j=0; j<graph[i].size(); j++){
                    edges[i].push_back(graph[i][j]);
                    //cout<<i<<' '<<graph[i][j]<<endl;
                }
            }
        }
        //cout<<match()<<endl;
        printf("Case %d: %d\n", caseno, n - match());
    }
}
