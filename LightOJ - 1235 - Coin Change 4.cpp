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

using namespace std;

LL arr[20];
vector<LL>cost, another;

void getall(int pos, int n, LL cur, vector<LL>& vec)
{
    if(pos>n+1) return;
    vec.push_back(cur);
    getall(pos+1, n, cur+2*arr[pos], vec);
    getall(pos+1, n, cur+arr[pos], vec);
    getall(pos+1, n, cur, vec);
}

int main()
{
    int test;
    scanf("%d", &test);
    LOOP(caseno, 1, test){
        cost.clear(); another.clear();
        int n; LL K;
        scanf("%d %lld", &n, &K);
        for(int i=1; i<=n; i++) scanf("%lld", arr+i);

        getall(1, n/2, 0, cost);
//        for(int i=0; i<cost.size(); i++){
//            cout<<cost[i]<<endl;
//        }
        getall(n/2+1, n, 0, another);
//        for(int i=0; i<another.size(); i++){
//            cout<<another[i]<<endl;
//        }
        sort(another.begin(), another.end());

        int sz = cost.size();
        CASE(caseno); bool found = false;

        for(int i=0; i<sz; i++){
            LL F = K - cost[i];
            if(F==0){
                printf(" Yes\n");
                found = true;
                break;
            }
            else if(F>0){
                if(binary_search(another.begin(), another.end(), F)){
                    found = true;
                    printf(" Yes\n");
                    break;
                }
            }
        }
        if(!found)
            printf(" No\n");
    }
}

