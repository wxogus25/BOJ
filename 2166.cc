// 2022-03-06 22:53:33
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL cross(LL x1, LL y1, LL x2, LL y2){
    return x1*y2 - x2*y1;
}

double func(){
    int n;
    cin >> n;
    LL ans = 0;
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i=3; i<=n; i++){
        cin >> x3 >> y3;
        ans += cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
        x2 = x3;
        y2 = y3;
    }
    return (double)abs(ans) / 2.0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cout << fixed;
    cout.precision(1);
    cout << func();
}