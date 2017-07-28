#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define pb push_back
#define LL long long
#define ULL unsigned long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define INV 1e-6
#define sc(a) scanf("%I64d", &a)
#define pr(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define PII pair<LL,LL>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)
#define CHECK_BIT(var,pos) ((var & (1 << pos)) == (1 << pos))

using namespace std;
//
LL MOD = 1000000007;
//
//LL bigmod(LL a, LL b){
//    LL x = 1, y = a%MOD;
//    while(b > 0) {
//        if(b%2 == 1) {
//            x=(x*y);
//            if(x>MOD) x%=MOD;
//        }
//        y = (y*y);
//        if(y>MOD) y%=MOD;
//        b /= 2;
//    }
//    return x;
//}
//
//LL MODINVERSE(LL a){
//    return bigmod(a, MOD-2);
//}

//LL dp[900][1000];
//LL NCR(int n, int r)
//{
//    if(r==1) return n;
//    else if(n==r) return 1;
//    else
//    {
//        if(dp[n][r]!=-1) return dp[n][r];
//        else
//        {
//            dp[n][r]=NCR(n-1,r) + NCR(n-1,r-1);
//            return dp[n][r];
//        }
//    }
//}

const int MAXN = 1050;
int status[(MAXN/32)+10];

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}

void sieve()
{
    int sqrtN=int (sqrt(MAXN));
    status[1>>5]=SET(status[1>>5],1&31);
    for(int j=4; j<=MAXN; j=j+2)
        status[j>>5]=SET(status[j>>5],j&31);
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAXN; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
}

char str[105], ttr[105];
int visited[105][105];
int dp[105][105], caseno, len;

int solve(int idx1, int idx2)
{
    if(idx1==len || idx2==len)  return 0;
    if(visited[idx1][idx2]==caseno)  return dp[idx1][idx2];
    visited[idx1][idx2] = caseno;
    int ans = 0;
    if(str[idx1]==ttr[idx2]){
        ans = 1 + solve(idx1 + 1, idx2 + 1);
    }
    else{
        int cost1 = solve(idx1+1, idx2);
        int cost2 = solve(idx1, idx2+1);
        ans = max(cost1, cost2);
    }
    dp[idx1][idx2] = ans;

    return dp[idx1][idx2];
}

int main()
{
    int test;
    scanf("%d", &test);
    getchar();
    for(caseno=1; caseno<=test; caseno++)
    {
        scanf("%s", str);
        len = strlen(str);
        strcpy(ttr, str);
        reverse(ttr+0, ttr+len);
        CASE(caseno);
        printf(" %d\n", len - solve(0,0));
    }
}

