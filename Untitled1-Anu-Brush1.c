#include<stdio.h>
int main()
{
    int t, n, x, j=0, i, sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("\n%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x>0)
                sum=sum+x;
        }
        printf("Case %d: %d\n",++j,sum);
    }
    return 0;
}
