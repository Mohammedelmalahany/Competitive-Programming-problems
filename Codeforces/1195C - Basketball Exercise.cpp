#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'


ll dp[100003][2];
vector<int> a;
vector<int > b;
int n;
ll rec(int i, bool st) {
    if (i >= n)return 0;
    ll& ret = dp[i][st];
    if (~ret)return ret;
    ret = max(ret, rec(i + 1, st));
    if (st) {
        ret = max(ret, a[i] + rec(i + 1, !st));
    }
    else {
        ret = max(ret, b[i] + rec(i + 1, !st));
    }
    return ret;
}
void solve() {
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << max(rec(0, 1), rec(0, 0));
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





