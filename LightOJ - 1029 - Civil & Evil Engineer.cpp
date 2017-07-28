#include<bits/stdc++.h>

using namespace std;

struct edge{
    int u, v, w;
    bool operator < (const edge& p) const{
         return w<p.w;
    }
    bool operator > (const edge& p) const{
         return w>p.w;
    }

};

vector<edge>graph;
int father[115];

int parent(int n)
{
    if(father[n]==n) return n;
    else return father[n] = parent(father[n]);
}

int MST(int n, int ch)
{
    if(ch==1) sort(graph.begin(), graph.end());
    else sort(graph.begin(), graph.end(), greater<edge>());

    int cnt = 0, tot = 0;
    for(int i=0; i<=n+5; i++) father[i] = i;
    for(int i=0; i<graph.size(); i++)
    {
        int u = parent(graph[i].u);
        int v = parent(graph[i].v);
        if(u!=v)
        {
            father[u] = v;
            tot = tot + graph[i].w;
            cnt++;
            if(cnt==n) break;
        }
    }
    return tot;
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int n, u, v, w;
        graph.clear();
        scanf("%d", &n);
        while(scanf("%d %d %d", &u, &v, &w)==3)
        {
            if(u==0 && v==0 && w==0) break;
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            graph.push_back(get);
        }
        int one = MST(n, 1);
        int two = MST(n, 2);
        if((one+two)%2 == 0)
            printf("Case %d: %d\n", caseno, (one+two)/2);
        else
            printf("Case %d: %d/2\n", caseno, (one+two));
    }
    return 0;
}

