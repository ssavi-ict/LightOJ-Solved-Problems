#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int t, n, i, l, w, d, max, min, j=0, x, y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int vol[n];
        char a[n][21];
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d %d", a[i], &l, &w, &d);
            vol[i] = l*w*d;
        }
        max = 1, min = 1000001;
        for(i=0;i<n;i++)
        {
            if(vol[i]>max)
            {
                max = vol[i];
                x = i;
            }
            if(vol[i]<min)
            {
                min = vol[i];
                y = i;
            }
        }
        if(max==min)
            printf("Case %d: no thief\n",++j);
        else
        {
            printf("Case %d: %s took chocolate from %s\n", ++j, a[x], a[y]);
        }
    }
    return 0;
}
