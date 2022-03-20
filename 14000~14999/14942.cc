// 2022-03-03 20:21:11
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

typedef pair<int, int> pii;
int dp[100010][20][2]; // 거리, 정점번호
int energy[100010];
bool check[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> energy[i];
    }
    vector<vector<pii> > e(n + 1);
    for(int i=1;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back(pii(b, c));
        e[b].push_back(pii(a, c));
    }

    queue<int> q;
    q.push(1);
    check[1] = true;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto x : e[now]){
            if(check[x.first]) continue;
            check[x.first] = true;
            dp[x.first][0][0] = x.second;
            dp[x.first][0][1] = now;
            q.push(x.first);
        }
    }

    for(int k=1;k<20;k++){
        for(int i=1;i<=n;i++){
            if(dp[dp[i][k-1][1]][k-1][1]){
                dp[i][k][0] = dp[i][k-1][0] + dp[dp[i][k-1][1]][k-1][0];
                dp[i][k][1] = dp[dp[i][k-1][1]][k-1][1];
            }
        }
    }

    for(int i=1;i<=n;i++){
        int now = i;
        for(int k=19;k>=0;k--){
            if(now == 1){
                break;
            }
            if(dp[now][k][1] && dp[now][k][0] <= energy[i]){
                energy[i] -= dp[now][k][0];
                now = dp[now][k][1];
            }
        }
        cout << now << '\n';
    }
}