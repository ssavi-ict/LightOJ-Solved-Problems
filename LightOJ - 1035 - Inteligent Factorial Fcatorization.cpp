#include<bits/stdc++.h>
#define MAX 100
#define LL long long int

using namespace std;

int primelist[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int factfreq[101][101];
int freq[101];

void solve()
{
    memset(factfreq,0,sizeof(factfreq));
    for(int i=0; i<26; i++) factfreq[1][primelist[i]] = 0;
    for(int i=2; i<=100; i++)
    {
        int cnt, num = i;
        memset(freq,0,sizeof(freq));
        for(int j=0; j<26; j++)
        {
            cnt=0;
            while(num%primelist[j]==0)
            {
                num = num / primelist[j];cnt++;
            }
            if(cnt>0) freq[primelist[j]] = cnt;
            if(num==1) break;
        }
        for(int l=0; l<26; l++)
        {
            factfreq[i][primelist[l]] = factfreq[i-1][primelist[l]] + freq[primelist[l]];
        }
    }
}

int main()
{
    solve();
    int test, n;
    scanf("%d",&test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        scanf("%d",&n);
        bool first = false;
        printf("Case %d: %d =", caseno, n);
        for(int i=0; i<26; i++)
        {
            if(factfreq[n][primelist[i]]>0 && !first)
            {
                printf(" %d (%d)",primelist[i], factfreq[n][primelist[i]]);
                first = true;
            }
            else if(factfreq[n][primelist[i]]>0 && first)
            {
                printf(" *");
                printf(" %d (%d)",primelist[i], factfreq[n][primelist[i]]);
            }


        }
        printf("\n");
    }
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int num[105][105];
int ans[105];
void  phi()
{
    memset(num,0,sizeof(num));
    for(int x=2;x<=100;x++)
    {
         int n=x;
         for(int i=2;i<(int)sqrt(1.0*n)+1;i++)
         {
                  if(n%i==0)
                  {
                           int cnt=0;
                           while(n%i==0)  cnt++,n/=i;
                           num[x][i]=cnt;
                  }
         }
         if(n>1) num[x][n]=1;
    }
}
int main()
{
    phi();
    int T,ca=0;
    cin>>T;
    while(T--)
    {
         int n,i,j;
         cin>>n;
         memset(ans,0,sizeof(ans));
         for( i=2;i<=100;i++)
              for(j=2;j<=n;j++) ans[i]+=num[j][i];
         printf("Case %d: %d = ",++ca,n);
         for(i=2;i<=100;i++)
                  if(ans[i]>0) {printf("%d (%d)",i,ans[i]);break;}
         for(i++;i<=100;i++)
                  if(ans[i]>0) printf(" * %d (%d)",i,ans[i]);
         printf("\n");
    }
    return 0;
}
*/
