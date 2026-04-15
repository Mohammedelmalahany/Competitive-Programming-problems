#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7, N = 1e5 + 3;
const int inv = 500000004;
int n;
int k, d;
int dp[N][2];
int v[N], h[N];
int func(int i, int b) {
    if (i == n)return b;
    if (i > n)return 0;
    int& ret = dp[i][b];
    if (~ret)return ret;
    ret = 0;
    for (int j = 1; j <= k; j++) {
        ret += func(i + j, (j >= d) | b);
        ret %= MOD;
    }
    return ret;
}
signed main() {

    int t = 1; //cin >> t;
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;
    cout << func(0, 0) % MOD;
    return 0;
}
//