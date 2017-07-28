#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        long long x1, y1, z1, x2, y2, z2;
        long long xx1 = 0, yy1 = 0, zz1 = 0, xx2 = 1001, yy2 = 1001, zz2 = 1001;
        long long xx = 0, yy = 0, zz = 0;
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
        scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &z1, &x2, &y2, &z2);
        xx1 = max(xx1,x1);
        xx2 = min(xx2,x2);
        yy1 = max(yy1,y1);
        yy2 = min(yy2,y2);
        zz1 = max(zz1,z1);
        zz2 = min(zz2,z2);
        }
        xx = abs(xx1-xx2);
        yy = abs(yy1-yy2);
        zz = abs(zz1-zz2);
        if(xx1>=xx2) xx = 0;
        if(yy1>=yy2) yy = 0;
        if(zz1>=zz2) zz = 0;
        printf("Case %d: %lld\n", caseno, xx*yy*zz);
    }
    return 0;
}

