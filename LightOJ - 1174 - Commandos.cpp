#include<bits/stdc++.h>
#define INF 999999999

using namespace std;

int graph[100+5][100+5];

void init()
{
    for(int i=0; i<101; i++)
    {
        for(int j=0; j<101; j++)
        {
            if(i==j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int nodes, edges, u, v, s, d;
        scanf("%d %d",&nodes, &edges);
        init();
        for(int i=0; i<edges; i++)
        {
            scanf("%d %d",&u, &v);
            graph[u][v] = graph[v][u] = 1;
        }
        scanf("%d %d", &s, &d);
        for(int k=0; k<nodes; k++)
        {
            for(int i=0; i<nodes; i++)
            {
                for(int j=0; j<nodes; j++)
                {
                    graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
                }
            }
        }

        int maxval = -999999;
        for(int i=0; i<nodes; i++)
        {
            if(graph[s][i]<INF && graph[i][d]<INF)
            {
                maxval = max(maxval, graph[s][i]+graph[i][d]);
            }
        }
        printf("Case %d: %d\n", caseno, maxval);
    }
    return 0;
}
