#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define MAX 1000008
#define PI acos(-1)

using namespace std;


int main()
{
    long long int t, w, even, j=0;
    cin>>t;
    while(t--)
    {
        cin>>w;
        if(w%2!=0)
            cout<<"Case "<<++j<<": Impossible"<<endl;
        else
        {
            even = 1;
            while(w%2==0)
            {
                even = even*2;
                w = w/2;
            }
            cout<<"Case "<<++j<<": "<<w<<" "<<even<<endl;
        }
    }
    return 0;
}
