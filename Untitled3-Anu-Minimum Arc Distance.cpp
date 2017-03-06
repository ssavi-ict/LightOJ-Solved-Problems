#include<bits/stdc++.h>
#define PI acos(-1)

using namespace std;

int main()
{
    double a, b, o, result;
    double ox, oy, ax, ay, bx, by, angle;
    int t, i=0;
    cin>>t;
    while(t--)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        b = sqrt(((ox-ax)*(ox-ax)) + ((oy-ay)*(oy-ay)));
        //cout<<b<<endl;
        a = sqrt(((ox-bx)*(ox-bx)) + ((oy-by)*(oy-by)));
        //cout<<a<<endl;
        o = sqrt(((ax-bx)*(ax-bx)) + ((ay-by)*(ay-by)));
        //cout<<o<<endl;
        angle = acos((-o*o + a*a + b*b)/(2*a*b));
        //cout<<angle<<endl;
        result = a*angle;
        cout<<"Case "<<++i<<": "<<setprecision(12)<<result<<endl;
    }
    return 0;
}
