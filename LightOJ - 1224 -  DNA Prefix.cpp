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
#define CASE(i) printf("Case %d: ", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)

using namespace std;

LL MOD = 1000000007;

LL bigmod(LL a, LL b){
    LL x = 1, y = a%MOD;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

LL MODINVERSE(LL a){
    return bigmod(a, MOD-2);
}

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

const int large = 2500005;
int porerta[4][large];
int cnt[large], maxx, depth[large];
int arr[125];
//int sesh[large];
bool created[large];
int sz;


void INSERT(char *str, int len)
{
    int curr = 0;
    depth[0] = 0;
    for(int i=0; i<len; i++)
    {
        int idx = arr[str[i]];
        if(!created[porerta[idx][curr]]){
            porerta[idx][curr] = ++sz;
            created[sz] = true;
            depth[sz] = depth[curr] + 1;
        }
        curr = porerta[idx][curr];
        cnt[curr]++;
        maxx = max(maxx, cnt[curr]*depth[curr]);
    }
   // ++sesh[curr];
}

//bool SEARCH(char *str, int len)
//{
//    int curr = 0;
//    for(int i=0; i<len; i++)
//    {
//        int idx = str[i] - 'A';
//        if(!created[porerta[idx][curr]]){
//            return false;
//        }
//        curr = porerta[idx][curr];
//    }
//    return sesh[curr]>0;
//}

int main()
{
    int N, test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%d", &N);
      //  memset(sesh, 0, sizeof sesh);
        arr['A'] = 0; arr['C'] = 1; arr['G'] = 2; arr['T'] = 3;
        memset(cnt, 0, sizeof cnt);
        memset(depth, 0, sizeof depth);
        memset(created, false, sizeof created);
        memset(porerta, 0, sizeof porerta);
        maxx = 0; sz = 0;
        while(N--)
        {
            char str[105];
            scanf("%s", str);
            INSERT(str, strlen(str));
        }
        CASE(caseno);
        printf("%d\n", maxx);

    }

    return 0;
}

