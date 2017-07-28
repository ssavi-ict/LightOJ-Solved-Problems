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

int M, N;
bool visited[1001];
int level[1001];
vector<int>grid[1001];

int status[(MAX/32)+10];
vector<int>primelist;

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}

void sieve()
{
    int sqrtN=int (sqrt(MAX));
    //for(int j=4; j<MAX; j=j+2)
        //status[j>>5]=SET(status[j>>5],j&31);
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAX; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
    primelist.push_back(2);

    for(int i=3; i<=MAX; i=i+2)
    {
        if(check(status[i>>5], i&31)==0)
        {
            primelist.push_back(i);
        }
    }
}

void precal()
{
    int sz = primelist.size();
    for(int i=1; i<=1000; i++)
    {
        for(int j=0; j<sz; j++)
        {
            if(i%primelist[j]==0 && i>primelist[j])
            {
                grid[i].push_back(primelist[j]);
            }
        }
    }
}

void BFS(int src, int dest)
{
    queue<int>q ;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<grid[u].size(); i++)
        {
            int v = u + grid[u][i];
            if(!visited[v] && v<=dest)
            {
                //cout<<u<<' '<<v<<endl;
                visited[v] = true;
                level[v] = level[u] + 1;
                if(v==dest)
                {
                    printf("%d\n", level[v]);
                    return;
                }
                q.push(v);
            }
        }
    }
    printf("-1\n");
}

int main()
{
    sieve();
    precal();
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        ERASE(visited, false);
        ERASE(level, 0);
        scanf("%d %d", &M, &N);
        printf("Case %d: ", caseno);
        if(M==N) printf("0\n");
        else BFS(M,N);
    }
}

