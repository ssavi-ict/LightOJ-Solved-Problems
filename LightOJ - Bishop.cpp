#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t, j=0;
    scanf("%d",&t);
    while(t--)
    {
        long long int r1, c1, r2, c2;
        scanf("%lld %lld %lld %lld", &r1, &c1, &r2, &c2);
        int p1=0, p2=0;
        p1 = r1%2!=0?(c1%2==0?1:2):(c1%2==0?2:1);
        p2 = r2%2!=0?(c2%2==0?1:2):(c2%2==0?2:1);
        printf("Case %d: ",++j);
        if(p1!=p2)
            printf("impossible\n");
        else
        {
            if(fabs(c2-c1)/fabs(r2-r1)==1.00)
                printf("1\n");
            else
               printf("2\n");
        }
    }
    return 0;
}
