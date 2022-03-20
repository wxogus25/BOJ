// 2022-02-25 22:47:47
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

bool check[31][31];
int n, dx[4]={0,0,-1,1}, dy[4]={1,-1,0,0};
double d[4];

double ans(int level, int ver, int hor){
    if(check[ver][hor]){
        return 0;
    }
    if(level == n){
        return 1;
    }
    check[ver][hor] = true;
    double tmp = 0;
    for(int i=0;i<4;i++){
        tmp += ans(level+1, ver+dx[i], hor+dy[i]) * d[i]/100.0;
    }
    check[ver][hor] = false;
    return tmp;
}

int main(){
    cin >> n;
    for(int i=0;i<4;i++){
        cin >> d[i];
    }
    cout << fixed;
    cout.precision(10);
    cout << ans(0, 15, 15);
}