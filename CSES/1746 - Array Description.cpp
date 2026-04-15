#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7, N = 1e5 + 3;
const int inv = 500000004;
int n, m;
int dp[N][101];
vector<int>v;
int func(int i, int ls) {
    if (i == n)return 1;
    if (v[i] != 0) {
        if (abs(v[i] - ls) > 1)return 0;
    }
    int& ret = dp[i][ls];
    if (~ret)return ret;
    if (v[i])return ret = func(i + 1, v[i]);
    ret = 0;
    ret += func(i + 1, ls);
    if (1ll <= ls - 1)ret += func(i + 1, ls - 1);
    if (m >= ls + 1)ret += func(i + 1, ls + 1);
    return ret %= MOD;
}

signed main() {

    int t = 1; //cin >> t;
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < n; i++)cin >> v[i];
    int ans = 0;
    if (v[0])cout << func(1, v[0]);
    else {
        for (int i = 1; i <= m; i++)ans += func(1, i);
        cout << ans % MOD;
    }
    return 0;
}
//
