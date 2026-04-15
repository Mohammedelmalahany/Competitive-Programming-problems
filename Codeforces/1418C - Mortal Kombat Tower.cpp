#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7, N = 1e5 + 3;
const int inv = 500000004;
int n, m;
vector<vector<vector<int>>>dp;
vector<int>v;
int func(int i, bool role, bool st) {
    if (i == n)return 0;
    int& ret = dp[i][role][st];
    if (~ret)return ret;
    if (role) {
        if (st) {
            ret = func(i + 1, 0, 0);
        }
        else {
            ret = min(func(i + 1, role, 1), func(i + 1, 0, 0));
        }
    }
    else {
        if (st) {
            ret = func(i + 1, 1, 0) + v[i];
        }
        else {
            ret = min(func(i + 1, role, 1) + v[i], func(i + 1, 1, 0) + v[i]);
        }
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n + 1);
        dp.assign(n, vector<vector<int>>(2, vector<int>(2)));
        for (int i = 0; i < n; i++)for (int j = 0; j < 2; j++)for (int k = 0; k < 2; k++)dp[i][j][k] = -1;
        for (int i = 0; i < n; i++)cin >> v[i];
        cout << func(0, 0, 0) << el;
    }
    return 0;
}
//
