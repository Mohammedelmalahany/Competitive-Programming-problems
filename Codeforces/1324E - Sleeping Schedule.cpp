#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
int v[2001];
int n, h, l, r;
int dp[2001][2001];
int fun(int i, int st) {
    if (i == n)return 0;
    int& ret = dp[i][st];
    if (~ret)return ret;
    int c1 = (st + v[i]) % h, c2 = ((st + v[i] - 1) % h);
    return ret = max(fun(i + 1, c1) + (c1 >= l && c1 <= r ? 1 : 0), fun(i + 1, c2) + (c2 >= l && c2 <= r ? 1 : 0));
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h >> l >> r;
    for (int i = 0; i < n; i++)cin >> v[i];
    memset(dp, -1, sizeof dp);
    cout << fun(0, 0);
    return 0;
}
//
