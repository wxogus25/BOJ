// 2022-03-10 17:02:43
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m, s, t;
const long long inf = 1e19;
vector<pii> edge[50];
long long dis[50];
long long don[50];
bool con[50][50];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> t >> m;
    int a, b, c;
    
    while(m--){
        cin >> a >> b >> c;
        edge[a].push_back(pii(b, c));
        con[a][b] = true;
    }
    for(int i=0;i<n;i++) cin >> don[i];

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(con[i][k] && con[k][j])
                    con[i][j] = true;
            }
        }
    }

    fill(dis, dis+n, inf);
    dis[s] = -don[s];
    bool check = false, reach = false;
    for(int k=0;k<=n;k++){
        for(int i=0;i<n;i++){
            if(dis[i] != inf){
                for(pii x : edge[i]){
                    if(dis[i] + x.second - don[x.first] < dis[x.first]){
                        dis[x.first] = dis[i] + x.second - don[x.first];
                        if(k >= n-1) {
                            check = true;
                            if(con[x.first][t]) reach = true;
                        }
                    }
                }
            }
        }
    }
    if(dis[t] == inf) cout << "gg";
    else if(check && reach) cout << "Gee";
    else{
        cout << -dis[t];
    }
}