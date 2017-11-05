#include<bits/stdc++.h>
#define LL long long

using namespace std;

int n, T;
vector<int>graph[1005];
int Left[1005], Right[1005];
bool visited[1005];
int arr[105], brr[105];
int nodeA[105], nodeB[105];

bool DFS(int u)
{
    if(visited[u]) return false;
    visited[u] = true;
    int len = graph[u].size();
    for(int i=0; i<len; i++){
        int v = graph[u][i];
        if(Right[v]==-1){
            Right[v] = u, Left[u] = v;
            return true;
        }
    }

    for(int i=0; i<len; i++){
        int v = graph[u][i];
        if(DFS(Right[v])){
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;

}

int BPM()
{
    memset(Left, -1, sizeof Left);
    memset(Right, -1, sizeof Right);
    int ret = 0;
    bool done;

    do{
        done = true;
        memset(visited, false, sizeof visited);
        for(int i=1; i<=n; i++){
            if(Left[i]==-1 && DFS(i)){
                done = false;
            }
        }
    }while(!done);

    for(int i=1; i<=n; i++){
        if(Left[i]!=-1) ret++;
    }
    return ret;
}

void init()
{
    for(int i=0; i<=105; i++){
        graph[i].clear();
        nodeA[i] = 0;
        nodeB[i] = 0;
        visited[i] = false;
    }
}

int main()
{
    //freopen("Out.txt", "w", stdout);
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++){
        init();

        int m, idx = 1;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", arr+i);
            nodeA[i] = idx++;
        }
        n = idx-1;

        idx =  1;
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            scanf("%d", brr+i);
            nodeB[i] = idx++;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((brr[j]%arr[i])==0){
                    graph[nodeA[i]].push_back(nodeB[j]);
                }
            }
        }

        printf("Case %d: %d\n",caseno, BPM());
    }
}
