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

vector<int>grid[1055];
bool visited[1055];
int arr[1055];
int N, M;

pii BFS(int src)
{
    int cnt = 0, cost = 0;
    queue<int>q;
    q.push(src);
    visited[src] = true;
    cnt++; cost = cost + arr[src];
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<grid[u].size(); i++)
        {
            int v = grid[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                cost = cost + arr[v];
                cnt++;
                q.push(v);
            }
        }
    }

    pii ret = pii(cost, cnt);
    return ret;
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        for(int i=0; i<=1050; i++)
        {
            grid[i].clear();
            visited[i] = false;
        }
        scanf("%d %d", &N, &M);
        for(int i=1; i<=N; i++)  scanf("%d", arr+i);

        int u, v;
        for(int i=0; i<M; i++)
        {
            scanf("%d %d", &u, &v);
            grid[u].push_back(v);
            grid[v].push_back(u);
        }

        printf("Case %d: ", caseno);
        if(M==0)
        {
            bool flag = true;
            for(int i=1; i<N; i++)
            {
                if(arr[i]!=arr[i+1])
                {
                    flag = false;
                    printf("No\n");
                    break;
                }
            }
            if(flag)  printf("Yes\n");
            continue;
        }

        set<int>myset;
        myset.clear();

        bool yes = true;
        for(int i=1; i<=N; i++)
        {
            if(!visited[i])
            {
                pii ret = BFS(i);
                int ave = ret.first/ret.second;
                if(ave*ret.second!=ret.first)
                {
                    yes = false;
                }
                myset.insert(ave);
            }
        }
        if(yes)
        {
            if(myset.size()==1)  printf("Yes\n");
            else printf("No\n");
        }
        else
        {
            printf("No\n");
        }
    }
}

