// 2022-02-18 01:48:11
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>

using namespace std;

int n, k;
long long d;
struct data{
    int a,b,c;
}rule[10010];

long long func(int num){
    long long dotori = 0;
    for(int i=1;i<=k;i++){
        if(rule[i].a > num) continue;
        dotori += (long long)((min(rule[i].b, num) - rule[i].a)/rule[i].c + 1);
    }
    return dotori;
}

int main(){
    cin >> n >> k >> d;
    for(int i=1;i<=k;i++){
        cin >> rule[i].a >> rule[i].b >> rule[i].c;
    }
    int lo = 0, hi = n+1;
    while(lo+1 < hi){
        int mid = (lo + hi) / 2;
        if(func(mid) >= d){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << hi;
}