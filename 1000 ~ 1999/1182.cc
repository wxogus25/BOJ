// 2022-02-15 22:45:22
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>

using namespace std;

int n, s, dap;
int d[21];

void func(int level, int now){
    if(level == n){
        if(now == s) dap++;
        return;
    }
    func(level+1, now+d[level]);
    func(level+1, now);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> d[i];
    }
    func(0,0);
    cout << ((s==0)?(dap-1):(dap));
}
