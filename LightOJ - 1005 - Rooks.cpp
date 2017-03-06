#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int m, n, k;
        scanf("%d %d", &n, &k);
        unsigned long long int ans = 1;
        if(k==1)
        {
            ans = n*n*k;
            printf("Case %d: %llu\n",caseno,ans );
            continue;
        }
        for(int i=1; i<=k; i++)
        {
            ans = (ans * n * n)/i;
            //cout<<ans<<endl;
            n--;
        }
        printf("Case %d: %llu\n",caseno,ans );
    }
    return 0;
}
