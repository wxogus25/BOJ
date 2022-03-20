// 2022-02-18 02:03:19
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>

using namespace std;

long long n, k;

bool func(long long num){
    long long cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += min(n, num/i);
    }
    if(cnt >= k) return true;
    else return false;
}

int main(){
    cin >> n >> k;
    long long lo = 0, hi = n*n;
    while(lo + 1 < hi){
        long long mid = (lo + hi) / 2;
        if(func(mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << hi;
}