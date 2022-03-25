// 2022-03-21 15:02:10
#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

queue<int> q[110];
int d[110];
set<int> x;

int main() {
    FASTIO
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> d[i];
        q[d[i]].push(i);
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        q[d[i]].pop();
        if (x.find(d[i]) == x.end()) {
            if (x.size() == n) {
                int maxx = 0;
                int index = 0;
                for (auto iter = x.begin(); iter != x.end(); iter++) {
                    if (q[*iter].empty() || q[*iter].front() > maxx) {
                        maxx = (q[*iter].empty() ? 110 : q[*iter].front());
                        index = *iter;
                    }
                }
                x.erase(index);
                x.insert(d[i]);
                cnt++;
            } else {
                x.insert(d[i]);
            }
        }
    }
    cout << cnt;
}