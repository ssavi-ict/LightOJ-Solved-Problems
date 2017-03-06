#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[205];
    int test;
    int b;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%s %d",s, &b);
        b = b<0? b*(-1) : b;
        int sz = strlen(s);
        int start = 0;
        start = (s[0]=='-')?1:0;
        long long int d = 0;
        for(int i=start; i<sz; i++)
        {
            long long int mod = (s[i]-'0')%b;
            d = ((d*10)%b + mod)%b;
        }
        if(d==0)
            printf("Case %d: divisible\n",caseno);
        else
            printf("Case %d: not divisible\n", caseno);
    }
    return 0;
}
