#include<stdio.h>
#include<math.h>

int main()
{
    long long int m, n, t, j=0, ans, k, c, d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld", &m, &n);
        if(m==1 || n==1)
            ans = m*n;
        else if(m==2 || n==2)
        {
            if(m==2)
                k=n;
            else
                k=m;
            c = (k%4==0)?k/4:(k/4)+1;
            d = ((k-1)%4==0)?(k-1)/4:((k-1)/4)+1;
            ans= 2*(c+d);
        }
        else
            ans = ((m*n)%2==0)?(m*n)/2:((m*n)/2)+1;
        printf("Case %lld: %lld\n", ++j, ans);
    }
    return 0;
}
