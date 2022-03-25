// 2022-02-17 22:54:34
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>

using namespace std;

int n, d[1010];
int dp[1010];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    for(int i=n;i>=1;i--){
        dp[i]=d[i];
        for(int j=i+1;j<=n;j++){
            if(d[j] > d[i]){
                dp[i] = max(dp[i], dp[j] + d[i]);
            }
        }
    }
    int maxx = 0;
    for(int i=1;i<=n;i++){
        maxx = max(maxx, dp[i]);
    }
    cout << maxx;
}