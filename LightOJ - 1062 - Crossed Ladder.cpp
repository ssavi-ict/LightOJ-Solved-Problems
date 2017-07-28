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
#define CASE(i) printf("Case %d: ", i);
#define PI acos(-1)
#define EPS 0.00000001

using namespace std;

double x, y, c;

double solve(double mid)
{
    double A = sqrt((x*x) - (mid*mid));
    double B = sqrt((y*y) - (mid*mid));

    //cout<<A<<' '<<B<<endl;
    return ((A*B)/(A+B));
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        scanf("%lf %lf %lf", &x, &y, &c);
        double lo = 0.0, hi = min(x, y), mid;

        int cnt = 100;
        double ans = 1;
        while(cnt--)
        {
            mid = (lo + hi)/2.0;
            //cout<<solve(mid)<<endl;
            if(solve(mid)<=c)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        printf("Case %d: %0.10lf\n", caseno, lo);
    }
}

