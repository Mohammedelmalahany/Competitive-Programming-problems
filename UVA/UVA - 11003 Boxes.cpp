#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'


//struct SegmantTree {
//private:
//	vector<int> seg; int n;
//
//	int skip = INF;
//	void build(vector<int>& arr, int node, int l, int r) {
//		if (l == r) {
//			seg[node] = arr[l];
//			return;
//		}
//		int mid = l + r >> 1;
//		build(arr, 2 * node, l, mid);
//		build(arr, 2 * node + 1, mid + 1, r);
//		seg[node] = min(seg[2 * node], seg[2 * node + 1]);
//	}
//	void update(int l, int r, int node, int ind, int val) {
//		if (l == r) {
//			seg[node] = val;
//			return;
//		}
//		int mid = l + r >> 1;
//		if (ind <= mid) {
//			update(l, mid, 2 * node, ind, val);
//		}
//		else {
//			update(mid + 1, r, 2 * node + 1, ind, val);
//		}
//		seg[node] = seg[2 * node] + seg[2 * node + 1];
//	}
//	int query(int L, int R, int l, int r, int node) {
//		if (l >= L && r <= R) {
//			return seg[node];
//		}
//		if (L > r || R < l)return skip;
//		int mid = r + l >> 1;
//		return min(query(L, R, l, mid, 2 * node), query(L, R, mid + 1, r, 2 * node + 1));
//	}
//public:
//	SegmantTree(vector<int>& arr) {
//		this->n =arr.size();
//		seg.assign(4 * arr.size(), 0);
//		build(arr, 1, 0, n - 1);
//	}
//	void update(int ind, int  val) {
//		update(0, n - 1, 1, ind, val);
//	}
//	int query(int l, int  r) {
//		return query(l, r, 0, n - 1, 1);
//	}
//};

int wt[1001];
int ld[1001];
int n;
int dp[1001][3001];
//return the best of each box
int rec(int i, int rem) {
	if (i == n)return 0;
	int& ret = dp[i][rem];
	if (~ret)return ret;
	ret = max(ret, rec(i + 1, rem));
	if (wt[i] <= rem) {
		ret = max(ret, 1 + rec(i + 1, min(rem - wt[i], ld[i])));
	}
	return ret;
}
void solve() {
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> wt[i] >> ld[i];
		}
		memset(dp, -1, sizeof(dp));
		//get the best of choose each box to be the first box
		int ans = -INF;
		for (int i = 0; i < n; i++) {
			ans = max(ans, 1 + rec(i + 1, ld[i]));

		}
		cout << ans << el;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
//






