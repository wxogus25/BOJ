// 2022-03-11 16:30:15
#include <bits/stdc++.h>

using namespace std;

int d[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(d[a][b] != 0)
            d[a][b] = min(d[a][b], c);
        else
            d[a][b] = c;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j) continue;
                if(d[i][k] && d[k][j])
                    if(d[i][j] != 0)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    else
                        d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}