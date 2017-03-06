#include<stdio.h>
int main()
{
    int t,n,i,a[10000],j=1,sum;
    scanf("%d",&t);
    printf("\n");
    while(t-- && t<=100)
    {
        sum =0;
        scanf("%d",&n);
        if(n>1000 || n<=0)
        {break;}
        else
        {
            for(i=1; i<=n; i++)
            {
                scanf("%d",&a[i]);
                if(a[i]<100 && a[i]>=100)
                {sum=sum+a[i];}
                else
                {break;}
            }
            printf("Case %d: %d\n\n",j++,sum);
        }
    }
    return 0;
}
