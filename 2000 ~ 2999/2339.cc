// 2022-02-16 22:34:18
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>

using namespace std;

int n, d[21][21];
int is_vertical;

int func(int sx, int sy, int ex, int ey){
    int gar = 0, jew = 0;
    queue<pair<int, int> > q;
    for(int i=sx;i<ex;i++){
        for(int j=sy;j<ey;j++){
            if(d[i][j] == 1){
                gar++;
                q.push(make_pair(i, j));
            }else if(d[i][j] == 2){
                jew++;
            }
        }
    }
    if(jew == 0){
        return 0;
    }else{
        if(jew == 1){
            if(gar == 0){
                return 1;
            }else{
                return 0;
            }
        }else if(gar == 0){
            return 0;
        }
    }
    bool ck[21], check;
    fill(ck,ck+21,0);
    int pos = 0;
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop(); check=false;
        if(is_vertical){
            if(ck[y]){
                continue;
            }
            ck[y] = true;
            for(int i=sx;i<ex;i++){
                if(d[i][y] == 2){
                    check=true;
                    break;
                }
            }
            if(check){
                continue;
            }
            is_vertical^=1;
            int c1 = func(sx, sy, ex, y), c2 = func(sx, y+1, ex, ey);
            pos += c1 * c2;
            is_vertical^=1;
        }else{
            if(ck[x]){
                continue;
            }
            ck[x] = true;
            for(int i=sy;i<ey;i++){
                if(d[x][i] == 2){
                    check=true;
                    break;
                }
            }
            if(check){
                continue;
            }
            is_vertical^=1;
            int c1 = func(sx, sy, x, ey), c2 = func(x+1, sy, ex, ey);
            pos += c1 * c2;
            is_vertical^=1;
        }
    }
    return pos;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> d[i][j];
        }
    }
    int s = func(0,0,n,n);
    is_vertical = 1;
    s += func(0,0,n,n);
    if(s == 0){
        cout << -1;
    }else{
        cout << s;
    }
}