// 2022-03-06 22:32:41
#include <bits/stdc++.h>

using namespace std;

int cross(int x1, int y1, int x2, int y2){
    return x1*y2 - x2*y1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int x1, x2, x3, y1, y2, y3, t;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    t = cross(x2 - x1, y2 - y1, x3 - x2, y3 - y2);
    if(t < 0){
        cout << -1;
    }else if(t > 0){
        cout << 1;
    }else{
        cout << 0;
    }
}