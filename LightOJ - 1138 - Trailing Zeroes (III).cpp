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
#define INV 1e-6
#define sl(a) scanf("%I64d", &a)
#define pl(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 600005

using namespace std;

LL fn(LL x)
{
    LL cnt = 0;
    for (int i=5; x/i>=1; i *= 5)
          cnt += x/i;

    return cnt;
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        LL n;
        scanf("%lld", &n);
        LL lo = 1, hi = 100000000000000, mid, ans = -1;
        while(lo<=hi)
        {
            mid = (lo + hi)/2;
            LL got = fn(mid);
            if(got==n)
            {
                ans = mid;
                for(LL i=mid-1; i>=mid-10; i--)
                {
                    if(fn(i)==got)
                    {
                        ans = i;
                    }
                }
                break;
            }
            else if(got<n)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if(ans!=-1)
             printf("Case %d: %lld\n", caseno, ans);
        else
             printf("Case %d: impossible\n", caseno);
    }
    return 0;
}

