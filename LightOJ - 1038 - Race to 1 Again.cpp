/*
The first person has a 100% chance of a unique number (of course)
The second has a (1 – 1/365) chance (all but 1 number from the 365)
The third has a (1 – 2/365) chance (all but 2 numbers)
The 23rd has a (1 – 22/365) (all but 22 numbers)
p(different) = 1 * (1-1/d) * (1 - 2/d) * (1 - 3/d) ....
p(exist a match) = 1 - p(different)
*/
 
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector < pii >
#define si set<int>
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MAX 10100
#define MOD 1000003
 
double ans[100100];
int divi[100100];
void precompute()
{
    ans[1]=0;
    for (int i=2;i<100100;i++){
        ans[i] = (ans[i] + divi[i] + 2)/((double)(divi[i] + 1));
        for (int j=2;i*j<100100;j++){
            ans[i*j] += ans[i];
            divi[i*j]++;
        }
    }
}
 
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    int t;
    cout << setprecision(7);
    cout << fixed;
    cin>>t;
    int cas=1;
    precompute();
    while (t--){
        cout<<"Case "<<cas++<<": ";
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}