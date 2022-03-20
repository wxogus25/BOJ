// 2022-03-13 14:20:59
#include <bits/stdc++.h>
#define FASTIO                   \
	ios::sync_with_stdio(false); \
	cin.tie(0);

using namespace std;

typedef pair<int, int> pii;
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
		seg.resize(size * 2, 0);
	}

	void update(int idx, int change)
	{
		idx += size;
		seg[idx] += change;
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

int main()
{
	FASTIO
	int t, n, m, q, a, b;
	cin >> n;
	segTree seg(1000001);
	while (n--)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> a;
			int l = 0, r = 1000000, mid;
			while (l + 1 < r)
			{
				mid = (l + r) / 2;
				if (seg.query(1, mid) < a)
				{
					l = mid;
				}
				else
				{
					r = mid;
				}
			}
			cout << r << '\n';
			seg.update(r, -1);
		}
		else
		{
			cin >> a >> b;
			seg.update(a, b);
		}
	}
}