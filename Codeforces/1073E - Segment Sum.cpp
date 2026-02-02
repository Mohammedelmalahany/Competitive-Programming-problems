#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 998244353;
#define el '\n'

string l, r;
int k;
int sumdp[20][1 << 11][2][2][2];
int dp[20][1 << 11][2][2][2];
int n;
ll p10[20];

int nums(int i, int mask, int resl, int resr, int st) {
    if (i == n) {
        return (__builtin_popcount(mask) <= k);
    }
    int& ret = dp[i][mask][resl][resr][st];
    if (~ret) return ret;
    ret = 0;
    int lb = resl ? l[i] - '0' : 0;
    int up = resr ? r[i] - '0' : 9;
    for (int it = lb; it <= up; it++) {
        if (!st && it == 0) {
            ret = (ret + nums(i + 1, mask, (resl && (it == lb)), resr && (it == up), st)) % MOD;
        }
        else {
            ret = (ret + nums(i + 1, mask | (1 << it),
                resl && it == lb,
                resr && it == up,
                1)) % MOD;
        }
    }
    return ret;
}

int segsum(int i = 0, int mask = 0, int resl = 1, int resr = 1, int st = 0) {
    if (i == n) return 0;

    int& ret = sumdp[i][mask][resl][resr][st];
    if (~ret) return ret;
    ret = 0;

    int lb = resl ? l[i] - '0' : 0;
    int up = resr ? r[i] - '0' : 9;

    for (int it = lb; it <= up; it++) {
        if (!st && it == 0) {
            ret = (ret + segsum(
                i + 1, mask,
                resl && it == lb,
                resr && it == up,
                0
            )) % MOD;
        }
        else {
            ll t1 = (ll)it * p10[n - i - 1] % MOD;
            ll count = nums(i + 1, mask | (1 << it),
                resl && it == lb,
                resr && it == up,
                1);

            ret = (ret + t1 * count) % MOD;

            ret = (ret + segsum(
                i + 1, mask | (1 << it),
                resl && it == lb,
                resr && it == up,
                1
            )) % MOD;
        }
    }
    return ret;
}

void solve() {
    p10[0] = 1;
    for (int i = 1; i < 20; i++)
        p10[i] = (p10[i - 1] * 10) % MOD;

    cin >> l >> r >> k;
    n = (int)r.size();
    reverse(l.begin(), l.end());
    while (l.size() < n) {
        l += '0';
    }
    reverse(l.begin(), l.end());

    memset(dp, -1, sizeof(dp));
    memset(sumdp, -1, sizeof(sumdp));

    cout << segsum() << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}