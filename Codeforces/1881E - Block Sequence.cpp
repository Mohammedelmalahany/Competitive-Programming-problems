#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
vector<int> v;
int n;
vector<int> dp;
int fun(int i) {
    if (i > n)return 1e18;
    if (i == n) {
        return 0;
    }
    int& ret = dp[i];
    if (~ret)return ret;
    return ret = min({ fun(i + 1) + 1,fun(i + v[i] + 1) });
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        dp.assign(n, -1);
        v.assign(n, 0);
        for (int i = 0; i < n; i++)cin >> v[i];
        cout << fun(0) << el;
    }
    return 0;
}
//
