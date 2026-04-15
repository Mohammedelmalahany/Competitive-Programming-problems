#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
string s, t;
int n, m;
int dp[1001][1001];
char grid[1001][1001];
int fun(int i, int j) {
    if (i >= n || j >= m || grid[i][j] == '#')return 0;
    if (i == n - 1 && j == m - 1)return 1;
    int& ret = dp[i][j];
    if (~ret)return ret;
    return ret = fun(i + 1, j) % MOD + fun(i, j + 1) % MOD;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)cin >> grid[i][j];
    memset(dp, -1, sizeof dp);
    cout << fun(0, 0) % MOD;
    return 0;
}
