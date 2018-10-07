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
#define MOD 1000003
#define MAX 10100
#define MOD 1000003
 
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        cout<<"Case "<<cas++<<": ";
        ll p,l;
        cin>>p>>l;
        p=p-l;
        vector < ll > ans;
        for (ll i=1;i*i<=p;i++){
            if (p%i == 0){
                if (i > l)
                    ans.pb(i);
                if (p/i > l && i*i != p)
                    ans.pb(p/i);
            }
        }
        if (ans.size() >= 1 ){
            sort(ans.begin(),ans.end());
            for (int i=0;i<ans.size()-1;i++){
                cout<<ans[i]<<" ";
            }
            cout<<ans[ans.size()-1]<<endl;
        }
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}