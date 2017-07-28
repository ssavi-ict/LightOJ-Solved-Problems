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
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)

using namespace std;

long long MOD = 10007;

void Make_Identity(LL ANS[][4], int n)
{
    memset(ANS, 0, sizeof ANS);
    for(int i=0; i<n; i++) ANS[i][i] = 1;
}

void Multiply(LL A[][4], LL B[][4], LL C[][4])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            C[i][j] = 0;
            for(int k=0; k<4; k++)
            {
                C[i][j] = ((C[i][j]%MOD) + (A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }
}

void Exponentian(LL Z[][4], LL n, LL ANS[][4])
{
    Make_Identity(ANS, 4);
    LL TEMP[4][4];
    while(n)
    {
        if(n&1)
        {
            Multiply(Z, ANS, TEMP);
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    ANS[i][j] = TEMP[i][j];
        }
        Multiply(Z, Z, TEMP);
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    Z[i][j] = TEMP[i][j];

        n = n / 2;
    }
}

LL Mat_Expo(LL n, LL a, LL b, LL c)
{
    LL res;
    if(n>2)
    {
        LL Z[4][4], ANS[4][4];
        memset(ANS, 0, sizeof ANS);

        Z[0][0] = a; Z[0][1] = 0; Z[0][2] = b; Z[0][3] = c;
        Z[1][0] = 1; Z[1][1] = 0; Z[1][2] = 0; Z[1][3] = 0;
        Z[2][0] = 0; Z[2][1] = 1; Z[2][2] = 0; Z[2][3] = 0;
        Z[3][0] = 0; Z[3][1] = 0; Z[3][2] = 0; Z[3][3] = 1;

        Exponentian(Z, n-2, ANS);
        res = (ANS[0][3])%MOD;
    }
    else res = 0;

    return res;
}


int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        LL n, a, b, c;
        sll(n);sll(a);sll(b);sll(c);

        LL ans = Mat_Expo(n,a,b,c);
        CASE(caseno);
        printf(" ");
        printf("%lld\n", ans);
    }
}


