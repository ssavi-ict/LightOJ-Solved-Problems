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

vector<int>graph[10009];
bool visited[10009];
int nodcnt;
vector<int>sl;

void DFS(int u)
{
    if(visited[u])  return;
    visited[u] = true;

    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        DFS(v);
    }

    sl.push_back(u);
    return;
}

int main()
{
   int test;
   scanf("%d", &test);
   for(int caseno = 1; caseno<=test; caseno++)
   {
       int node, edge;
       scanf("%d %d", &node, &edge);

       ERASE(visited, false);
       for(int i=0; i<edge; i++)
       {
           int u, v;
           scanf("%d %d", &u, &v);
           graph[u].push_back(v);
       }

       nodcnt = 0;
       for(int i=1; i<=node; i++)
       {
           if(!visited[i]) DFS(i);
       }

       ERASE(visited, false);

       //Jehetu value gula Topologically sorted sehetu amader ekhon dekhte hobe je thik gula alada component ache
       for(int i=sl.size()-1; i>=0; i--)
       {
           if(!visited[sl[i]])
           {
               DFS(sl[i]);
               nodcnt++;
           }
       }

       CASE(caseno);
       printf(" %d\n", nodcnt);
       VCLR(graph, node+5);
       sl.clear();

   }
}

