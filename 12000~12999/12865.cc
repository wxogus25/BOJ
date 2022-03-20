// 2022-02-17 20:17:24
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>

using namespace std;

int dp[2][100010];
int d[101][2];

int main(){
    int n,k,maxx=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> d[i][0] >> d[i][1];
    }
    fill(dp[0],dp[0]+100010,-1);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        fill(dp[i%2],dp[i%2]+100010,-1);
        for(int j=0;j<=k;j++){
            if(j<d[i][0]){
                dp[i%2][j] = dp[(i+1)%2][j];
            }else{
                if(dp[(i+1)%2][j-d[i][0]] != -1){
                    dp[i%2][j] = max(dp[(i+1)%2][j], dp[(i+1)%2][j-d[i][0]] + d[i][1]);
                    maxx = max(maxx, dp[i%2][j]);
                }else{
                    dp[i%2][j] = dp[(i+1)%2][j];
                }
            }
        }
    }
    cout << maxx;
}