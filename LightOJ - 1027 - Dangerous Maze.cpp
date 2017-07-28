#include<bits/stdc++.h>

using namespace std;

int euclid(int a, int b)
{
    if(b==0) return a;
    else return euclid(b, a%b);
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        int n, total = 0, x, neg = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &x);
            if(x<0) neg++;
            total = total + abs(x);
        }
        if(neg==n)
            printf("Case %d: inf\n", caseno);
        else
            printf("Case %d: %d/%d\n", caseno, total/euclid(total, n-neg), (n-neg)/euclid(total, n-neg) );
    }
    return 0;
}
