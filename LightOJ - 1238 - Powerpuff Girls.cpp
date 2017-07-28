#include<bits/stdc++.h>
#define pii pair<int,int>
#define isvalid(x,y,m,n)(x>=0 && x<m && y>=0 && y<n)
#define CLR(a,b) memset(a, b, sizeof(a))
#define validchar(a,b,c,d, e) (a==b || a==c || a==d || a==e)

using namespace std;

int row, column;
char graph[23][23];
bool visited[23][23];
int cost[23][23];
int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

int BFS(int x, int y)
{
    queue<pii>q;
    CLR(visited,false);
    CLR(cost,0);
    q.push(pii(x,y));
    visited[x][y] = true;
    cost[x][y] = 0;
    graph[x][y]='.';
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int f = top.first + fx[i];
            int s = top.second + fy[i];
            if(graph[f][s]=='h')
            {
                cost[f][s] = cost[top.first][top.second] + 1;
                return cost[f][s];
            }
            if(isvalid(f,s,row,column) && !visited[f][s] && validchar(graph[f][s], '.', 'a', 'b','c'))
            {
                visited[f][s] = true;
                cost[f][s] = cost[top.first][top.second] + 1;
                q.push(pii(f,s));
            }
        }
    }
    return 0;
}

int main()
{
    int test, ax, ay, bx, by, cx, cy, dx, dy;
    scanf("%d",&test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%d %d", &row, &column);
        CLR(graph,'\0');
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                cin>>graph[i][j];
                if(graph[i][j]=='a'){ax = i, ay = j;}
                else if(graph[i][j]=='b'){bx = i, by = j;}
                else if(graph[i][j]=='c'){cx = i, cy = j;}
            }
        }
        int dist = max(BFS(ax,ay), max(BFS(bx,by), BFS(cx,cy)));
        printf("Case %d: %d\n",caseno, dist);
    }
    return 0;
}
