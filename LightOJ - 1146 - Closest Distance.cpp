
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

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);

        int cnt = 100;
        double dist1, dist2;
        while(cnt--)
        {
            double mid1x = (2.0*Ax + Bx)/3.0;double mid2x = (Ax + 2.0*Bx)/3.0;
            double mid1y = (2.0*Ay + By)/3.0;double mid2y = (Ay + 2.0*By)/3.0;
            double mid3x = (2.0*Cx + Dx)/3.0;double mid4x = (Cx + 2.0*Dx)/3.0;
            double mid3y = (2.0*Cy + Dy)/3.0;double mid4y = (Cy + 2.0*Dy)/3.0;

            dist1 = sqrt(DIST(mid1x, mid3x, mid1y, mid3y));
            dist2 = sqrt(DIST(mid2x, mid4x, mid2y, mid4y));

            if(dist1>=dist2)
            {
                Ax = mid1x; Ay = mid1y;
                Cx = mid3x; Cy = mid3y;
            }
            else
            {
                Bx = mid2x; By = mid2y;
                Dx = mid4x; Dy = mid4y;
            }
            cnt--;
        }
        printf("Case %d: %.12lf\n", caseno, min(dist1, dist2));
    }
}
