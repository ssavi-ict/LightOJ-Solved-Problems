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
#define MAX 1000
#define MAXN 100007
#define logbase(a, b) ( log10(a)/log10(b) )
#define DIR(f,s,R,C) (f>=0 && f<R && s>=0 && s<C)
#define DIR1(f,s,R,C) (f>=1 && f<=R && s>=1 && s<=C)

using namespace std;

vector<pii>points;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        points.clear();
        int N, W, x, y;
        scanf("%d %d", &N, &W);
        for(int i=0; i<N; i++)
        {
            scanf("%d %d", &x, &y);
            points.push_back(pii(y,x));
        }
        sort(points.begin(), points.end());

        int mova = 0, sz = 0;
        for(int i=0; i<N; )
        {
            sz = points[i].first + W;
            mova++; int j;
            for(j=i; j<N; j++)
            {
                if(points[j].first>sz) break;
            }
            i = j;
        }

        int movb = 0; sz = 0;
        for(int i=N-1; i>=0 ; )
        {
            sz = points[i].first - W;
            movb++; int j;
            for(j=i; j>=0 ; j--)
            {
                if(points[j].first<sz) break;
            }
            i = j;
        }

        printf("Case %d: %d\n", caseno, min(mova, movb));
    }
}

