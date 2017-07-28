#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
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
#define INV 1e-6
#define sll(a) scanf("%I64d", &a)
#define pll(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)

using namespace std;

vector<int>graph[20003];
bool invalid;
int visited[20003];

void DFS(int u)
{
    if(visited[u] == 2) { return;}
    if(visited[u] == 1) { invalid = true; return; }

    visited[u] = 1;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        DFS(v);

    }
    visited[u] = 2;
    return;
}

int main()
{
   int test;
   scanf("%d", &test);
   for(int caseno = 1; caseno<=test; caseno++)
   {
       int n;
       scanf("%d", &n);
       char name1[16], name2[16];
       map<string, int>mymap;
       int cnt = 1;
       for(int i=0; i<n; i++)
       {
           scanf("%s %s", name1, name2);
           if(mymap[name1]==0)
              mymap[name1] = cnt++;
           if(mymap[name2]==0)
              mymap[name2] = cnt++;

           graph[mymap[name1]].push_back(mymap[name2]);
       }

       memset(visited, 0, sizeof visited);

       invalid = false;
       for(int i=1; i<cnt; i++)
       {
           DFS(i);
       }

       CASE(caseno);
       if(invalid)
          printf(" No\n");
       else
          printf(" Yes\n");

        VCLR(graph, cnt+5);

   }
}

