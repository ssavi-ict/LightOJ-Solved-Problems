#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector <int>
#define si set <int>
#define mp make_pair
#define pb push_back
#define fr first
#define se second
#define pii pair <int,int>
 
int f[50][3][26];
queue < pair<string,int> > q;
map <string,bool> ma;
int n;
 
void clea()
{
    while (!q.empty())
        q.pop();
    memset(f,0,sizeof(f));
    ma.clear();
}
 
bool che(string s)
{
    bool ret = true;
    for (int i=0;i<n;i++){
        if (f[i][0][s[0]] == 1 && f[i][1][s[1]] && f[i][2][s[2]])
            return false;
    }
    return true;
}
 
 
int main ()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        clea();
        string st,en;
        cin>>st;
        cin>>en;
        cin>>n;
        string fo[3];
        for (int i=0;i<n;i++){
            cin>>fo[0]>>fo[1]>>fo[2];
            for (int j=0;j<fo[0].size();j++)
                f[i][0][fo[0][j]]=1;
            for (int j=0;j<fo[1].size();j++)
                f[i][1][fo[1][j]]=1;
            for (int j=0;j<fo[2].size();j++)
                f[i][2][fo[2][j]]=1;
        }
        int ans=-1;
        if (che(st) && che(en))
            q.push(mp(st,0));
        while (!q.empty()){
            pair <string,int> po=q.front();
            q.pop();
            if (po.fr==en){
                ans=po.se;
                break;
            }
            if (ma.find(po.fr)!=ma.end())
                continue;
            ma[po.fr]=true;
            for (int i=0;i<3;i++){
                string ne1=po.fr;
                string ne2=po.fr;
                if (po.fr[i]=='a'){
                    ne1[i]='z';
                    ne2[i]='b';
                }
                else if (po.fr[i]=='z'){
                    ne1[i]='y';
                    ne2[i]='a';
                }
                else {
                    ne1[i]=po.fr[i]-1;
                    ne2[i]=po.fr[i]+1;
                }
                if (che(ne1))
                    q.push(mp(ne1,po.se+1));
                if (che(ne2))
                    q.push(mp(ne2,po.se+1));
            }
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}