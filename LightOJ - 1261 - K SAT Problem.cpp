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
#define ii(a) scanf("%lld", &a)
#define PP(a) printf("%I64d", a)
#define pp(a) printf("%lld", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 100007
#define logbase(a, b) ( log10(a)/log10(b) )

using namespace std;

bool AC[35][35], RJ[35][35];

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int n, m, k, x, full, wish;
        ERASE(AC, false); ERASE(RJ, false);
        scanf("%d %d %d", &n, &m, &k);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=k; j++)
            {
                scanf("%d", &x);
                if(x>0) AC[i][x] = true;
                else RJ[i][abs(x)] = true;
            }
        }
        scanf("%d", &full);
        int cnt = 0;
        for(int i=1; i<=full ; i++)
        {
            scanf("%d", &wish);
            for(int j=1; j<=n; j++)
            {
                if(AC[j][wish])  cnt++;
                else if(!RJ[j][wish]) cnt++;
            }
        }
        if(cnt==n || full==0)  printf("Case %d: Yes\n", caseno);
        else printf("Case %d: No\n", caseno);
    }
}
