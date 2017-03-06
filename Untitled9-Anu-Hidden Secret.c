#include<stdio.h>
#include<string.h>

int main()
{
    char s1[102], s2[102];
    int a[27], b[27], i, j, k, l, t, check, cases=0;
    char word[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s1);
        for(i=0;s1[i]!='\0';i++)
            s1[i] = tolower(s1[i]);
        gets(s2);
        for(i=0;s2[i]!='\0';i++)
            s2[i] = tolower(s2[i]);
        for(i=0;i<26;i++)
        {
            k=0; l=0;
            for(j=0;s1[j]!='\0';j++)
            {
                if(word[i]==s1[j])
                    k++;
            }
            for(j=0;s2[j]!='\0';j++)
            {
                if(word[i]==s2[j])
                    l++;
            }
            a[i]=k; b[i]=l;
        }
        check=0;
        for(i=0;i<26;i++)
        {
            if(a[i]==b[i])
            {
                check = 1;
            }
            else
            {
                check =0;
                break;
            }
        }
        if(check==0)
            printf("Case %d: No\n",++cases);
        else
            printf("Case %d: Yes\n",++cases);
    }
    return 0;
}
