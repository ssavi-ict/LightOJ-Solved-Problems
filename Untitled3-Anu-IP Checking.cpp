#include<bits/stdc++.h>

using namespace std;
long long int str[257];

int main()
{

    long long int i, j=0, a, b, c, d;
    long long int  A, B, C, D, t;
    for(i=0; i<=255; i++)
    {
        long long int rem, l=1, binary=0;
        long long int n = i;
        while (n!=0)
        {
            rem=n%2;
            n/=2;
            binary+=rem*l;
            l*=10;
        }
        str[i]=binary;
        //cout<<str[i]<<endl;
    }
   cin>>t;
    while(t--)
    {
        scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
        scanf("%lld.%lld.%lld.%lld",&A,&B,&C,&D);
        cout<<"Case "<<++j<<": ";
        if(str[a]==A)
        {
            if(str[b]==B)
            {
                if(str[c]==C)
                {
                    if(str[d]==D)
                    {
                        cout<<"Yes"<<endl;
                    }
                    else cout<<"No"<<endl;
                }
                else cout<<"No"<<endl;
            }
            else cout<<"No"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}
