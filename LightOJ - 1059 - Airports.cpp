#include<bits/stdc++.h>
#define LL long long

using namespace std;

struct edge{
   LL u, v, w;
   bool operator < (const edge& p) const{
        return w<p.w;
   }
};

vector<edge>graph;
int father[10015];

int parent(int n)
{
    if(father[n]==n) return n;
    else return father[n] = parent(father[n]);
}

void MST(int n, LL air)
{
    sort(graph.begin(), graph.end());
    int cnt = 0, st = 0;
    LL tot = 0;
    for(int i=0; i<=n+5; i++)  father[i] = i;

    for(int i=0; i<graph.size(); i++)
    {
        LL u = parent(graph[i].u);
        LL v = parent(graph[i].v);
        LL w = graph[i].w;
        if(u!=v)
        {
            cnt++;
            father[u] = v;
            if(w>=air){
                st++;
                tot = tot + air;
            }
            else tot = tot + w;
            if(cnt==n-1) break;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(parent(father[i])==i)
        {
            st++;
            tot = tot + air;
        }
    }
    printf("%lld %d\n", tot, st);
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        graph.clear();
        LL m, air, u, v, w;
        int n;
        scanf("%d %lld %lld", &n, &m, &air);
        for(int i=0; i<m; i++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            edge get;
            get.u = u; get.v = v; get.w = w;
            graph.push_back(get);
        }
        printf("Case %d: ", caseno);
        MST(n, air);
    }
    return 0;
}

