#include<stdio.h>
#include<math.h>

int main()
{
    long long int a, b, c, d, e, f, n, arr[10001], i, t, j=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        arr[0]=a; arr[1]=b; arr[2]=c; arr[3]=d; arr[4]=e; arr[5]=f;
        for(i=6;i<=n;i++)
        {
            arr[i] = (arr[i-6]+arr[i-5]+arr[i-4]+arr[i-3]+arr[i-2]+arr[i-1])%10000007;
        }
        printf("Case %lld: %lld\n",++j,arr[n]%10000007);
    }
    return 0;
}
