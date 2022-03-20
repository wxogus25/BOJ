// 2022-02-14 23:47:38
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

    int n, m, sum = 0, maxx = -1001;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        sum += m;
        maxx = max(maxx, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    cout << maxx;
}