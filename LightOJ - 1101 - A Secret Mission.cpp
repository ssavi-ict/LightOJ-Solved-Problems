/** Jai Shree Ram **/
/** ssavi. ICT-4 CoU **/

#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
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
#define DBGA2(a, b) cout<<a<<' '<<b<<endl
#define DBGA3(a, b, c) cout<<a<<' '<<b<<' '<<c<<endl
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
#define valid(i,j,a,b,m,n) (i>=a && i<=n && j>=b && j<=m)
#define all(v) v.begin(), v.end()

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

const LL MOD = 1000000007;
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
    T x = (T)1, y = a%c;
    while(b > 0) {
        if(b%(T)2 == (T)1) {
            x = (x * y)%c;
        }
        y = (y * y)%c;
        b /= (T)2;
    }
    return x;
}


template <typename T> T MODINVERSE(T a){
    return bigmod(a, MOD-2);
}

template<typename T> T GCD(T x, T y) {
  while ( y != 0 ) {
    T z = x % y;
    x = y;
    y = z;
  }
  return x;
}

bool isvowel(char ch)
{
    ch = toupper(ch);
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y') return true;
    return false;
}

template<typename T>T isleap (T year)
{
    if (year%(T)400 == (T)0 || (year%(T)100 != (T)0 && year%(T)4 == (T)0)) return true;
    return false;
}

/**----------------------------------------------------------------------------**/
/** Template Ends Here. Main Function And User Defined Functions Starts Here. **/
/**--------------------------------------------------------------------------**/

struct info{
    int u, v, w;
    bool operator < (const info& p) const{
        return w<p.w;
    }
};

vector<info>grid, valid;
vector<int>graph[50005];
vector<int>cost[50005];
int n, e;
int father[50005], Depth[50005], Weight[50005];
int Sparse[50005][17];
int Max[50005][17];

void init()
{
    for(int i=1; i<=n+2; i++){
        father[i] = i;
        graph[i].clear();
        cost[i].clear();
        Depth[i] = 0;
        Weight[i] = 0;
    }
    valid.clear();
    grid.clear();
    ERASE(Sparse, -1);
    ERASE(Max, 0);
}

int parent(int src)
{
    if(src==father[src]) return src;
    return father[src] = parent(father[src]);
}

void MST()
{
    sort(all(grid));
    int cnt = 0;
    int sz = grid.size();
    //cout<<sz<<endl;
    for(int i=0; i<sz; i++){
        int u = parent(grid[i].u);
        int v = parent(grid[i].v);
        //cout<<grid[i].u<<' '<<grid[i].v<<' '<<u<<' '<<v<<endl;
        if(u!=v){
            cnt++;
            father[u] = v;
            valid.push_back(grid[i]);
            if(cnt==n-1) break;
        }
    }

    sz = valid.size();
    //DBGA(cnt);
    for(int i=0; i<sz; i++){
        int u, v, w;
        u = valid[i].u, v = valid[i].v, w = valid[i].w;
        //cout<<u<<' '<<v<<' '<<w<<endl;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

}

void DFS(int from , int node, int dep)
{
    father[node] = from;
    Depth[node] = dep;
    int sz = graph[node].size();
    for(int i=0; i<sz; i++){
        int v = graph[node][i];
        if(v==from) continue;
        Weight[v] = cost[node][i];
        DFS(node, v, dep+1);
    }
}

void LCA_INIT()
{
    for(int i=1; i<=n; i++){
        Sparse[i][0] = father[i];
        Max[i][0] = Weight[i];
    }

    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(Sparse[i][j-1]!=-1){
                Sparse[i][j] = Sparse[Sparse[i][j-1]][j-1];
                Max[i][j] = max(Max[i][j-1], Max[Sparse[i][j-1]][j-1]);
            }
        }
    }
}

int LCA_Query(int p, int q)
{
    if(Depth[p]<Depth[q]) swap(p, q);
    int log = 15;

    int ans = 0;
    for(int i=log; i>=0; i--){
        if((Depth[p] - (1<<i)) >= Depth[q]){
            ans = max(ans, Max[p][i]);
            //DBGA2(Max[p][i], i);
            p = Sparse[p][i];
        }
    }
    if(p==q) return ans;
    for(int i=log; i>=0; i--){
        if(Sparse[p][i]!=-1 && Sparse[p][i]!=Sparse[q][i]){
            ans = max(ans, max(Max[p][i], Max[q][i]));
            //cout<<Max[p][i]<<' '<<Max[q][i]<<endl;
            p = Sparse[p][i], q = Sparse[q][i];
        }

    }
    ans = max(ans, max(Weight[p], Weight[q]));
    return ans;
}

int main()
{
    int test;
    scanf("%d", &test);
    LOOP(caseno, 1, test)
    {

        scanf("%d %d", &n, &e);
        init();
        LOOP( i, 0, e-1){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            info var;
            var.u = u, var.v = v, var.w = w;
            grid.push_back(var);
        }

        MST();
        Weight[1] = 0;
        DFS(1, 1, 0);
        LCA_INIT();
        CASE(caseno);
        nl;

        int q;
        scanf("%d", &q);
        while(q--){
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", LCA_Query(a, b));
        }

    }
}
