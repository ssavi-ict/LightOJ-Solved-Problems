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

LL M, N;
LL arr[1001];

bool solve(LL mid)
{
    LL cnt = 0; LL tot = 0;
    for(int i=0; i<M; i++)
    {
        tot = tot + arr[i];
        if(tot>mid){
            cnt++;
            tot = arr[i];
        }
    }
    //cout<<cnt<<endl;
    if(cnt>=N) return true;
    else return false;
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%lld %lld", &M, &N);
        for(int i=0; i<M; i++) scanf("%lld", arr+i);

        LL maxx = *max_element(arr, arr+M);

        if(N>=M)
        {
            printf("Case %d: %lld\n", caseno, maxx);
            continue;
        }

        LL lo = maxx, hi = 2000000000, mid;

        int cnt = 50;
        while(cnt--)
        {
            mid = (lo+hi)/2;
           // cout<<mid<<' ';
            if(solve(mid))
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        printf("Case %d: %lld\n", caseno, lo);
    }
}

