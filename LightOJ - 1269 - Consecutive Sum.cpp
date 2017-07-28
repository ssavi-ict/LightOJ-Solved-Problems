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
#define sc(a) scanf("%I64d", &a)
#define SC(a) scanf("%lld", &a)
#define pr(a) printf("%I64d\n", a)
#define PR(a) printf("%lld\n", a)
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
//LL MOD = 1000000007;
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

const int MAXN = 2000000;
int pre_xor, sz;
int val[MAXN], porerta[2][MAXN];

void INSERT(int num)
{
    int curr = 0;
    for(int i = 31; i>=0; i--)
    {
        int pos = CHECK_BIT(num, i);
        if(porerta[pos][curr]==-1){
            porerta[pos][curr] = ++sz;
        }
        curr = porerta[pos][curr];
    }
    val[curr] = num;
}

int MAX_SEARCH(int num)
{
    int curr = 0;
    for(int i = 31; i>=0; i--)
    {
        int pos = CHECK_BIT(num, i);
        if(porerta[1-pos][curr]!=-1){
            curr = porerta[1-pos][curr];
        }
        else if(porerta[pos][curr]!=-1){
            curr = porerta[pos][curr];
        }
    }
    return (num ^ val[curr]);
}

int MIN_SEARCH(int num)
{
    int curr = 0;
    for(int i = 31; i>=0; i--)
    {
        int pos = CHECK_BIT(num, i);
        if(porerta[pos][curr]!=-1){
            curr = porerta[pos][curr];
        }
        else if(porerta[1-pos][curr]!=-1){
            curr = porerta[1-pos][curr];
        }
    }
    return (num ^ val[curr]);
}



int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        ERASE(porerta, -1); ERASE(val, 0);
        int n, x, maximum = 0, minimum = INT_MAX;
        scanf("%d", &n);
        pre_xor = 0; sz = 0;
        INSERT(0);
        for(int i=1; i<=n; i++){
            scanf("%d", &x);
            pre_xor = pre_xor^x;

            maximum = max(maximum, MAX_SEARCH(pre_xor));
            minimum = min(minimum, MIN_SEARCH(pre_xor));
            INSERT(pre_xor);
        }
        CASE(caseno);
        printf(" %d %d\n", maximum, minimum);
    }
}

