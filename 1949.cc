// 2022-02-27 21:35:56
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

int n, dp[10010][2], d[10010];
bool check[10010];
vector<int> graph[10010];

int func(int now, bool is_wusu){
    int &res = dp[now][is_wusu];
    if(res != -1){
        return res;
    }
    res = 0;
    check[now] = true;
    for(auto &x : graph[now]){
        if(check[x]) continue;
        int tmp = func(x, 0);
        if(!is_wusu) tmp = max(tmp, func(x, 1));
        res += tmp;
    }
    check[now] = false;
    return res += is_wusu * d[now];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << max(func(1, 0), func(1, 1));
}