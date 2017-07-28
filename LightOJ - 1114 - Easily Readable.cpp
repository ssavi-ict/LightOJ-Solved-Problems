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

const int large = 100007;
int porerta[57][large];
int cnt[large];
int sz, N, test, caseno;

void INSERT(char *str, int len)
{
    int curr = 0;
    for(int i=0; i<len; i++)
    {
        int idx;
        if(str[i]>='a' && str[i]<='z')  idx = str[i] - 'a' + 26;
        if(str[i]>='A' && str[i]<='Z')  idx = str[i] - 'A';

        if(porerta[idx][curr]==-1){
            porerta[idx][curr] = ++sz;
        }
        curr = porerta[idx][curr];

    }
    cnt[curr]++;
}

int SEARCH(string str, int len)
{
    int curr = 0;
    for(int i=0; i<len; i++)
    {
        int idx;
        if(str[i]>='a' && str[i]<='z')  idx = str[i] - 'a' + 26;
        if(str[i]>='A' && str[i]<='Z')  idx = str[i] - 'A';
        if(porerta[idx][curr]==-1){
            return 0;
        }
        curr = porerta[idx][curr];
    }
    return cnt[curr];
}

int main()
{
    scanf("%d", &test);
    for(caseno=1; caseno<=test; caseno++)
    {
        scanf("%d", &N);
        sz = 0;
        ERASE(cnt, 0);
        ERASE(porerta, -1); ;
        char str[100005];
        while(N--)
        {

            scanf("%s", str);
            int len = strlen(str);
            if(len>2) sort(str+1, str+len-1);
            INSERT(str, len);
        }
        int Q;
        scanf("%d", &Q);
        getchar();
        string ttr;
        CASE(caseno); puts("");
        while(Q--){
          int ans = 1;
          gets(str);
          stringstream ss(str);

          while(ss>>ttr){
                int len = ttr.size();
                if(len>2) sort(ttr.begin()+1, ttr.end()-1);
                ans = ans * SEARCH(ttr, ttr.size());
          }
          ttr.clear();
          printf("%d\n", ans);
        }
    }

    return 0;
}

