#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        double a, b, c, d, l, x, ans, h;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        if(a<c) swap(a,c);
        if(d<b) swap(b,d);
        l = a - c;
        x = (d*d - b*b + l*l);
        x = x / (2.0 * l);
        h = (d*d) - (x*x);
        h = sqrt(h);
       // cout<<h<<endl;
        ans = ((a+c) * h) / 2;
        printf("Case %d: %0.10lf\n", caseno, ans);
    }
    return 0;
}
