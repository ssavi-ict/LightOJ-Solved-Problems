#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i, j=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(i=1; i<=n; i++)
            cin>>a[i];
        int count =0, got;
        a[0]=2;
        for(i=1; i<=n; i++)
        {
            got = a[i] - a[i-1];
            if(got>0)
            {
                int rem=(got%5==0)?0:1;
                int vag = got/5;
                count = count+vag+rem;
            }
        }
        cout<<"Case "<<++j<<": "<<count<<endl;
    }
    return 0;
}
