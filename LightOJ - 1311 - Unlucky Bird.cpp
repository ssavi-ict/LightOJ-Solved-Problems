#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        double v1, v2, v3, a1, a2;
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
        double t1, t2, time;
        t1 = v1/a1; t2 = v2/a2;
        double dbird, dtot;
        time = t1>t2? t1: t2;
        dbird = v3 * time;
        dtot = (v1*t1) - (0.5 * a1 * t1 * t1) + (v2*t2) - (0.5 * a2 * t2 * t2);
        printf("Case %d: %.9lf %0.9lf\n", caseno, dtot, dbird);
    }
    return 0;
}
