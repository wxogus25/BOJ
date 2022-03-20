// 2022-03-13 12:22:45
#include <bits/stdc++.h>
#define FASTIO                   \
	ios::sync_with_stdio(false); \
	cin.tie(0);

using namespace std;

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
		seg.resize(size * 2, 0);
	}

	void update(int idx, int change)
	{
		idx += size;
		seg[idx] = change;
		while (idx)
		{
			idx /= 2;
			seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
		}
	}

	int query(int l, int r)
	{
		l += size;
		r += size;
		int res = 0;
		while (l <= r)
		{
			if (r % 2 == 0)
			{
				res += seg[r--];
			}
			if (l % 2 == 1)
			{
				res += seg[l++];
			}
			r /= 2;
			l /= 2;
		}
		return res;
	}
} segTree;

int d[100010];

int main()
{
	FASTIO
	int t, n, m, c;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int size = n + m;
		segTree seg(size);
		for (int i = 1; i <= n; i++)
		{
			d[i] = n - i;
			seg.update(i - 1, 1);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> c;
			seg.update(d[c], 0);
			cout << seg.query(d[c], size) << " ";
			d[c] = n + i;
			seg.update(d[c], 1);
		}
		cout << '\n';
	}
}