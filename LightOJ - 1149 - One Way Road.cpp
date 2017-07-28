#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        bool arrLeft[106],arrRight[106] ;
        int u, v, w, con, costone = 0, costtwo = 0;
        scanf("%d", &con);
        memset(arrLeft, false, sizeof(arrLeft));
        memset(arrRight, false, sizeof(arrRight));
        for(int i=0; i<con; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            if(!arrLeft[u] && !arrRight[v])
            {
                costone = costone + w;
                arrLeft[u] = arrRight[v] = true;
            }
            else
            {
                arrLeft[v] = arrRight[u] = true;
                costtwo = costtwo + w;
            }
        }
        printf("Case %d: %d\n",caseno,  min(costone, costtwo));
    }
    return 0;
}
