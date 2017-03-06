#include<bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c, d, rati, result;
    int t, i=0;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        rati = d/(d+1);
        result = a*sqrt(rati);
        cout<<"Case "<<++i<<": "<<setprecision(12)<<result<<endl;
    }
    return 0;
}
