#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main()
{
    int t, i=0, n;
    double r, R, a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %d",&R, &n);
        a = sin(PI/n);
        r = (R*a)/(a+1);
        printf("Case %d: %0.10lf\n",++i,r);
    }
    return 0;
}
