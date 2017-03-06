#include<bits/stdc++.h>
#define CLR(a,b) memset(a,b,sizeof(a))

using namespace std;

vector<int>graph[30005];
vector<int>cost[30005];
bool visited[30005];
int dis[30005];

void BFS(int x, int &y)
{
    CLR(visited,false);
    CLR(dis,0);
    queue<int>q;
   // while(!q.empty()){ q.pop(); }
    q.push(x);
    visited[x]=true;
    dis[x]=0;
    int maxi = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            int c = cost[u][i];
            if(!visited[v])
            {
                visited[v]=true;
                dis[v] = dis[u]+cost[u][i];
                if(dis[v]>maxi)
                {
                    maxi=dis[v];
                    y = v;
                }
                q.push(v);
            }
        }
    }

}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int nodes;
        scanf("%d", &nodes);
        for(int i=0; i<30005; i++)
            graph[i].clear();
        for(int i=0; i<30005; i++)
            cost[i].clear();
        for(int i=1; i<nodes; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            graph[x].push_back(y);
            graph[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        int s, t;
        BFS(0,s);
        BFS(s,t);
        printf("Case %d: %d\n", caseno, dis[t]);
    }
    return 0;
}
