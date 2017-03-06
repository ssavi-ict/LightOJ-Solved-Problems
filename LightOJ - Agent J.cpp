#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main()
{
    double r1, r2, r3, ar1, ar2, ar3, areat, p, c1, c2, c3, kon1, kon2, kon3;
    int i=0, t;
    cin>>t;
    while(t--)
    {
        cin>>c1>>c2>>c3;
        r1 = c1+c2;
        r2 = c1+c3;
        r3 = c2+c3;
        p = (r1+r2+r3)/2;
        areat = sqrt(p * (p-r1) * (p-r2) * (p-r3));
        kon1 = acos((-r1*r1 + r2*r2 + r3*r3)/(2*r2*r3)) * (180.0/PI);
        kon2 = acos((r1*r1 - r2*r2 + r3*r3)/(2*r1*r3)) * (180.0/PI);
        kon3 = acos((r1*r1 + r2*r2 - r3*r3)/(2*r1*r2)) * (180.0/PI);
        ar1 = (kon3/2) * (PI/180.0) * (c1*c1);
        ar2 = (kon2/2) * (PI/180.0) * (c2*c2);
        ar3 = (kon1/2) * (PI/180.0) * (c3*c3);
        double sum = ar1+ar2+ar3;
        cout<<"Case "<<++i<<": "<<setprecision(13)<<(areat-sum)<<endl;
    }
    return 0;
}
