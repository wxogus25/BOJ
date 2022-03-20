// 2022-02-26 19:33:43
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

int d[30];

int power(int x){
    int tmp = 1;
    while(x--){
        tmp *= 10;
    }
    return tmp;
}

bool cmp(const int &i, const int &j){
    return i > j;
}

int main(){
    string x;
    int n, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        int ck = x.size();
        for(int j=0;j<ck;j++){
            d[x[j]-'A'] += power(ck-j-1);
        }
    }
    sort(d,d+30,cmp);
    int num = 9;
    for(int i=0;i<30;i++){
        if(d[i] == 0) break;
        ans += d[i] * (num--);
    }
    cout << ans;
}