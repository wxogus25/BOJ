// 2022-02-24 18:35:53
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

int findl(int now){
    int level = 0;
    while(now % 10){
        now /= 10;
        level++;
    }
    return level;
}
int swapab(int now, int a, int b){
    int d[9]={0,};
    for(int i=0;i<9;i++){
        d[i] = now%10;
        now /= 10;
    }
    swap(d[a], d[b]);
    now = d[8];
    for(int i=7;i>=0;i--){
        now *= 10;
        now += d[i];
    }
    return now;
}
int L(int now){
    int level = findl(now);
    if(level%3 == 2) return 0;
    return swapab(now, level, level+1);
}
int R(int now){
    int level = findl(now);
    if(level%3 == 0) return 0;
    return swapab(now, level, level-1);
}
int U(int now){
    int level = findl(now);
    if(level > 5) return 0;
    return swapab(now, level, level+3);
}
int D(int now){
    int level = findl(now);
    if(level < 3) return 0;
    return swapab(now, level, level-3);
}

map<int, int> m;
int (*fp[4])(int) = {L,R,U,D};

int main(){
    int a = 0, b = 123456780, c;
    for(int i=0;i<9;i++){
        cin >> c;
        a *= 10;
        a += c;
    }
    if(a == b){
        cout << 0;
        return 0;
    }
    m[a] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(a, 0));
    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ck = fp[i](p.first);
            if(ck == 0 || m[ck] == 1) continue;
            if(ck == b){
                cout << p.second + 1 << endl;
                return 0;
            }
            m[ck] = 1;
            q.push(make_pair(ck, p.second + 1));
        }
    }
    cout << -1;
}