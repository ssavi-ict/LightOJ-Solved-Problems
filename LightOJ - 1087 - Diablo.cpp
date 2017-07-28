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
#define SF(a) scanf("%I64d", &a)
#define PF(a) printf("%I64d\n", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d\n", a)
#define pii pair<int,int>
#define PIS pair<double,string>
#define PII pair<LL,LL>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)
#define CHECK_BIT(var,pos) ((var & (1 << pos)) == (1 << pos))
#define LOOP(i, b, n) for(int i=b; i<=n; i++)
#define nl puts("")
#define popcount __builtin_popcount
#define valid(i,j,m,n) (i>=0 && i<n && j>=0 && j<m)

using namespace std;

/** -------------------------------------------------**/
/** Header And Definitions Ends Here.               **/
/** -----------------------------------------------**/

int dx4[] = {0, 0, 1, -1}; int dy4[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, -1, 1, 1, -1, -1}; int dy8[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dxH[] = {2, 2, -2, -2, 1, 1, -1, -1}; int dyH[] = {1, -1, 1, -1, 2, -2, 2, -2};
const double GRS = (1 + sqrt(5))/2;

template<typename T> T power(T X, T P)
{
    T ans = (T)1;
    for(T i=1; i<=P; i++){
        ans = ans * X;
    }
    return ans;
}

template<typename T> T ABS(T A, T B)
{
    T ret = A - B;
    if(ret<0) return -ret;
    return ret;
}

const LL BIGMAX = power(2,63) - 1;

template<typename T> T ADD(T X, T Y, T M)
{
    if(X+Y<0)
        return (X - M) + Y;
    else if(X+Y>=M)
        return X+Y-M;
    else
        return X+Y;
}

template<typename T> T prod(T a, T b, T c) // CUSTOM PRODUCT FUNCTION FOR BIG NUMBER MULTIPLICATION
{
    T x = 0, y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = ADD(x, y, c);
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

template<typename T> T bigmod(T a, T b, T c){
    T x = 1, y = a%c;
    while(b > 0) {
        if(b%2 == 1) {
            x = prod(x,y, c);
        }
        y = prod(y,y, c);
        b /= (LL)2;
    }
    return x;
}


template <typename T> T MODINVERSE(T a, T b){
    return bigmod(a, b-2);
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

const int MAXN = 1000000;
int status[(MAXN/32)+10];
int primelist[1234567];
int primesz = 0;

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}

void sieve()
{
    int sqrtN=int (sqrt(MAXN));
    status[1>>5]=SET(status[1>>5],1&31);
    for(int j=4; j<=MAXN; j=j+2)
        status[j>>5]=SET(status[j>>5],j&31);
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
    //primelist.push_back(2);
    primelist[primesz++] = 2;
    for(int i=3; i<=MAXN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0) {
            //primelist.push_back(i);
            primelist[primesz++] = i;
        }
    }
}

template<typename T> T GCD(T x, T y) {
  while ( y != 0 ) {
    T z = x % y;
    x = y;
    y = z;
  }
  return x;
}


/**----------------------------------------------------------------------------**/
/** Template Ends Here. Main Function And User Defined Functions Starts Here. **/
/**--------------------------------------------------------------------------**/

LL arr[123456], idx, ret;
struct info{
    LL val, sum;
}tree[4*151234];

void build(LL node, LL b, LL e)
{
    if(b==e){
        tree[node].val = arr[b];
        tree[node].sum = 1;
        return;
    }
    LL Left = node<<1;
    LL Right = Left + 1;
    LL mid = (b + e)>>1;
    build(Left, b, mid);
    build(Right, mid+1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(LL node, LL b, LL e, LL idx, LL value)
{
    if(idx>e || idx<b) return;
    if(b>=idx && e<=idx){
        tree[node].val = value;
        tree[node].sum = 1;
        return;
    }

    LL Left = node<<1;
    LL Right = Left + 1;
    LL mid = (b + e)>>1;
    update(Left, b, mid, idx, value);
    update(Right, mid+1, e, idx, value);

    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void query(LL node, LL b, LL e, LL pos)
{
    if(b==e){
        tree[node].sum = 0;
        ret = tree[node].val;
        return;
    }
    LL Left = node<<1;
    LL Right = Left + 1;
    LL mid = ( b + e )>>1;
    if(pos<=tree[Left].sum){
        query(Left, b, mid, pos);
    }
    else{
        query(Right, mid+1, e, pos-tree[Left].sum);
    }
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

int main()
{
    int test;
    scanf("%d", &test);
    getchar();
    LOOP(caseno, 1, test){
        ERASE(tree, 0);
        LL n, q; idx = 0;
        scanf("%lld %lld", &n, &q);
        for(int i=1; i<=n; i++){
            scanf("%lld", arr+i);
            ++idx;
        }

        build(1LL, 1LL, 150005LL);
        LL cnt = 0;
        CASE(caseno);
        nl;
        while(q--){
            getchar();
            char com; LL val;
            scanf("%c %lld", &com, &val);

            if(com=='a'){
                ++idx;
                update(1LL, 1LL, 150005LL, idx, val);
            }
            else{
                if(val>idx - cnt){
                    printf("none\n");
                }
                else{
                    cnt++;
                    query(1LL, 1LL, 150005LL, val);
                    printf("%lld\n", ret);
                }
            }
        }
    }
}

