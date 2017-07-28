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
#define MAX 600005
#define CASE(i) printf("Case %d: ", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)

using namespace std;

double result[1000002];

int main()
{
    double ans = 0.0; int k = 1;
    for(int i=1; i<=100000001; i++)
    {
        ans = ans + (1.0/(i*1.0));
        if(i%100==0)
        {
            result[k] = ans;
            k++;
        }
    }

    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        int n;
        scanf("%d", &n);
        int mod = n % 100;
        int div = n / 100;
        int start = div*100;
      //  cout<<mod<<' '<<div<<endl;

        double tot = result[div];
        for(int i=start+1 ; i<=(start+mod); i++)
        {
            tot = tot +  (1.0/(i*1.0));
        }
        printf("Case %d: %.10f\n", caseno, tot);
    }
}
/*
Solution - 2
------------
double result[2001];

int main()
{
    double ans = 0.0; int k = 1;
    for(int i=1; i<=1000; i++)
    {
        ans = ans + (1.0/(i*1.0));
        result[i] = ans;
    }

    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        int n;
        scanf("%d", &n);
        double tot;
        if(n<=1000)
            tot = result[n];
        else
        {
            tot = log(n) + 0.57721566490153286060651209008240243104215933593992;
            tot = tot + (1.0/(2*1.0*n)) - (1.0 / (12*1.0 * n * n));

        }
        printf("Case %d: %.10f\n", caseno, tot);
    }
}
*/
