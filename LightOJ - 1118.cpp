#include<bits/stdc++.h>
#define PI acos(-1)

using namespace std;

int main()
{
    int t, j=0;
    scanf("%d",&t);
    while(t--)
    {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int x = x1 - x2;
        int y = y1 - y2;
        double d = sqrt((double)(x*x + y*y));
        double R, r;
        if(r1>=r2)
         {
            R = (double)r1;
            r = (double)r2;
         }
         else
         {
             R = r2;
             r = r1;
         }
        double area;
        if(d>R+r)
            { area = 0.00; }
        else if(d<=fabs(R-r))
        {
            area = PI * r * r;
        }
        else
        {
            double a = 0.5 * sqrt((-d + r + R)*(d + r - R)*(d - r + R)*(d + r + R));
            double area1 = (r*r)*acos(((r*r) + (d*d) - (R*R))/(2*d*r));
            double area2 = (R*R)*acos(((R*R) + (d*d) - (r*r))/(2*d*R));
            area = area1 + area2 - a;
        }
        printf("Case %d: %0.10lf\n",++j,area);

    }
    return 0;
}
