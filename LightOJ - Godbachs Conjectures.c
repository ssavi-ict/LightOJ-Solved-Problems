#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int status[10000000]={0};

int main()
{
    long long int i, j, k, l, count, t, cases=0,n, check;
    long long int sqrtN;
    sqrtN = sqrt(10000000);
    for(i=3;i<=sqrtN;i=i+2)
    {
        if(status[i]==0)
        {
            for(j=i*i;j<=10000000;j=j+i+i)
            {
                status[j]=1;
            }
        }
    }
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        count=0; check =0;
        if(n==4)
        {
            printf("Case %d: 1\n",++cases);
            continue;
        }
        for(i=3;i<=n/2;i=i+2)
        {
            if(status[i]==0 && status[n-i]==0 && i<=n-i)
            {
                count++;
            }
        }
        printf("Case %lld: %lld\n", ++cases, count);
    }
    return 0;
}
