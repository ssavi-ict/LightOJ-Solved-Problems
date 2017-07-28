#include<bits/stdc++.h>

using namespace std;

int recursion(int n, int k)
{
    if(n==1) return 0;
    else return (recursion(n-1, k)+k)%n;
}

int main()
{
    int n, k, test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        scanf("%d %d", &n, &k);
        int ans = recursion(n,k);
        printf("Case %d: %d\n", caseno, ans+1);
    }
    return 0;
}
