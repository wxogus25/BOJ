// 2022-03-22 23:45:00
#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int d[31][8];
int main() {
    int n;
    cin >> n;
    d[1][0] = d[1][3] = d[1][6] = 1;
    for (int i = 2; i <= n; i++) {
        d[i][7] = d[i - 1][6] + d[i - 1][3] + d[i - 1][0];
        d[i][6] = d[i - 1][7] + d[i - 1][1];
        d[i][5] = d[i - 1][2];
        d[i][4] = d[i - 1][3];
        d[i][3] = d[i - 1][7] + d[i - 1][4];
        d[i][2] = d[i - 1][5];
        d[i][1] = d[i - 1][6];
        d[i][0] = d[i - 1][7];
    }
    cout << d[n][7];
}