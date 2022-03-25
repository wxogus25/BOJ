// 2022-02-24 19:12:54
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int memo[1000010];
int m;

int swapab(int now, int a, int b){
    int d[7]={0,}, w = 0;
    for(int i=0;i<7;i++){
        d[i] = now%10;
        now /= 10;
    }
    swap(d[a], d[b]);
    now = d[6];
    for(int i=5;i>=0;i--){
        now *= 10;
        now += d[i];
    }
    for(int c = now; c /= 10; w++);
    return (w == m) ? now : 0;
}

int main(){
    int n, k, max_k = 0;
    cin >> n >> k;
    for(int c = n; c /= 10; m++);
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    while(!q.empty()){
        pair<int, int> t = q.front(); q.pop();
        if(t.second == k) continue;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<=m;j++){
                int c = swapab(t.first, i, j);
                if(c == 0 || memo[c] == t.second + 1) continue;
                memo[c] = t.second + 1;
                q.push(make_pair(c, t.second + 1));
                max_k = t.second + 1;
            }
        }
    }
    if(max_k < k){
        cout << -1;
    }else{
        for(int i=1000000;i>0;i--){
            if(memo[i] == k){
                cout << i;
                return 0;
            }
        }
    }
}