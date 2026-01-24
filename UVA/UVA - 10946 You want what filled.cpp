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
vector<vector<char>> mat(50, vector<char>(50));
vector<vector<bool>> vis(50, vector<bool>(50));
int r[4] = { 0, 0, 1, -1 };
int c[4] = { 1, -1, 0, 0 };
int n, m;
vector < pair<int, char>> a;
bool com(pair<int, char>& a, pair<int, char>& b) {
	if (a.first != b.first) {
		return a.first > b.first;
	}
	return a.second < b.second;
}
bool valid(int i, int j) {
	return (i >= 0 && i < n) && (j >= 0 && j < m);
}

int dfs(int i, int j, char p) {
	if (mat[i][j] != p)return 0;
	int ret = 1;
	vis[i][j] = 1;
	for (int l = 0; l < 4; l++) {
		if (valid(i + r[l], j + c[l])) {
			if (!vis[i + r[l]][j + c[l]])ret += dfs(i + r[l], j + c[l], p);
		}
	}
	return ret;
}

void solve() {
	int t = 1;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)break;
		a.clear();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				vis[i][j] = false;

		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> mat[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == '.')continue;
				if (!vis[i][j]) {
					char s = mat[i][j];
					int f = dfs(i, j, s);
					a.push_back({ f, s });
				}
			}
		sort(a.begin(), a.end(), com);
		cout << "Problem " << t << ":\n";
		for (int i = 0; i < a.size(); i++)
			cout << a[i].second << ' ' << a[i].first << el;
		t++;
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






