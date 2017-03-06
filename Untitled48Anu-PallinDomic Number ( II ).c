#include<stdio.h>

int main()
{
    long long int t, w, l=0, i, n, j, temp;
    scanf("%lld",&t);
    while(t--)
    {
       scanf("%lld",&n);
       j = 0;  temp = n;
       while(n!=0)
       {
           w=n%10;
           j = j*10+w;
           n = n/10;
       }
       if(j!=temp)
        printf("Case %lld: No\n",++l);
       else
        printf("Case %lld: Yes\n",++l);
    }
    return 0;
}

