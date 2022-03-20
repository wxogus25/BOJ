// 2022-03-03 16:54:37
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

int d[200010], dp[200010][21];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q, x;
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> d[i];
        dp[i][0] = d[i];
    }
    for(int k=1;k<20;k++){
        for(int i=1;i<=m;i++){
            dp[i][k] = dp[dp[i][k-1]][k-1];
        }
    }

    cin >> q;
    while(q--){
        cin >> n >> x;
        for(int i=0;i<20;i++){
            if(n & (1 << i)){
                x = dp[x][i];
            }
        }
        cout << x << '\n';
    }
}