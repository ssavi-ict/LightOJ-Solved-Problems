#include<stdio.h>
#define pi 2*acos(0.0)
int main()
{
    double r, result, d, area_s, area_c;
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&r);
        if(r>0 && r<=1000)
        {
            d = 2*r;
            area_s = d*d;
            area_c = pi*r*r;
            result = area_s - area_c;

        }
        printf("Case %d: %.2lf\n",i,result);
    }
    return 0;
}
