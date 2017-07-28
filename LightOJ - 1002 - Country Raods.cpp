#include<bits/stdc++.h>
#define MAX 16020

using namespace std;

vector<int>graph[MAX], cost[MAX];

struct node
{
    int u, w;
    node(int a, int b) { u = a; w = b;}
    bool operator <(const node& p) const { return w>p.w; }
};

int d[MAX], par[MAX];

void dijkstra(int src, int n)
{
    for(int i=0; i<n; i++) d[i] = INT_MAX;
    //memset(d, 63, sizeof(d));
    priority_queue<node>pq;
    pq.push(node(src,0));
    d[src] = 0;
    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();
        int u = top.u;
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(d[v]>max(d[u], cost[u][i]))
            {
                d[v] = max(d[u], cost[u][i]);
                pq.push(node(v,d[v]));
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(d[i]>=INT_MAX) printf("Impossible\n");
        else printf("%d\n", d[i]);
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        for(int i=0; i<=MAX; i++)
        {
            graph[i].clear();
            cost[i].clear();
        }
        int nd, ed, u, v, w, src;
        scanf("%d %d", &nd, &ed);
        for(int i=0; i<ed; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        scanf("%d", &src);
        printf("Case %d:\n", caseno);
        dijkstra(src, nd);
    }
    return 0;
}
