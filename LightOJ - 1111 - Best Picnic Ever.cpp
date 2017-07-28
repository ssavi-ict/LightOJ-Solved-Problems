#include<bits/stdc++.h>
#define matclr(n, a) for(int i=0; i<=n; i++) a[i].clear()

using namespace std;

vector<int>graph[1004];
bool visited[1004];

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        int man, city, con, x, y, in;
        scanf("%d %d %d", &man, &city, &con);
        vector<int>mv;
        mv.clear();
        for(int i=0; i<man; i++)
        {
            scanf("%d",&in);
            mv.push_back(in);
        }
        matclr(1004, graph);
        for(int i=0; i<con; i++)
        {
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
        }
        map<int, int>mymap;
        map<int, int>::iterator it;
        for(int j=0; j<man; j++)
        {
            queue<int>q;
            q.push(mv[j]);
            memset(visited, false, sizeof(visited));
            visited[mv[j]] = true;
            mymap[mv[j]]++;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int i=0; i<graph[u].size(); i++)
                {
                    int v = graph[u][i];
                    if(!visited[v])
                    {
                        visited[v] = true;
                        q.push(v);
                        mymap[v]++;
                    }
                }
            }
        }
        int totvis = 0;
        for(it = mymap.begin(); it!=mymap.end(); ++it)
        {
            if(it->second==man)
            {
                totvis++;
            }
        }
        if(totvis)
            printf("Case %d: %d\n", caseno, totvis);
        else
            printf("Case %d: 0\n", caseno);
    }
        return 0;
}
