// 2022-03-14 20:45:02
#include <bits/stdc++.h>
#define FASTIO                   \
	ios::sync_with_stdio(false); \
	cin.tie(0);

using namespace std;

int a[500010], b[500010];
const int INF = 1000000;
typedef struct segTree
{
	vector<int> seg;
	int size;

	segTree(int N)
	{
		size = 1;
		while (size < N)
		{
			size *= 2;
		}
		seg.resize(size * 2, INF);
	}

	void update(int idx, int change)
	{
		idx += size;
		seg[idx] = change;
		while (idx)
		{
			idx /= 2;
			seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
		}
	}

	int query(int l, int r)
	{
		l += size;
		r += size;
		int res = INF;
		while (l <= r)
		{
			if (r % 2 == 0)
			{
				res = min(res, seg[r--]);
			}
			if (l % 2 == 1)
			{
				res = min(res, seg[l++]);
			}
			r /= 2;
			l /= 2;
		}
		return res;
	}
} segTree;

int main()
{
	FASTIO
	int n;
	cin >> n;
	segTree seg(500001);
	for (int i = 1, x; i <= n; i++)
	{
		cin >> x;
		a[x] = i;
	}
	for (int i = 1, x; i <= n; i++)
	{
		cin >> x;
		b[a[x]] = i;
	}
	int ans = 0;
	for (int i = 1, x; i <= n; i++)
	{
		cin >> x;
		if (seg.query(1, a[x]) > b[a[x]])
		{
			ans++;
		}
		seg.update(a[x], b[a[x]]);
	}
	cout << ans;
}