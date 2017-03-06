#include<stdio.h>
int main()
{
    long long int a, b, c, mul1, mul2, t, i,max;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a>=1 && a<=40000 && b>=1 && b<=40000 && c>=1 && c<=40000)
        {
            if(a>=b && a>c)
                {
                    max=a;
                    mul1 = max*max;
                    mul2 = (b*b) + (c*c);
                }
            else if(b>a && b>=c)
                {
                    max=b;
                    mul1 = max*max;
                    mul2 = (a*a) + (c*c);
                }
            else
                {
                  max=c;
                  mul1 = max*max;
                  mul2 = (a*a) + (b*b);
                }
        }
        if(mul1==mul2)
        {
            printf("Case %d: yes\n",i);
        }
        else
        {
            printf("Case %d: no\n",i);
        }
    }
    return 0;
}
