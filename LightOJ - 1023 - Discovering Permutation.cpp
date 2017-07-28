#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int n, k, cnt = 0;
        string a;
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++) a = a + (char)('A' + i);
        printf("Case %d:\n", caseno);
        do{
            cout<<a<<endl;
            cnt++;
            if(cnt==k) break;
        }while(next_permutation(a.begin(), a.end()));
    }
    return 0;
}
