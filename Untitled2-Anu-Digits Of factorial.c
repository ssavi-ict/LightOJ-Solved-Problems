#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double sum[1000010];

int main()
{
    long long int n, b, i, t, ans, j=0;
    for(i=1;i<=1000000;i++)
    {
       sum[i] = sum[i-1]+log(i);
    }
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n, &b);
        ans = sum[n]/log(b);
        printf("Case %lld: %lld\n",++j,ans+1);
    }
    return 0;
}
