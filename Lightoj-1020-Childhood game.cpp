#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, t, j=0;
    char s[6];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %s", &n,s);
        printf("Case %lld: ",++j);
        if(s[0]=='A')
        {
            if(n%3==1)
                printf("Bob");
            else
                printf("Alice");
        }
        else
        {
            if(n%3==0)
                printf("Alice");
            else
                printf("Bob");
        }
        printf("\n");
    }
    return 0;
}
