#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    long long int x;
    scanf("%d",&test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        long long int r, c, corner;
        scanf("%lld",&x);
        long long int sqrs = ceil((double)sqrt(x));
        corner = (sqrs*sqrs) - (sqrs - 1);
        if(x==corner) { r = sqrs; c = sqrs; }
        else if(x>corner) { r = sqrs - abs(x-corner); c = sqrs; }
        else { r = sqrs; c = sqrs - abs(x-corner); }
        if(sqrs%2==0) swap(r,c);
        printf("Case %d: %lld %lld\n", caseno, r, c);
    }
    return 0;
}
