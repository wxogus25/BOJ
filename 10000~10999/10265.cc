// 2022-02-23 20:03:47
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>

using namespace std;

int n, k, gcnt;
int d[1010], dp[2][1010];
bool finished[1010], check[1010];
struct data{
    int cnt, cycle_cnt;
} com[1010];

int group(int now){
    if(check[now] && !finished[now]){
        gcnt++;
        for(int x=now,c=d[now];x!=c;c=d[c]){
            com[gcnt].cycle_cnt++;
        }
        com[gcnt].cycle_cnt++;
        return d[now] = gcnt;
    }
    if(check[now]){
        return d[now];
    }
    check[now] = true;
    d[now] = group(d[now]);
    com[d[now]].cnt++;
    finished[now] = true;
    return d[now];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            group(i);
        }
    }
    fill(dp[0]+1,dp[0]+1009,-1);
    for(int i=1;i<=gcnt;i++){
        fill(dp[i%2],dp[i%2]+1010,-1);
        int q = com[i].cnt - com[i].cycle_cnt;
        for(int j=0;j<=k;j++){
            dp[i%2][j] = dp[(i+1)%2][j];
        }
        for(int j=com[i].cycle_cnt;j<=k;j++){
            if(dp[(i+1)%2][j-com[i].cycle_cnt] != -1){
                for(int w=0;w<=q && j+w <= k;w++){
                    dp[i%2][j+w]=1;
                }
            }
            if(j > k-q){
                break;
            }
        }
    }
    for(int w=k;w>=0;w--){
        if(dp[gcnt%2][w] != -1){
            cout << w;
            return 0;
        }
    }
}