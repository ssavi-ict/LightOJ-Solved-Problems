#include<bits/stdc++.h>

using namespace std;

struct edge{
   int u, v, w;
   bool operator < (const edge& p) const{
       return w<p.w;
   }
};

vector<edge>graph;
int father[115];
int cost[55][55];
bool check[55][55];

int parent(int n)
{
    if(n==father[n]) return n;
    else return father[n] = parent(father[n]);
}

void MST(int n, int totcost)
{
    sort(graph.begin(), graph.end());
    for(int i=0; i<=n+5; i++)  father[i] = i;
    int cnt = 0, tot = 0;
    for(int i=0; i<graph.size(); i++)
    {
        int u = parent(graph[i].u);
        int v = parent(graph[i].v);
        if(u!=v)
        {
            tot = tot + graph[i].w;
            cnt++;
            father[u] = v;
            if(cnt==n-1) break;
        }
    }
    if(cnt==n-1) printf("%d\n", totcost-tot);
    else printf("-1\n");
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        memset(check, false, sizeof check);
        memset(cost, 0, sizeof cost);
        graph.clear();
        int n, x, u, v, w, total = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d", &cost[i][j]);
                total = total + cost[i][j];
            }
            cost[i][i] = 0;
        }
        edge get;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(!check[i][j] && !check[j][i])
                {
                    get.u = i;
                    get.v = j;
                    check[i][j] = check[j][i] = true;
                    if(cost[i][j]==0 && cost[j][i]==0) continue;
                    else if(cost[i][j]==0 || cost[j][i]==0)
                    {
                        get.w = max(cost[i][j], cost[j][i]);
                    }
                    else
                    {
                        get.w = min(cost[i][j], cost[j][i]);
                    }
                    graph.push_back(get);
                }
            }
        }
        printf("Case %d: ", caseno);
        MST(n, total);
    }
    return 0;
}

