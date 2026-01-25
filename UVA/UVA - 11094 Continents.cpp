#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

vector<vector<char>> mat(21, vector<char>(21));
vector<vector<bool>> vis(21, vector<bool>(21));
int r[4] = { 0, 0, 1, -1 };
int c[4] = { 1, -1, 0, 0 };
int m, n;
bool valid(int i, int j) {
	return (i >= 0 && i < m) && (j >= 0 && j < n);
}
int dfs(int i, int j, char p) {
	// horizontal wrapping only
	if (j < 0)j = n - 1;
	if (j == n) j = 0;
	if (!valid(i, j) || vis[i][j])return 0;
	if (mat[i][j] != p)return 0;
	int ret = 1;
	vis[i][j] = 1;
	for (int l = 0; l < 4; l++) {
		ret += dfs(i + r[l], j + c[l], p);
	}
	return ret;
}

void solve() {
	while (cin >> m >> n) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				vis[i][j] = false;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];
		int x, y; cin >> x >> y;
		int ret = dfs(x, y, mat[x][y]);
		int ans = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!vis[i][j] && mat[i][j] == mat[x][y]) {
					ans = max(ans, dfs(i, j, mat[x][y]));
				}
			}
		}
		//without el WA
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






