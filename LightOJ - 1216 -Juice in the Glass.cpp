#include<bits/stdc++.h>
#define PI acos(-1)

using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        int r1, r2, p, h;
        scanf("%d%d%d%d",&r1,&r2,&h,&p);
        double R = r2;
        double r = r2+(double)(r1-r2)*((double)(p)/(double)h);
        double V = 1/3.0*PI*p*(R*R+R*r+r*r);
        printf("Case %d: %.10lf\n",caseno,V);

    }
    return 0;
}

