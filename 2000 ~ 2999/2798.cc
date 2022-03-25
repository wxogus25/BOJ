// 2022-02-13 10:05:13
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>

using namespace std;

int d[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, maxx=0;
    cin >> n >> m;
    for(int i=0; i<n;i++){
        cin >> d[i];
    }

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(d[i]+d[j]+d[k] <= m){
                    maxx = max(d[i]+d[j]+d[k], maxx);
                }
            }
        }
    }
    cout << maxx;
}