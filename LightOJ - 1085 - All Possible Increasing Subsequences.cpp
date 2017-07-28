/** Jai Shree Ram **/
/** ssavi. ICT-4 CoU **/

#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define pb push_back
#define LL long long
#define ULL unsigned long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define INV 1e-6
#define sc(a) scanf("%I64d", &a)
#define pr(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define nl puts("")
#define pii pair<int,int>
#define PII pair<LL,LL>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)
#define CHECK_BIT(var,pos) ((var & (1 << pos)) == (1 << pos))
#define LOOP(i, b, n) for(i=b; i<=n; i++)

using namespace std;

/** ---------------------------------------------- **/
/** Header And Defintions Ends Here. **/
/** ---------------------------------------------- **/

const double GRS = (1 + sqrt(5))/2;

LL power(int X, int P)
{
    LL ans = 1;
    for(int i=1; i<=P; i++){
        ans = ans * (LL)X;
    }
    return ans;
}

LL ABS(LL A, LL B)
{
    LL ret = A - B;
    if(ret<0) return -ret;
    return ret;
}

LL MOD = 1000000007;

LL bigmod(LL a, LL b){
    LL x = 1, y = a%MOD;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

LL MODINVERSE(LL a){
    return bigmod(a, MOD-2);
}

LL ncrdp[900][1000];
LL NCR(int n, int r)
{
    if(r==1) return n;
    else if(n==r) return 1;
    else
    {
        if(ncrdp[n][r]!=-1) return ncrdp[n][r];
        else
        {
            ncrdp[n][r]=NCR(n-1,r) + NCR(n-1,r-1);
            return ncrdp[n][r];
        }
    }
}

const int MAXN = 1005;
int status[(MAXN/32)+10];
vector<int>primelist;

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}

void sieve()
{
    int sqrtN=int (sqrt(MAXN));
    status[1>>5]=SET(status[1>>5],1&31);
//    for(int j=4; j<=MAXN; j=j+2)
//        status[j>>5]=SET(status[j>>5],j&31);
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAXN; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
    primelist.push_back(2);
    for(int i=3; i<=MAXN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0) {
            primelist.push_back(i);
        }
    }
}


/**----------------------------------------------------------------------------**/
/** Template Ends Here. Main Function And User Defined Functions Starts Here. **/
/**--------------------------------------------------------------------------**/

LL arr[100005], brr[100005];
LL tree[3*100005];

void build(LL node, LL top, LL rear)
{
    if(top==rear){
        tree[node] = 0;
        return;
    }
    LL Left = 2*node;
    LL Right = 2*node + 1;
    LL Mid = (top + rear)/2;
    build(Left, top, Mid);
    build(Right, Mid+1, rear);
    tree[node] = tree[Left] + tree[Right];
}

LL query(LL node, LL top, LL rear, LL i, LL j)
{
    if(i>rear || j<top)  return 0;
    if(top>=i && rear<=j){
        return tree[node];
    }
    LL Left = 2*node;
    LL Right = 2*node + 1;
    LL Mid = (top + rear)/2;
    LL ret1 = query(Left, top, Mid, i, j);
    LL ret2 = query(Right, Mid+1, rear, i, j);

    return (ret1 + ret2);
}

void update(LL node, LL top, LL rear, LL i, LL value)
{
    if(i>rear || i<top)  return ;
    if(i<=top && i>=rear){
        tree[node] = (tree[node] + value)%MOD;
        return;
    }
    LL Left = 2*node;
    LL Right = 2*node + 1;
    LL Mid = (top + rear)/2;
    update(Left, top, Mid, i, value);
    update(Right, Mid+1, rear, i, value);
    tree[node] = (tree[Left] + tree[Right])%MOD;
}

int main()
{
    int test, caseno;
    scanf("%d", &test);
    LOOP(caseno, 1, test)
    {
        map<LL, LL>mymap;
        memset(tree, 0, sizeof tree);
        LL n;
        scanf("%lld", &n);
        for(LL i=1; i<=n; i++){
            scanf("%lld", arr+i);
            brr[i] = arr[i];
        }

        sort(brr+1, brr+n+1);
        LL cnt = 0;
        for(int i=1; i<=n; i++){
            if(!mymap[brr[i]]) mymap[brr[i]] = ++cnt;
        }

        build(1, 1, cnt);
        LL ans = 0;
        for(LL i=1; i<=n; i++)
        {
//            cout<<mymap[arr[i]]<<endl;
            LL ret = query(1, 1, cnt, 1, mymap[arr[i]]-1) + 1;
            ans = (ans + ret)%MOD;
           // cout<<ret<<' '<<ans<<endl;
            update(1, 1, cnt, mymap[arr[i]], ret%MOD);
//            printf("After %lldth Update: ", i);
//            for(int j=1; j<=2*cnt-1; j++){
//                printf("%lld ", tree[j]);
//            }
//            nl;
        }
        CASE(caseno);
        printf(" %lld\n", ans);
    }
}

