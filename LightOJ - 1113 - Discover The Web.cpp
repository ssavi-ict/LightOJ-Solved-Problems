
#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define PB(a, b) a.push_back(b)
#define PB2(a,i,b) a[i].push_back(b)
#define LL long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define II(a) scanf("%I64d", &a)
#define PP(a) printf("%I64d", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define pii2 pair<int, pii>
#define MAX 1000
#define MAXN 100007
#define logbase(a, b) ( log10(a)/log10(b) )
#define DIR(f,s,R,C) (f>=0 && f<R && s>=0 && s<C)
#define DIR1(f,s,R,C) (f>=1 && f<=R && s>=1 && s<=C)

using namespace std;

vector<string>web;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        web.clear();
        printf("Case %d:\n", caseno);
        string com, site, str;
        int i = 0, j;
        web.push_back("http://www.lightoj.com/");
        j = web.size()-1;
        while(cin>>com)
        {
            if(com=="QUIT") break;

            if(com=="VISIT")
            {
                cin>>site;
                cout<<site<<endl;
                if(j<web.size() - 1)
                {
                    web.erase(web.begin()+j + 1, web.end());
                }
                web.push_back(site);
                j = web.size() - 1;
            }
            else if(com=="FORWARD")
            {
                //cout<<j<<endl;
                if(j+1==web.size()) printf("Ignored\n");
                else
                {
                    j = j + 1;
                    cout<<web[j]<<endl;
                }
            }
            else if(com=="BACK")
            {
                //cout<<j<<endl;
                if(j-1<0) printf("Ignored\n");
                else
                {
                    j = j - 1;
                    cout<<web[j]<<endl;
                }
            }
        }

    }
}

