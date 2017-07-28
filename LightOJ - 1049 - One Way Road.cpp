#include<bits/stdc++.h>
#define CLR(a,b) memset(a, b, sizeof(a))

using namespace std;

vector<int>graph[101];
bool connect[101][101];
bool visited[104];
int cost[101][101], total;

int BFS(int src , int dest, int total, int nodes)
{
    queue<int>q;
    q.push(src);
    int price = 0;
    while(!q.empty())
    {
        int u = q.front(), v;
        for(int i=0; i<graph[u].size(); i++)
        {
            for(int i=1; i<=nodes; i++)
            {
                if(!visited[i] && connect[u][i])
                {
                    v = i;
                }
                else
                    continue;
            }
            if(!visited[v])
            {
                visited[v] = true;
                //cout<<"Cost: "<<cost[u][v]<<endl;
                if(cost[u][v]<0)
                    price = price + abs(cost[u][v]);
                q.push(v);
                break;
            }
        }
         q.pop();
    }
    return min(price, total-price);
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        CLR(connect, false); CLR(cost, 0);
        CLR(visited, false);
        for(int i=0; i<=101; i++) graph[i].clear();
        int u, v, w, contact;
        total = 0;
        scanf("%d", &contact);
        for(int i=0; i<contact; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            connect[u][v] = true;
            connect[v][u] = true;
            cost[u][v] = w;
            cost[v][u] = (-1) * w;
            total = total + w;
        }
        printf("Case %d: %d\n", caseno, BFS(1,1, total, contact));
    }
    return 0;
}
