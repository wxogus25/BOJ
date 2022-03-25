// 2022-02-14 23:57:28
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>

using namespace std;

int d[10], q[10];
void func(int level, int sum, int now){
    if(sum > 100) return;
    if(level == 7){
        if(sum == 100){
            for(int i=0;i<7;i++){
                cout << q[i] << endl;
            }
            exit(NULL);
        }
        return;
    }

    for(int i=now;i<9-6+level;i++){
        q[level] = d[i];
        func(level+1, sum+d[i], i+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<9;i++){
        cin >> d[i];
    }
    sort(d,d+9);
    func(0,0,0);
}