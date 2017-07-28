#include<bits/stdc++.h>

using namespace std;

int solve(int m, int d)
{
    int tot = 0;
    while(m>0)
    {
        tot = tot + m/d;
        m = m / d;
    }
    return tot;
}

int calc(int m, int d)
{
    int cnt = 0;
    while(m>0 && m%d==0)
    {
        cnt++;
        m = m / d;
    }
    //if(m>1) cnt++;
    return cnt;
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int p, q, n, r;
        scanf("%d %d %d %d", &n, &r, &p, &q);

        int factn2 = solve(n, 2);
        int factn5 = solve(n, 5);
        int factr2 = solve(r, 2);
        int factr5 = solve(r, 5);
        int factmin2 = solve(n-r, 2);
        int factmin5 = solve(n-r, 5);

        int two, five;
        two = factn2 - factr2 - factmin2 + (calc(p,2) * q);
        five = factn5 - factr5 - factmin5 + (calc(p,5) * q);
        printf("Case %d: %d\n",caseno, min(two, five));
    }
    return 0;
}
