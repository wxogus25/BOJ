// 2022-03-02 23:12:14
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

typedef pair<long long, long long> pii;
pii segtree[524288];
int siz;
const int mod = 1000000007;

void update(int index, int num){
    index += siz;
    segtree[index].first += num;
    segtree[index].second++;
    while(index > 1){
        index /= 2;
        segtree[index].first = segtree[index*2].first + segtree[index*2+1].first;
        segtree[index].second = segtree[index*2].second + segtree[index*2+1].second;
    }
}

void init(){
}

pii sum(int fl, int fr, int nl, int nr, int index){
    if(fl > nr || fr < nl) return pii(0, 0);
    if(fl <= nl && nr <= fr) return segtree[index];
    int mid = (nl + nr) / 2;
    pii a = sum(fl, fr, nl, mid, index*2), b = sum(fl, fr, mid + 1, nr, index*2+1);
    return pii(a.first + b.first, a.second + b.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long ans = 1, tmp;
    int n; 
    cin >> n;
    cin >> tmp;
    siz = 524288 / 2;
    init();
    update(tmp, tmp);
    for(int i=2;i<=n;i++){
        cin >> tmp;
        update(tmp, tmp);
        pii a = sum(0, tmp - 1, 0, siz - 1, 1), b = sum(tmp + 1, siz - 1, 0, siz - 1, 1);
        ans *= ((a.second * tmp - a.first) + (b.first - b.second * tmp)) % mod;
        ans %= mod;
    }
    cout << ans;
}