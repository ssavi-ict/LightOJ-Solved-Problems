#include<stdio.h>
int main()
{
    long long int t, n, bin[1000], i, j=0, rem, count;
    scanf("%lld",&t);
    while(t-- && t<=1000)
    {
        scanf("%lld",&n);
        count =0; i=1;
        while(n!=0)
        {
            bin[i]=n%2;
            if((n%2)==1)
            {
                count++;
            }
            n=n/2;
            i++;
        }
        if((count%2)==0)
            printf("Case %lld: even\n",++j);
        if((count%2)!=0)
            printf("Case %lld: odd\n",++j);
    }
    return 0;
}
