#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, t, m, n, s, d, k, x, y, l=0;
    char c;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(j=1; j<=m; j++)
        {
            cin>>c;
            if(c=='R')
            {
                reverse(a,a+n);
            }
            else if(c == 'S')
            {
                cin>>s;
                for(i=0;i<n; i++)
                    { a[i] = a[i] + s;}
            }
            else if(c=='M')
            {
                cin>>d;
                for(i=0; i<n; i++)
                    { a[i] = a[i]*d;}
            }
            else if(c=='D')
            {
                cin>>k;
                for(i=0; i<n; i++)
                    { a[i] = a[i]/k;}
            }
            else
            {
                cin>>x>>y;
                swap(a[x], a[y]);
            }
        }
        cout<<"Case "<<++l<<":"<<endl;
        for(i=0; i<n; i++)
            { cout<<a[i]; if(i<n-1) cout<<' '; }
        cout<<endl;
    }
    return 0;
}
