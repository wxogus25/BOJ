// 2022-03-13 12:46:15
#include <bits/stdc++.h>
#define FASTIO                   \
	ios::sync_with_stdio(false); \
	cin.tie(0);

using namespace std;

typedef pair<int, int> pii;
const int INF = 1000000;
typedef struct segTree
{
	vector<pii> seg;
	int size;

	segTree(int N)
	{
		size = 1;
		while (size < N)
		{
			size *= 2;
		}
		seg.resize(size * 2, pii(INF, -1));
	}

	void update(int idx, int change)
	{
		idx += size;
		seg[idx].first = seg[idx].second = change;
		while (idx)
		{
			idx /= 2;
			seg[idx].first = min(seg[idx * 2].first, seg[idx * 2 + 1].first);
			seg[idx].second = max(seg[idx * 2].second, seg[idx * 2 + 1].second);
		}
	}

	pii query(int l, int r)
	{
		l += size;
		r += size;
		pii res = pii(INF, -1);
		while (l <= r)
		{
			if (r % 2 == 0)
			{
				res.first = min(res.first, seg[r].first);
				res.second = max(res.second, seg[r--].second);
			}
			if (l % 2 == 1)
			{
				res.first = min(res.first, seg[l].first);
				res.second = max(res.second, seg[l++].second);
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
	int t, n, m, q, a, b;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int size = n;
		segTree seg(size);
		for (int i = 0; i < n; i++)
		{
			d[i] = i;
			seg.update(i, i);
		}
		while (m--)
		{
			cin >> q >> a >> b;
			if (q)
			{
				pii tmp = seg.query(a, b);
				if (tmp.first != a || tmp.second != b)
				{
					cout << "NO\n";
				}
				else
				{
					cout << "YES\n";
				}
			}
			else
			{
				swap(d[a], d[b]);
				seg.update(d[a], a);
				seg.update(d[b], b);
			}
		}
	}
}