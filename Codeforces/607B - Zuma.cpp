#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int n;
int dp[501][501];
vector<int> v;
int rec(int i, int j) {
    if (i > j)return 0;
    if (i == j)return 1;
    int& ret = dp[i][j];
    if (~ret)return ret;
    ret = INF;
    //take alone
    ret = min(ret, 1 + rec(i + 1, j));
    //take optimal when char equal to another one
    for (int k = j; k > i; k--) {
        if (v[k] == v[i]) {
            bool b = 0;
            if (k == i + 1)b = 1;
            ret = min(ret, b + rec(i + 1, k - 1) + rec(k + 1, j));
        }
    }
    return ret;
}
void solve() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1);
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





