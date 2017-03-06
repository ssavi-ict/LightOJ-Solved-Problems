#include<bits/stdc++.h>
#define INF 999999999

using namespace std;

int matrix[105][105];

void init(int nodes)
{
    for(int i=1; i<=nodes; i++)
    {
        for(int j=1; j<=nodes; j++)
        {
            if(i==j) matrix[i][j]=0;
            else matrix[i][j] = INF;
        }
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        int nodes, edges, x, y, cost;
        scanf("%d %d",&nodes, &edges);
        init(nodes);
        for(int i=1; i<=edges; i++)
        {
            scanf("%d %d %d",&x, &y, &cost);
            if(cost<matrix[x][y]) matrix[x][y] = matrix[y][x] = cost;
        }
        for(int k=1; k<=nodes; k++)
        {
            for(int i=1; i<=nodes; i++)
            {
                for(int j=1; j<=nodes; j++)
                {
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        if(matrix[1][nodes]<INF)
        {
            printf("Case %d: %d\n", caseno, matrix[1][nodes]);
        }
        else if(matrix[1][nodes]>=INF)
        {
            printf("Case %d: Impossible\n", caseno);
        }
    }
    return 0;
}
