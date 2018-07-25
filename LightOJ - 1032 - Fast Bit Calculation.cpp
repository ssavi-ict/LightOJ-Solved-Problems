#include<bits/stdc++.h>
#define i64 long long

using namespace std;


vector<int>dig;
i64 dp[33][2][2][33]; // Position, small, previous_digit, total 11 for a state

i64 solve(int pos, int small, int prv_dg, int tot)
{
    //cout<<pos<<' '<<small<<' '<<prv_dg<<' '<<tot<<endl;
    if(pos==dig.size()) return (i64)tot;
    if(dp[pos][small][prv_dg][tot]!=-1) return dp[pos][small][prv_dg][tot];

    i64 ret = 0;
    if(small==1){
        ret = ret + solve(pos+1, 1, 0, tot);
        ret = ret + solve(pos+1, 1, 1, tot+(prv_dg==1));
    }
    else{
        if(dig[pos]==1){
            ret = ret + solve(pos+1, 0, 1, tot+(prv_dg==1));
            ret = ret + solve(pos+1, 1, 0, tot);
        }
        else{
            ret = ret + solve(pos+1, 0, 0, tot);
        }
    }
    return (dp[pos][small][prv_dg][tot] = ret);
}

void bin(i64 N){

    while(N){
        dig.push_back(N%2);
        N/=2;
    }
    reverse(dig.begin(), dig.end());

}

int main(){
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++){
        i64 N;
        scanf("%lld", &N);
        dig.clear();
        memset(dp, -1, sizeof dp);
        bin(N);
        i64 ret = solve(0, 0, 0, 0);
        printf("Case %d: %lld\n", caseno, ret);
    }
}
