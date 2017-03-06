#include<stdio.h>
#include<math.h>

int main()
{
    int t, a, b, i, ans, j, x, y, let;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a, &b);
        for(i=a; i<=b ;i++)
        {
            let = (i*(i+1))/2;
            printf("%d\n",let);
            if(let%3==0)
            {
                x=let;break;
            }
        }
        for(i=b; i>=a; i--)
        {
            let = (i*(i+1))/2;
            printf("%d\n",let);
            if(let%3==0)
            {
                y=let; break;
            }
        }
        ans = (y-x)/3;
        printf("%d\n",ans);
    }
    return 0;
}
