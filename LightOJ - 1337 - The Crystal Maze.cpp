#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define PB(a, b) a.push_back(b)
#define PB2(a,i,b) a[i].push_back(b)
#define LL long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define II(a) scanf("%I64d", &a)
#define PP(a) printf("%I64d", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define pii2 pair<int, pii>
#define MAX 1000
#define MAXN 100007
#define logbase(a, b) ( log10(a)/log10(b) )
#define DIR(f,s,R,C) (f>=0 && f<R && s>=0 && s<C)

using namespace std;

int M, N, Q;
bool visited[505][505];
int temp[505][505];
char grid[505][505];
int level[200003];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct data{
    int u, v;
};


int BFS(int srcx, int srcy, int ptr)
{
    int tot = 0;
    queue<data>q;
    data D, Z;
    D.u = srcx; D.v = srcy;
    q.push(D);
    visited[srcx][srcy] = true;
    temp[srcx][srcy] = ptr;
    if(grid[srcx][srcy]=='C') tot++;

    while(!q.empty())
    {
        D = q.front();
        q.pop();
        int u = D.u;
        int v = D.v;
        for(int i=0; i<4; i++)
        {
            int s = u + dx[i];
            int t = v + dy[i];
            if(!visited[s][t] && grid[s][t]!='#' && (s>=1 && s<=M && t>=1 && t<=N))
            {
                visited[s][t] = true;
                temp[s][t] = ptr;
                if(grid[s][t]=='C')
                {
                    tot++;
                }
                Z.u = s; Z.v = t;
                q.push(Z);
            }
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
        ERASE(visited, false);
        ERASE(temp, 0);
        ERASE(level, 0);
        scanf("%d %d %d\n", &M, &N, &Q);

        for(int i=1; i<=M; i++)
        {
            for(int j=1; j<=N; j++)
            {
                scanf("%c", &grid[i][j]);
            }
            getchar();
        }

        int cnt = 1;
        for(int i=1; i<=M; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(grid[i][j]=='#')
                {
                    visited[i][j] = true;
                    temp[i][j] = 0;
                }
                else if(!visited[i][j])
                {
                    level[cnt] = BFS(i, j, cnt);
                    cnt++;
                }
            }
        }


        printf("Case %d:\n", caseno);
        for(int i=0; i<Q; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", level[temp[x][y]]);
        }
    }
}




