// 2022-03-07 13:04:10
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, dp[10010]={0,}, k, d;
    cin >> n >> k;
    dp[0]=1;
    while(n--){
        cin >> d;
        for(int j=d;j<=k;j++){
            dp[j] += dp[j-d];
        }
    }
    cout << dp[k];
}