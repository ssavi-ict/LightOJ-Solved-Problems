#include<bits/stdc++.h>

using namespace std;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main()
{
    unsigned long long int n, result;
    while(cin>>n && n!=0)
    {
        result = 1;
        if(n>=47)
        { cout<<"614889782588491410"<<endl; continue;}
        for(int i=0; ;i++)
        {
            if(prime[i]<=n)
                result = result*prime[i];
            else
                break;
        }
        cout<<result<<endl;
    }
    return 0;
}
