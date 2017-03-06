#include<bits/stdc++.h>

#define MAX 10000005

using namespace std;

int status[(MAX/32)+2];
int golbachs[664580];

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}
int len;
void sieve()
{
    int sqrtN=int (sqrt(MAX));
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAX; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
    len = 1;
    golbachs[0]=2;
    for(int i=3; i<=MAX; i=i+2)
    {
        if(check(status[i>>5], i&31)==0)
        {
            golbachs[len]=i;
            len++;
        }
    }

}

int main()
{
    sieve();
    int t, N;
    scanf("%d",&t);
    int cases=0;
    while(t--)
    {
        scanf("%d",&N);
        int cnt = 0;
        if(N==4)
        {
            cnt=1;
            printf("Case %d: %d\n", ++cases, cnt);
            continue;
        }
        for(int i=0; golbachs[i]<=N/2; i++)
        {
            if((check(status[(N-golbachs[i])>>5], (N-golbachs[i])&31)==0))
                cnt++;
        }
        printf("Case %d: %d\n", ++cases, cnt-1);
    }
    return 0;
}
