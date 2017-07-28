#include<bits/stdc++.h>

using namespace std;

vector<int>arr;
vector<int>::iterator it, ir;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int n, x, m, st, en;
        scanf("%d %d", &n, &m);
        arr.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%d", &x);
            arr.push_back(x);
        }
        arr.push_back(100000002);
        printf("Case %d:\n", caseno);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &st, &en);
            it = lower_bound(arr.begin(), arr.end(), st);
            ir = lower_bound(arr.begin(), arr.end(), en);
            if(*ir==en) ir++;
            printf("%d\n", ir-it);
        }
    }
    return 0;
}

