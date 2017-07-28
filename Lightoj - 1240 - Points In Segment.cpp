#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
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
        double Ax, Ay, Az, Bx, By, Bz, x, y, z;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Az, &Bx, &By, &Bz, &x, &y, &z);

        int cnt = 100;
        double dist1, dist2;
        while(cnt--)
        {
            double mid1x = (2.0*Ax + Bx)/3.0;double mid2x = (Ax + 2.0*Bx)/3.0;
            double mid1y = (2.0*Ay + By)/3.0;double mid2y = (Ay + 2.0*By)/3.0;
            double mid1z = (2.0*Az + Bz)/3.0;double mid2z = (Az + 2.0*Bz)/3.0;

            dist1 = sqrt(DIST3D(mid1x, x, mid1y, y, mid1z, z));
            dist2 = sqrt(DIST3D(mid2x, x, mid2y, y, mid2z, z));

            if(dist1>=dist2)
            {
                Ax = mid1x; Ay = mid1y; Az = mid1z;
            }
            else
            {
                Bx = mid2x; By = mid2y; Bz = mid2z;
            }
            cnt--;
        }
        printf("Case %d: %.12lf\n", caseno, min(dist1, dist2));
    }
}

