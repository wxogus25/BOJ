// 2022-02-15 00:06:10
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int s = i, a = i;
        while(a){
            s += a%10;
            a/=10;
        }
        if(s == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
}