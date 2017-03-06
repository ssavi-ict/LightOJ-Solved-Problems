#include<stdio.h>
int main()
{
    int t, x1,y1,x2,y2,m, p1,p2,i,j=0,x,y;
    scanf("%d",&t);
    while(t-- && t<=50)
    {
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&m);
        if(m>=1 && m<=100)
        {
            printf("Case %d:\n",++j);
            for(i=1;i<=m;i++)
            {
                scanf("%d%d",&x,&y);
                if((x>x1 && x<x2) && (y>y1 && y<y2))
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
    }
    return 0;
}
