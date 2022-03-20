// 2022-03-10 09:46:44
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m;
const long long inf = 1e19;
vector<pii> edge[501];
long long dis[501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int a, b, c;
    
    while(m--){
        cin >> a >> b >> c;
        edge[a].push_back(pii(b, c));
    }

    fill(dis, dis+n+1, inf);
    dis[1] = 0;
    bool check = false;
    for(int k=0;k<n;k++){
        for(int i=1;i<=n;i++){
            if(dis[i] != inf){
                for(pii x : edge[i]){
                    if(dis[i] + x.second < dis[x.first]){
                        dis[x.first] = dis[i] + x.second;
                        if(k == n-1) check = true;
                    }
                }
            }
        }
    }

    if(check) cout << -1;
    else{
        for(int i=2;i<=n;i++){
            if(dis[i] == inf) cout << -1 << '\n';
            else cout << dis[i] << '\n';
        }
    }
}