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
#define sll(a) scanf("%lld", &a)
#define pll(a) printf("%lld\n", a)
#define sii(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)

using namespace std;


void Make_Identity(LL ANS[][2], int n)
{
    memset(ANS, 0, sizeof ANS);
    for(int i=0; i<n; i++) ANS[i][i] = 1;
}

void Multiply(LL A[][2], LL B[][2], LL C[][2], LL MOD)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            C[i][j] = 0;
            for(int k=0; k<2; k++)
            {
                C[i][j] = ((C[i][j]%MOD) + (A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }
}

void Exponentian(LL Z[][2], LL n, LL ANS[][2], LL MOD)
{
    Make_Identity(ANS, 2);
    LL TEMP[2][2];
    while(n)
    {
        if(n&1)
        {
            Multiply(Z, ANS, TEMP, MOD);
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    ANS[i][j] = TEMP[i][j];
        }
        Multiply(Z, Z, TEMP, MOD);
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    Z[i][j] = TEMP[i][j];

        n = n / 2;
    }
}

LL Mat_Expo(LL a, LL b, LL n, LL MOD)
{
    LL fib;
    LL Z[2][2], ANS[2][2];
    memset(ANS, 0, sizeof ANS);

    Z[0][0] = 1;
    Z[0][1] = 1;
    Z[1][0] = 1;
    Z[1][1] = 0;

    Exponentian(Z, n-1, ANS, MOD);
    fib = ((ANS[0][0]*b) + ANS[0][1]*a)%MOD;

    return fib;
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        LL a, b, n, m;
        sll(a);sll(b);
        sll(n);sll(m);

        LL MOD = 1;
        for(LL i=1; i<=m; i++)
        {
            MOD = MOD * (LL)10;
        }
        a = a%MOD; b = b%MOD;

        CASE(caseno);
        printf(" ");
        if(n==0)
            printf("%lld\n", a);
        else if(n==1)
            printf("%lld\n", b);
        else if(n==2)
            printf("%lld\n", (a+b)%MOD);
        else
        {
            printf("%lld\n", Mat_Expo(a, b, n, MOD));
        }

    }
}


