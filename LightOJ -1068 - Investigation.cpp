#include<bits/stdc++.h>
#define i64 long long

using namespace std;

vector<int>dig;
i64 dp[11][2][82][82];
int K;

i64 solve(int pos, int sml, int rem, int sum)
{
    if(pos==dig.size()){
        //cout<<rem<<' '<<sum<<endl;
        return ( rem==0 && sum == 0);
    }
    if(dp[pos][sml][rem][sum]!=-1) return dp[pos][sml][rem][sum];
    i64 ret = 0;
    if(sml){
        for(int i=0; i<=9; i++){
            ret = ret + solve(pos+1, 1, (rem*10+i)%K, (sum+i)%K);
        }
    }
    else{
        for(int i=0; i<=dig[pos]; i++){
            if(i<dig[pos])ret = ret + solve(pos+1, 1, (rem*10+i)%K, (sum+i)%K);
            else ret = ret + solve(pos+1, 0, (rem*10+i)%K, (sum+i)%K);
        }
    }

    return (dp[pos][sml][rem][sum] = ret);
}

i64 rec(i64 N)
{
    memset(dp, -1, sizeof dp);
    dig.clear();
    while(N){
        dig.push_back(N%10);
        N/=10;
    }
    reverse(dig.begin(), dig.end());

    return solve(0, 0, 0, 0);
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++){
        i64 A, B;
        scanf("%lld %lld %d", &A, &B, &K);
        if(K>81){
            printf("Case %d: 0\n", caseno); continue;
        }
        else{

            //cout<<rec(B)<<' '<<rec(A-1)<<endl;
            printf("Case %d: %lld\n", caseno, rec(B) - rec(A-1));
        }
    }
}
