#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int a, b, p, q, r, s, t, i=0, num;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>a>>b;
        p = ((a*(a+1))/2)%3;
        q = ((b*(b+1))/2)%3;
        r = (((a-1)*a)/2)%3;
        s = (((b+1)*(b+2))/2)%3;
        num = 0;
        if(p!=0 && q!=0)
        {
            num = (2*(b-a))/3;
        }
        else if((p!=0 && q==0) || (q!=0 && p==0))
        {
            if(q!=0)
                num = ((2*(b-a))/3) + q;
            else
                num = ((2*(b-a))/3) + p;
        }
        else
        {
            if((b-a)%3==0)
                {num = ((2*(b-a))/3) + 1;}
            else
                {
                    if(r==0 && s==0)
                         num = ((2*(b-a))/3) + 1;
                    else
                         num = ((2*(b-a))/3) + 2;
                }
        }
        cout<<"Case "<<++i<<": "<<num<<endl;
    }
    return 0;
}
