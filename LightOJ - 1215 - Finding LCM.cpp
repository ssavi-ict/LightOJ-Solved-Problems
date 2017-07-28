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
#define MAX 1005000
#define MAXN 100007
#define logbase(a, b) ( log10(a)/log10(b) )
#define DIR(f,s,R,C) (f>=0 && f<R && s>=0 && s<C)
#define DIR1(f,s,R,C) (f>=1 && f<=R && s>=1 && s<=C)

using namespace std;

int status[(MAX/32)+10];
vector<int>primelist;

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}

void sieve()
{
    int sqrtN=int (sqrt(MAX));
    for(int j=4; j<MAX; j=j+2)
        status[j>>5]=SET(status[j>>5],j&31);
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAX; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
    primelist.push_back(2);

    for(int i=3; i<=MAX; i=i+2)
    {
        if(check(status[i>>5], i&31)==0)
        {
            primelist.push_back(i);
        }
    }
}

LL power(LL a, LL b)
{
    if(b==0) return 1;
    else return a * power(a, b-1);
}

LL solve(LL a, LL b, LL c)
{

    LL ans = 1;
    int sz = primelist.size();
    for(int i=0; i<sz; i++)
    {
        int cnta = 0, cntb =0, cntc = 0;
        while(a%primelist[i]==0)
        {
            cnta++;
            a = a / primelist[i];
        }
        while(b%primelist[i]==0)
        {
            cntb++;
            b = b / primelist[i];
        }
        while(c%primelist[i]==0)
        {
            cntc++;
            c = c / primelist[i];
        }

        if(cntc>cnta && cntc>cntb)
        {
            ans = ans * power(primelist[i], cntc);
            //cout<<ans<<endl;
        }
    }
    if((c>1 && a==1) || (c>1 && b==1))  ans = ans * c;

    return ans;
}


int main()
{
    sieve();
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        LL a, b, L;
        scanf("%lld %lld %lld", &a, &b, &L);
        if(L%a!=0 || L%b!=0)
        {
            printf("Case %d: impossible\n", caseno);
        }
        else
        {
            printf("Case %d: %lld\n", caseno, solve(a, b, L));
        }
    }
}

