// 2022-03-09 14:46:19
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long, int> plli;
typedef pair<int, int> pii;
int n, m, f, s, t;
bool check[100000];
vector<pair<int, int> > vec[100000];
long long dis[2][50000];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> f >> s >> t;
    int a, b, c;
    while(m--){
        cin >> a >> b >> c;
        vec[a].push_back(pii(b, c));
        vec[b].push_back(pii(a, c));
        vec[a+n].push_back(pii(b+n, c));
        vec[b+n].push_back(pii(a+n, c));
    }
    while(f--){
        cin >> a >> b;
        vec[a].push_back(pii(b+n, 0));
    }
    priority_queue<plli, vector<plli>, greater<plli> > q;
    memset(dis, -1, sizeof(dis));
    dis[0][s] = 0;
    q.push(plli(0, s));
    while(!q.empty()){
        plli tmp = q.top(); q.pop();
        if(check[tmp.second]) continue;
        check[tmp.second] = true;
        for(pii v : vec[tmp.second]){
            if(dis[v.first / n][v.first % n] == -1 || dis[v.first / n][v.first % n] > dis[tmp.second / n][tmp.second % n] + (ll)v.second){
                dis[v.first / n][v.first % n] = dis[tmp.second / n][tmp.second % n] + (ll)v.second;
                q.push(plli(dis[v.first / n][v.first % n], v.first));
            }
        }
    }
    if(dis[0][t] == -1 || dis[1][t] == -1){
        cout << max(dis[0][t], dis[1][t]);
    }else{
        cout << min(dis[0][t], dis[1][t]);
    }
}