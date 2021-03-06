// 2022-03-12 22:45:59
#include <bits/stdc++.h>

using namespace std;

long long trsize[300010], edcnt[300010], ans;
int n;
vector<int> edge[300010];

void func(int now, int parent, long long level)
{
	if (trsize[now])
		return;
	int len = edge[now].size();
	for (int i = 0; i < len; i++)
	{
		if (edge[now][i] == parent)
			continue;
		func(edge[now][i], now, level + 1);
		trsize[now] += trsize[edge[now][i]];
		edcnt[now] += edcnt[edge[now][i]] + trsize[edge[now][i]];
		ans += edcnt[edge[now][i]] + trsize[edge[now][i]] + trsize[edge[now][i]] * level;
	}
	long long ck = trsize[now];
	for (int i = 0; i < len; i++)
	{
		if (edge[now][i] == parent)
			continue;
		ans += (trsize[edge[now][i]] + edcnt[edge[now][i]]) * (trsize[now] - trsize[edge[now][i]]) + (ck - trsize[edge[now][i]]) * trsize[edge[now][i]] * level;
		ck -= trsize[edge[now][i]];
	}
	trsize[now]++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	func(1, 0, 0);
	cout << ans;
}