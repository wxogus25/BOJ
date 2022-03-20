// 2022-02-17 23:42:30
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>

using namespace std;

struct room{
    int type;
    unsigned long long atk, hp;
} d[130000];
long long atk;
int n;

bool func(unsigned long long max_hp){
    unsigned long long now_hp = max_hp, now_atk = atk, hero_atkcnt, mob_atkcnt;
    for(int i=0;i<n;i++){
        if(d[i].type == 1){
            hero_atkcnt = (d[i].hp + now_atk - 1LL)/now_atk;
            mob_atkcnt = (now_hp + d[i].atk - 1LL)/d[i].atk;
            if(hero_atkcnt <= mob_atkcnt){
                now_hp -= (hero_atkcnt-1LL)*d[i].atk;
            }else{
                return false;
            }
        }else{
            now_hp = min(now_hp + d[i].hp, max_hp);
            now_atk += d[i].atk;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> atk;

    for(int i=0;i<n;i++){
        cin >> d[i].type >> d[i].atk >> d[i].hp;
    }
    unsigned long long lo = 0, hi=9223372036854775807LL;
    while(lo+1 < hi){
        long long mid = (lo + hi)/2;
        if(func(mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << hi;
}