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
#define sl(a) scanf("%I64d", &a)
#define pl(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        long long n;
        scanf("%lld", &n);

        int ans = 1;
        bool flag = false;
        if(n>0)
        {
            for(int i=2; i<46341; i++)
            {
                long long calc = 1;
                for(int j=1; j<=32; j++)
                {
                    calc = calc * i;
                    if(calc==n)
                    {
                        ans = j;
                        flag = true;
                        break;
                    }
                    else if(calc>n)
                    {
                        break;
                    }
                }
                if(flag)  break;
            }
        }
        else
        {
            for(int i=-2; i>-46341; i--)
            {
                long long calc = 1;
                for(int j=1; j<=32; j++)
                {
                    calc = calc * i;
                    if(calc==n)
                    {
                        ans = j;
                        flag = true;
                        break;
                    }
                    else if(calc<0 && abs(calc)>abs(n))
                    {
                        break;
                    }
                }
                if(flag)  break;
            }
        }

        CASE(caseno);
        printf(" %d\n", ans);
    }
}

