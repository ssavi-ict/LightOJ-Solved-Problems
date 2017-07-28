#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define PB(a, b) a.push_back(b)
#define PB2(a,i,b) a[i].push_back(b)
#define LL long long
#define ULL unsigned long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define INV 1e-6
#define sll(a) scanf("%I64d", &a)
#define pll(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 100006
#define CASE(i) printf("Case %d: ", i);
#define CSH(i) printf("Case #%d: ", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)


LL MOD = 1000000007;

using namespace std;

LL bigmod(LL b, LL p, LL m)
{
    if(p==0)  return 1;
    if(p%2==0)
    {
        LL x = bigmod(b,p/2,m);
        return (x%m * x%m)%m;
    }
    else return ((b%m)*bigmod(b,p-1,m)%m)%m;
}


LL MODINVERSE(LL a)
{
    return bigmod(a, MOD-2, MOD);
}

int dx[] = {1, 1};
int dy[] = {0, 1};
LL arr[2*101][2*101], maxc, n;
LL dp[2*101][2*101];

LL solve(int u, int v)
{
    if(u<1 || u>=2*n || v<1 || v>=2*n) return 0;
    if(dp[u][v]!=-1) return dp[u][v];
    LL ret = -INF;
    ret = max(ret, arr[u][v] + solve(u+dx[0], v+dy[0]));
    ret = max(ret, arr[u][v] + solve(u+dx[1], v+dy[1]));
  //  cout<<u<<' '<<v<<' '<<ret<<endl;

    return (dp[u][v] = ret);

}

int main()
{
    int t;
    scanf("%d", &t);
    for(int caseno = 1; caseno<=t; caseno++)
    {
        scanf("%lld", &n);
        maxc = 0;
        memset(dp, -1, sizeof dp);
        memset(arr, 0, sizeof arr);

        int i;
        for( i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        int x = 2;
        for(int j=i; j<2*n; j++)
        {
            for(int k=x; k<=n; k++)
            {
                scanf("%d", &arr[j][k]);
            }
            x++;
        }
        CASE(caseno);
        printf("%lld\n", solve(1,1));
    }
}

