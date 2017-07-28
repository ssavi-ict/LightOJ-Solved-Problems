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
#define LOOP(i, b, n) for(i=b; i<=n; i++)
#define nl puts("")


using namespace std;

/** ---------------------------------------------- **/
/** Header And Defintions Ends Here. **/
/** ---------------------------------------------- **/

int dx4[] = {0, 0, 1, -1}; int dy4[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, -1, 1, 1, -1, -1};int dy8[] = {1, -1, 0, 0, 1, -1, 1, -1};

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
const LL BIGMAX = power(2,63) - 1;

LL ADD(LL X, LL Y)
{
    if(X+Y<0)
        return (X - MOD) + Y;
    else if(X+Y>=MOD)
        return X+Y-MOD;
    else
        return X+Y;
}

LL prod(LL X, LL Y) // CUSTOM PRODUCT FUNCTION FOR BIG NUMBER MULTIPLICATION
{
    if(Y==0 || X<=(BIGMAX/Y)) return (X*Y)%MOD;
    LL result = 0;

    if(X>Y) swap(X,Y);
    while(X>0){
        if(X&1!=0){
            result = ADD(result, Y);
        }
        X>>=1;
        Y -= MOD - Y;
        if(Y<0)
            Y = Y + MOD;
    }
    return result;
}

LL bigmod(LL a, LL b){
    LL x = 1, y = a%MOD;
    while(b > 0) {
        if(b%2 == 1) {
            x = prod(x,y);
        }
        y = prod(y,y);
        b /= (LL)2;
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

const int MAXN = 1400005;
int status[(MAXN/32)+10];
vector<int>primelist;

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

int test, caseno, node, second, total;
vector<int>G[50055];
bool visited[50055], flag[50055];
int scc[50055], scccnt;
int low[50055], start[50055];
int cnt[50055];
stack<int>myStack;

void init(){
    for(int i=0; i<=50005; i++){
        G[i].clear();
        visited[i] = false;
        low[i] = -1;
        start[i] = -1;
        scc[i] = 0;
        flag[i] = false;
        cnt[i] = 0;
    }
    scccnt = 0; second = 0;  total = 0;
    while(!myStack.empty()){
        myStack.pop();
    }
}

void DFS_SCC(int u){

    second++;
    start[u] = low[u] = second;
    myStack.push(u);
    visited[u] = true;

    int sz = G[u].size();
    for(int i=0; i<sz; i++){
        int v = G[u][i];

        if(start[v]==-1){
            DFS_SCC(v);
            low[u] = min(low[u], low[v]);
        }
        else if(visited[v]){
            low[u] = min(low[u], start[v]);
        }
    }

    if(start[u]==low[u]){
        scccnt++;
        scc[scccnt] = u;
        while(myStack.top()!=u){
            visited[myStack.top()] = false;
            myStack.pop();
        }
        visited[myStack.top()] = false;
        myStack.pop();
    }
}

void DFSC(int u){
    if(cnt[u]){
        total = total + cnt[u];
        return;
    }
    total++;
    flag[u] = true;
    int sz = G[u].size();
    for(int i=0; i<sz; i++){
        int v = G[u][i];
        if(!flag[v]){
            DFSC(v);
        }
    }
    cnt[u] = total;
}

void DFSCLEAR(int u){
    flag[u] = false;
    int sz = G[u].size();
    for(int i=0; i<sz; i++){
        int v = G[u][i];
        if(flag[v]){
            DFSCLEAR(v);
        }
    }
}

int main(){
   // freopen("in.txt", "r", stdin);
    scanf("%d", &test);
    LOOP(caseno, 1, test){
        init();
        scanf("%d", &node);

        for(int i=1; i<=node; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }

        for(int i=1; i<=node; i++){
            if(start[i]==-1){
                DFS_SCC(i);
            }
        }

       // DBG;
        int maxnode = 0, ansnode;
        for(int i=1; i<=scccnt; i++){
            int u = scc[i];
            if(!flag[u]){
                total = 0;
                DFSC(u);
                //cout<<"YES"<<' '<<total<<' '<<u<<endl;
                if(total>maxnode){
                    maxnode = total;
                    ansnode = u;
                }
                else if(total==maxnode){
                    ansnode = min(u, ansnode);
                }
                DFSCLEAR(u);
            }
        }

        CASE(caseno);
        printf(" %d\n", ansnode);
    }
}

