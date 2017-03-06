#include<stdio.h>
int main()
{
    int a,b,t,i=1,c;
    scanf("%d",&t);
    while(t-- &&t>=0 && t<125)
    {

        scanf("%d %d",&a,&b);
        c=a+b;
        printf("Case %d: %d\n",i++,c);
    }
    return 0;
}
