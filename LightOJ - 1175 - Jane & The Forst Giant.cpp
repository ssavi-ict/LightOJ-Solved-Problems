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
#define DIR1(f,s,R,C) (f>=1 && f<=R && s>=1 && s<=C)

using namespace std;

char grid[204][204];
bool visited[204][204];
int levelF[204][204], levelJ[204][204];
bool visitedF[204][204], visitedJ[204][204];
vector<pii>F;
int M, N, srcfx, srcfy, srcjx, srcjy;
int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};

void BFS()
{
    queue<pii>q;
    int sz = F.size();
    for(int i=0; i<sz; i++)
    {
        int u = F[i].first;
        int v = F[i].second;
        q.push(pii(u, v));
        visitedF[u][v] = true;
        levelF[u][v] = 0;
    }

    while(!q.empty())
    {
        pii top = q.front();
        int u = top.first;
        int v = top.second;
        //cout<<u<<' '<<v<<endl;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int f = u + fx[i];
            int s = v + fy[i];

            if(!visitedF[f][s] && DIR1(f,s,M,N) && (grid[f][s]=='.'))
            {
                visitedF[f][s] = true;
                levelF[f][s] = levelF[u][v] + 1;
                q.push(pii(f,s));
            }
        }
    }
}

int BFSAG()
{
    queue<pii>q;
    q.push(pii(srcjx, srcjy));
    visitedJ[srcjx][srcjy] = true;
    levelJ[srcjx][srcjy] = 0;
    while(!q.empty())
    {
        pii top = q.front();
        int u = top.first;
        int v = top.second;
        //cout<<u<<' '<<v<<' '<<levelJ[u][v]<<endl;
        q.pop();
        if(u==1 || u==M || v==N || v==1) return levelJ[u][v] + 1;

        for(int i=0; i<4; i++)
        {
            int f = u + fx[i];
            int s = v + fy[i];
            if(!visitedJ[f][s] && DIR1(f,s, M,N) && grid[f][s]=='.' && (levelJ[u][v] + 1<levelF[f][s]))
            {
                visitedJ[f][s] = true;
                levelJ[f][s] = levelJ[u][v] + 1;
                q.push(pii(f,s));
            }
        }
    }
    return -1;
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        for(int i=0; i<=201; i++)
        {
            for(int j=0; j<=201; j++)
            {
                visitedF[i][j] = false; visitedJ[i][j] = false;
                levelF[i][j] = 99999999; levelJ[i][j] = 99999999;
            }
        }
        F.clear();

        scanf("%d %d\n", &M, &N);
        for(int i=1; i<=M; i++)
        {
            for(int j=1; j<=N; j++)
            {
                scanf("%c", &grid[i][j]);
                if(grid[i][j]=='J')  srcjx = i, srcjy = j;
                if(grid[i][j]=='F'){
                    F.push_back(pii(i,j));
                }
            }
            getchar();
        }

        BFS();
        int ret = BFSAG();


        if(ret==-1)  printf("Case %d: IMPOSSIBLE\n", caseno);
        else printf("Case %d: %d\n", caseno, ret);
    }
}

