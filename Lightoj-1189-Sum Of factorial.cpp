#include<bits/stdc++.h>

using namespace std;
long long int f[21], a[21];
int main()
{
    int t, caseno=0;
    scanf("%d",&t);
    f[0]=1;
    for(int i=1; i<21; i++)
    {
        f[i] = f[i-1]*i;
    }
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        int l=0;
        for(int i=20; i>=0; i--)
        {
            if(n>=f[i])
            {
                n = n - f[i];
                a[l++]=i;
            }
        }
        printf("Case %d: ",++caseno);
        if(n!=0)
            printf("impossible\n");
        else
        {
            for(int i=l-1; i>=0; i--)
            {
                printf("%d!",a[i]);
                if(i>0)
                    printf("+");
            }
            printf("\n");
        }
    }
    return 0;
}
