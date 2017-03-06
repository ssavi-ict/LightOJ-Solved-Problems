#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    long long int sum, k, t,i=0,n,j;
    scanf("%lld",&n);
    for(j=1;j<=n;j++)
    {
        sum =0;
        scanf("%lld",&t);
        printf("Case %lld:\n",++i);
        while(t-- && t<= 100)
        {
            scanf("%s",a);
            if(a[0]=='d' || a[0]=='D')
            {
                scanf("%lld",&k);
                sum=sum+k;
            }
            if(a[0]=='r' || a[0]=='R')
            {
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}
