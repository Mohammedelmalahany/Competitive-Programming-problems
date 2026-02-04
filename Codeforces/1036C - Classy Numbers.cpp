#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 1000000007;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int dp[20][4][2][2];
int n;
string l, r;
int rec(int i = 0, int nz = 0, bool resl = 1, bool resr = 1) {
    if (i == n)return nz <= 3;
    if (nz > 3)return 0;
    int& ret = dp[i][nz][resl][resr];
    if (~ret)return ret;
    ret = 0;
    int lb = resl ? l[i] - '0' : 0;
    int ub = resr ? r[i] - '0' : 9;
    for (int d = lb; d <= ub; d++) {
        ret += rec(i + 1, nz + (d != 0), resl && (d == lb), resr && (d == ub));
    }
    return ret;
}

void solve() {
    cin >> l >> r;
    n = r.size();
    while (l.size() < n) {
        l = '0' + l;
    }
    memset(dp, -1, sizeof dp);
    cout << rec() << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

//