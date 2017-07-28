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

int a, b;
double lent, width;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        scanf("%d : %d", &a, &b);

        double lo = 0, hi = 400, mid, r, angle, temp;
        int cnt = 50;

        while(cnt--)
        {
            mid = (hi + lo)/2.0;

            lent = mid/2;
            temp = (lent*b)/a;
            r = sqrt(lent*lent + temp*temp);
            r = r/2.0;
            angle = (r*r + r*r - temp*temp)/ (2*r*r);
            angle = acos(angle);
            width = r * angle;
            //cout<<lent<<' '<<width<<endl;
            if(lent+width>=200) hi = mid;
            else lo = mid;

        }
        printf("Case %d: %0.10lf %0.10lf\n", caseno, lent, width - (width-temp));
    }
}

