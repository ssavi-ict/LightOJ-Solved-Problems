#include<bits/stdc++.h>
#define LL long long

using namespace std;

int n, m;
vector<int>graph[1005];
int Left[1005], Right[1005];
bool visited[1005];
char str[25][25];
int node[25][25];

int dx4[] = {1, -1, 0, 0};
int dy4[] = {0, 0, 1, -1};

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
    for(int i=0; i<500; i++){
        graph[i].clear();
    }
    memset(node, 0, sizeof node);
}

int main()
{
    //freopen("Out.txt", "w", stdout);
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++){
        init();
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++){
            scanf("%s", &str[i]);
        }
        int wdx = 0, bdx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(str[i][j]=='*'){
                    if( (i+j)%2 == 1 )node[i][j] = ++bdx;
                    else node[i][j] = ++wdx;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i+j)%2==0 && str[i][j]=='*'){
                    for(int l=0; l<4; l++){
                        int x = i + dx4[l], y = j + dy4[l];
                        if(x>=0 && x<n && y>=0 && y<m && str[x][y]=='*'){
                            graph[node[i][j]].push_back(node[x][y]);
                        }
                    }
                }
            }
        }
        n = wdx;

        printf("Case %d: %d\n", caseno, (bdx + wdx) - BPM());
    }
}

