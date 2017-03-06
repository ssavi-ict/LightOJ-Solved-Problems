#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, digit, test;
    scanf("%d",&test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%d %d", &n, &digit);
        int cnt=1;
        int a = digit%n;
        while(a!=0)
        {
             a = ((a*10)%n + (digit%n))%n;
             cnt++;
        }
        printf("Case %d: %d\n", caseno, cnt);
    }
    return 0;
}

