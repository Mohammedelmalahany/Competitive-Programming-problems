#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
int v[2001];
int n, h, l, r;
string s, t, c;
vector<vector<int>> dp;
int fun(int i, int j) {
    if (i == s.size() && j == t.size())return 0;
    int& ret = dp[i][j];
    if (~ret)return ret;
    ret = 1e18;
    if (i < s.size()) ret = min(ret, fun(i + 1, j) + (c[i + j] != s[i]));
    if (j < t.size()) ret = min(ret, fun(i, j + 1) + (c[i + j] != t[j]));
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> s >> t >> c;
        dp.assign(s.size() + 1, vector<int>(t.size() + 1, -1));
        cout << fun(0, 0) << el;
    }
    return 0;
}
//
