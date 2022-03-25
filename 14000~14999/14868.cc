// 2022-03-01 19:33:52
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

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, n, k;
int d[100010], g[2010][2010], lv[2020][2020];

int find(int now){
    if(d[now] < 0) return now;
    return d[now] = find(d[now]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    d[a] += d[b];
    d[b] = a;
}

typedef struct v{
    int x, y, group, level;
    v(int X, int Y, int Group, int Level) : x(X), y(Y), group(Group), level(Level) {}
} v;

bool check(int x, int y){
    return !(x < 1 || x > n || y < 1 || y > n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    queue<v> q;
    for(int i=1;i<=k;i++){
        int x, y;
        cin >> x >> y;
        g[x][y] = i;
        d[i] = -1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]){
                int a, b;
                if(g[i+1][j] && i+1 <= n){
                    a = find(g[i][j]);
                    b = find(g[i+1][j]);
                    merge(a, b);
                }
                if(g[i][j+1] && j+1 <= n){
                    a = find(g[i][j]);
                    b = find(g[i][j+1]);
                    merge(a, b);
                }
                ans = min(ans, d[find(g[i][j])]);
                q.push(v(i, j, find(g[i][j]), 0));
            }
        }
    }
    if(ans + k == 0){
        cout << 0;
        return 0;
    }
    int lev = 0;
    while(!q.empty()){
        v tmp = q.front();
        q.pop();
        if(lev != tmp.level){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(g[i][j]){
                        int a, b;
                        if(g[i+1][j] && i+1 <= n){
                            a = find(g[i][j]);
                            b = find(g[i+1][j]);
                            merge(a, b);
                        }
                        if(g[i][j+1] && j+1 <= n){
                            a = find(g[i][j]);
                            b = find(g[i][j+1]);
                            merge(a, b);
                        }
                        ans = min(ans, d[find(g[i][j])]);
                    }
                }
            }
            if(ans + k == 0){
                cout << lev + 1;
                return 0;
            }
            lev = tmp.level;
        }
        for(int i=0;i<4;i++){
            if(check(tmp.x + dx[i], tmp.y + dy[i])){
                if(g[tmp.x + dx[i]][tmp.y + dy[i]]){
                    int a = find(tmp.group), b = find(g[tmp.x + dx[i]][tmp.y + dy[i]]);
                    merge(a, b);
                    ans = min(ans, d[a]);
                    if(ans + k == 0){
                        cout << max(lv[tmp.x + dx[i]][tmp.y + dy[i]], lv[tmp.x][tmp.y]);
                        return 0;
                    }
                }else{
                    g[tmp.x + dx[i]][tmp.y + dy[i]] = find(tmp.group);
                    q.push(v(tmp.x + dx[i], tmp.y + dy[i], find(tmp.group), tmp.level + 1));
                    lv[tmp.x + dx[i]][tmp.y + dy[i]] = tmp.level + 1;
                }
            }
        }
    }
}