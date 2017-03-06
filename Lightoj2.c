#include<stdio.h>
int main()
{
    int n,t,a,b;
    scanf("%d",&t);
    while(t-- && t>=0 && t<=25)
    {
        scanf("%d",&n);
        a=n/2;
        b=n-a;
        printf("%d %d\n",a,b);
    }
    return 0;
}
