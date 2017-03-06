#include<stdio.h>
#include<math.h>
int main()
{
    long long int n, t, j=0, m, ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld", &n , &m);
        ans = (n/2)*m;
        printf("Case %lld: %lld\n",++j ,ans);
    }
    return 0;
}
