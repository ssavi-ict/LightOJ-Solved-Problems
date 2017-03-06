#include<bits/stdc++.h>
#define MAX 20010
#define CLR(a,b) memset(a,b, sizeof(a))

using namespace std;

vector<int>graph[MAX];
char color[MAX];
bool visited[MAX];
set<int>myset;
set<int>::iterator it;

int bfs(int x)
{
    queue<int>q;
    int red=0, black=0;
    q.push(x);
    visited[x]=true;
    color[x]='B';
    black++;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(!visited[v])
            {
                q.push(v);
                if(color[u]=='B')
                {
                    color[v]='R';
                    red++;
                }
                else
                {
                    color[v]='B';
                    black++;
                }
                visited[v]=true;
            }
        }
    }
    return max(red,black);

}

int main()
{
    int test, caseno=0;
    scanf("%d", &test);
    while(test--)
    {
        int edges, x, y;
        scanf("%d",&edges);
        for(int i=0; i<edges; i++)
        {
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
            myset.insert(x);
            myset.insert(y);
        }
        int cnt = 0;
        CLR(visited,false);
        CLR(color,' ');
        for(it=myset.begin(); it!=myset.end(); ++it)
        {
            if(!visited[*it])
            {
                cnt = cnt + bfs(*it);
            }
        }
        printf("Case %d: %d\n",++caseno, cnt);
        for(int i=0; i<=MAX; i++)
            graph[i].clear();
        myset.clear();
    }
    return 0;
}
