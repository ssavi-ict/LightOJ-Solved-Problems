#include<stdio.h>
#include<math.h>

long long int prime[79000];
long long int b[1000003];
int main()
{
    long long int n,i,j=0,k,l, count=0, t, size, sum;
    for(i=1;i<=1000003;i++)
      {
        b[i]=i;
      }
    b[1]=0; l=1;
    for(i=2;i<=sqrt(1000003);i++)
    {
        if(b[i]!=0)
          {
            for(k=2*i;k<=1000003;k=k+i)
            if(b[k]!=0)
                b[k]=0;
          }
    }
    for(i=1;i<=1000003;i++)
    {
        if(b[i]!=0)
          prime[l++]=b[i];
    }
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        sum=1;
        for(i=1;prime[i]<=sqrt(n);i++)
        {
                count=1;
                while(n%prime[i]==0)
                {
                    n=n/prime[i];
                    count++;
                }
              sum = sum*count;
        }
        if(n>1)
            sum = sum*2;
        printf("Case %lld: %lld\n",++j,sum-1);
    }
    return 0;
}
