#include<bits/stdc++.h>
#define CLR(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>

using namespace std;

int w, h, cnt;
char graph[21][21];
int fx[]={1, -1, 0, 0};
int fy[]={0, 0, 1, -1};

void bfs(int x, int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    graph[x][y]='#';
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        cnt++;
        for(int i=0; i<4; i++)
        {
            int f = top.first + fx[i];
            int s = top.second + fy[i];
            if(f>=0 && f<h && s>=0 && s<w && graph[f][s]=='.')
            {
                graph[f][s]='#';
                q.push(pii(f,s));
            }
        }
    }
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%d %d", &w, &h);
        getchar();
        int ii, jj;
        for(int i=0; i<h; i++)
        {
            gets(graph[i]);
        }
        cnt = 0;
        bool flag = false;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(graph[i][j]=='@')
                {
                    bfs(i,j);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        printf("Case %d: %d\n",caseno, cnt);
    }
    return 0;
}
