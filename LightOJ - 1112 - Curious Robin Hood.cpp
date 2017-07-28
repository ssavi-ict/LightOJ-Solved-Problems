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
#define sl(a) scanf("%I64d", &a)
#define pl(a) printf("%I64d", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 100007

using namespace std;

int arr[MAX];
int tree[3*MAX];

void build(int node, int b, int e)
{
    if(b==e){
        tree[node] = arr[b];
        return;
    }
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1, e);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[node];
    }
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    int ret1 = query(left, b, mid, i, j);
    int ret2 = query(right, mid+1, e, i, j);

    return ret1 + ret2;
}

void update(int node, int b, int e, int target, int  value)
{
    if(target>e || target<b)  return;
    if(b>=target && e<=target){
        tree[node] = tree[node] + value;
        return ;
    }

    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    update(left, b, mid, target, value);
    update(right, mid+1, e, target, value);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        int n, q, type, x, y;
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++)  scanf("%d", &arr[i]);
        build(1, 1, n);
        printf("Case %d:\n", caseno);
        for(int i=0; i<q; i++)
        {
            scanf("%d", &type);
            if(type==1)
            {
                scanf("%d", &x);
                x++;
                update(1, 1, n, x, -arr[x]);
                printf("%d\n", arr[x]);
                arr[x] = 0;
            }
            else if(type==2)
            {
                scanf("%d %d", &x, &y);
                x++;
                update(1, 1, n, x, y);
                arr[x] = arr[x] + y;
            }
            else
            {
                scanf("%d %d", &x, &y);
                x++; y++;
                printf("%d\n", query(1, 1, n, x, y));
            }
        }
    }
    return 0;
}

