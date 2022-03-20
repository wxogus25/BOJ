// 2022-03-04 17:57:05
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
vector<pii> d;
int n;

void input(){
    cin >> n;
    for(int i=0,x,y;i<n;i++){
        cin >> x >> y;
        d.push_back(pii(x, y));
    }
}

long long answer(){
    sort(d.begin(), d.end());
    long long ans = 0, l = -1000000001, r;
    for(auto i : d){
        if(l == -1000000001){
            l = i.first;
            r = i.second;
        }else{
            if(i.first > r){
                ans += r - l;
                l = i.first;
                r = i.second;
            }else{
                r = max(i.second, r);
            }
        }
    }
    ans += r - l;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << answer();
}