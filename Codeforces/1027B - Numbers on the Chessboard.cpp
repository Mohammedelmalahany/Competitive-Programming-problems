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
void solve() {
	ll n; int q; cin >> n >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		ll ans = 0;
		if ((a + b) & 1) {
			ans = ((n * n + 1) >> 1) + (((a - 1) * n) >> 1) + (b + 1 >> 1);
		}
		else {
			ans = (((a - 1) * n) + 1 >> 1) + (b + 1 >> 1);
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






