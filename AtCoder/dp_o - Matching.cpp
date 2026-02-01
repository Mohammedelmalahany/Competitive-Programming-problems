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
bool match[21][21];
int dp[22][1 << 21];
int add(int& x, int y) {
    return x = (x + y) % MOD;
}
int msk(int i = 0, int mask = 0) {
    if (i == n)return 1;
    int& ret = dp[i][mask];
    if (~ret)return ret;
    ret = 0;
    for (int j = 0; j < n; j++) {
        if (!((mask >> j) & 1) && match[i][j]) {
            add(ret, msk(i + 1, mask | (1 << j)));
        }
    }
    return ret % MOD;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cin >> match[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << msk();
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
//