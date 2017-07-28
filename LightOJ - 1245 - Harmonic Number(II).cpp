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

LL arr[100003];

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        LL n;
        scanf("%lld", &n);
        LL sqrtN = sqrt(n);
        for(int i=1; i<=sqrtN+1; i++)
        {
            arr[i] = n / (LL) i;
        }
        LL sum = 0;
        for(int i=1; i<=sqrtN; i++)
        {
            if(i==sqrtN){
                sum = sum + i + arr[i];
               // DBGA(sum);
                if(i==arr[i]) sum = sum - i;
                if(abs(i-arr[i])>1) sum = sum - i + (arr[i]-arr[i+1]) * i;
            }
            else{
                sum = sum + arr[i] + (arr[i]-arr[i+1]) * i;
            }
            //cout<<sum<<endl;
        }

        CASE(caseno);
        printf("%lld\n", sum);
    }
}

