#include<stdio.h>
int main()
{
    int a, b, t, min, time1, sum1, time2, sum,i=0;
    scanf("%d",&t);
    while(t-- && t<=25)
    {
        scanf("%d%d",&a,&b);
        if(a>0 && b<=100)
        {
            if(a<b)
            {
                min = b-a;
                time1 = min*4;
                sum1 = time1+3+5+3;
                time2 = (a-0)*4;
                sum = sum1+time2+5+3;
            }
            if(a>=b)
            {
                min = a-b;
                time1 = min*4;
                sum1 = time1+3+5+3;
                time2 = (a-0)*4;
                sum = sum1+time2+5+3;
            }
            printf("Case %d: %d\n",++i,sum);
        }
    }
    return 0;
}
