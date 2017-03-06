#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n, i, j, k, l, count, t, tc=0;
    int a[1005], b[1005], c[1005], d[35][1005];
        for(i=1000;i>0;i--)
        {
            count=0;
            for(j=1;j<=i;j++)
            {
                if((i)%j==0)
                {
                    count++;
                }
            }
            a[i]=count;
        }
        k=0;
        for(l=1;l<=32;l++)
        {
            j=0;
            for(i=1;i<=1000;i++)
            {
                if(a[i]==l)
                {
                    d[l][++j]=i;
                }
            }
            c[l]=j;
            for(j=c[l];j>=1;j--)
              {
                  b[++k]=d[l][j];
              }
        }
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&n);
            printf("Case %d: %d\n",++tc, b[n]);
        }
        return 0;
}
