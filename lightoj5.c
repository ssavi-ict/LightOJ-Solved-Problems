#include<stdio.h>
int main()
{
    int t,i=1,m,n,s,a;
    scanf("%d",&t);
    while(t-- && t<=41000)
    {
            scanf("%d %d",&m ,&n);
            while(m>=1 && m<=200)
            {
                a=m*n;
                if((a%2)==0)
                    {printf("Case %d: %d\n",i++,a/2);break;}
                else
                    {printf("Case %d: %d\n",i++,a/2+1);break;}
            }
    }
    return 0;
}
