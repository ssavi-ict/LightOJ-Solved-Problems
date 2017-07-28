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
#define INV 1e-6
#define sl(a) scanf("%I64d", &a)
#define pl(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 600005
#define CASE(i) printf("Case %d: ", i);
#define PI acos(-1)
#define EPS 0.00000001

using namespace std;

vector<int>arr;

int main()
{
    int test, n, x;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
       arr.clear();
       scanf("%d", &n);
       for(int i=0; i<n; i++){
           scanf("%d", &x);
           arr.push_back(x);
       }

       sort(arr.begin(), arr.end());

       long long cnt = 0;
       for(int i=0; i<n-2; i++)
       {
           for(int j=i+1; j<n-1; j++)
           {
               int have = arr[i] + arr[j];
               int ind = lower_bound(arr.begin()+j, arr.end(), have) - arr.begin();
               //cout<<arr[ind]<<endl;
               int so = (ind - 1 - j);
               if(so>0)
               {
                   cnt = cnt + so;
                   //cout<<i<<' '<<j<<' '<<ind<<endl;
               }
           }
       }
       printf("Case %d: %lld\n", caseno, cnt);
    }
}

