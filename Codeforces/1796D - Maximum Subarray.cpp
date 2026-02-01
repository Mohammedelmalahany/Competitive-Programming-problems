#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define ll long long
#define int long long

const int INF = INT32_MAX;
const ll MOD = 1e9 + 7;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int n;
const int N = 2e5 + 5;
int v[2 * 100001];
int x;
int k;
int dp[N][21][4];
void add(int& x, int y) {
    x = (x + y) % MOD;
}
int mxsbarr(int i = 0, int rem = k, int state = 0) {
    if (i == n) {
        if (rem == 0)
            return 0;
        return -1e18;
    }
    int& ret = dp[i][rem][state];
    if (ret != -1)return ret;
    ret = -1e18;
    if (state == 0) {
        ret = max(ret, mxsbarr(i + 1, rem, 0));
        ret = max(ret, mxsbarr(i, rem, 1));
        if (rem > 0)ret = max(ret, mxsbarr(i + 1, rem - 1, 0));
    }
    else if (state == 1) {
        ret = max(ret, mxsbarr(i + 1, rem, 1) + v[i] - x);
        ret = max(ret, mxsbarr(i, rem, 2));
        if (rem > 0)
            ret = max(ret, mxsbarr(i + 1, rem - 1, 1) + v[i] + x);
    }
    else {
        ret = max(ret, mxsbarr(i + 1, rem, 2));
        if (rem > 0)ret = max(ret, mxsbarr(i + 1, rem - 1, 2));
    }
    return ret;
}

void solve() {
    cin >> n >> k >> x;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= 20; j++)
            for (int s = 0; s < 3; s++)
                dp[i][j][s] = -1;

    cout << mxsbarr() << el;
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

