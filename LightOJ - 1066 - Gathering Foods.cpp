#include<bits/stdc++.h>
#define pii pair<char, pii2>
#define pii2 pair<int, int>
#define valid(a,b,n) (a>=0 && a<n && b>=0 && b<n)

using namespace std;

int N;
char graph[12][12];
int price[15][15];
bool visited[12][12];
int fx[]={0, 0, -1, 1};
int fy[]={1, -1, 0, 0};
bool found;

int BFS(char chx, int srcx, int srcy)
{
    memset(price, 0, sizeof(price));
    memset(visited, false, sizeof(visited));
    queue<pii2>q;
    q.push(pii2(srcx,srcy));
    graph[srcx][srcy] = '.';
    visited[srcx][srcy] = true;
    while(!q.empty())
    {
        pii2 top = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int f = top.first + fx[i];
            int s = top.second + fy[i];
            if(graph[f][s]==chx)
            {
                graph[f][s]='.';
                price[f][s] = price[top.first][top.second] + 1;
                found = true;
                return price[f][s];
            }
            if(valid(f,s,N) && graph[f][s]=='.' && !visited[f][s])
            {
                price[f][s] = price[top.first][top.second] + 1;
                visited[f][s] = true;
                q.push(pii2(f,s));
            }
        }
    }
    return 0;
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%d",&N);
        int srcx, srcy;
        found = false;
        set<pii>myset;
        set<pii>:: iterator it;
        myset.clear();
        memset(graph,'\0', sizeof(graph));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin>>graph[i][j];
                if(graph[i][j]>='A' && graph[i][j]<='Z')
                {
                    if(graph[i][j]=='A'){srcx = i; srcy = j; graph[i][j]='.'; found = true;}
                    else
                    {
                        //cout<<graph[i][j]<<i<<j<<endl;
                        myset.insert(pii(graph[i][j], pii2(i, j)));
                    }
                }
            }
        }

        char chx;
        int cost = 0, tot;
        for(it = myset.begin(); it!=myset.end(); ++it)
        {
            found = false;
            pii top = *it;
            chx = top.first;
            //cout<<chx<<' '<<srcx<<' '<<srcy<<endl;
            pii2 ntop = top.second;
            tot = BFS(chx, srcx, srcy);
            srcx = ntop.first;
            srcy = ntop.second;
            if(found)
                { cost = cost + tot;}
            else
                break;
        }
        if(!found)
            printf("Case %d: Impossible\n", caseno);
        else
            printf("Case %d: %d\n",caseno, cost);
    }
    return 0;
}
