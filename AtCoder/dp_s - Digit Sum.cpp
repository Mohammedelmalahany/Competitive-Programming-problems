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
string l = "1", r;
int d;
const int N = 1e5 + 5;
int dp[N][103][2][2];
void add(int& x, int y) {
    x = (x + y) % MOD;
}
int digitsum(int i = 0, int modsum = 0, bool resr = 1, bool resl = 1) {
    if (i == n) {
        return ((modsum % d) == 0);
    }
    int& ret = dp[i][modsum][resr][resl];
    if (~ret)return ret;
    ret = 0;
    int lp = resl ? l[i] - '0' : 0;
    int up = resr ? r[i] - '0' : 9;
    for (int j = lp; j <= up; j++) {
        add(ret, digitsum(i + 1, (modsum + j) % d, resr && (j == up), resl && (j == lp)));
    }
    return ret;
}

void solve() {
    cin >> r;
    cin >> d;
    n = r.size();
    memset(dp, -1, sizeof(dp));
    l = string(n - 1, '0');
    l += "1";
    cout << digitsum();
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