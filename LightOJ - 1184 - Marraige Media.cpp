#include<bits/stdc++.h>
#define LL long long

using namespace std;

struct data{
    int hi, age, div;
};

int n, m;
vector<int>graph[1005];
int Left[1005], Right[1005];
bool visited[1005];
data arr[105], brr[105];

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
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++){
            scanf("%d %d %d", &arr[i].hi, &arr[i].age, &arr[i].div);
        }
        for(int i=1; i<=m; i++){
            scanf("%d %d %d", &brr[i].hi, &brr[i].age, &brr[i].div);
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(abs(arr[i].hi - brr[j].hi)<=12 && abs(arr[i].age - brr[j].age)<=5 && arr[i].div==brr[j].div){
                    graph[i].push_back(j);
                }
            }
        }

        printf("Case %d: %d\n", caseno, BPM());

    }
}
