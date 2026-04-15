#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
string s, t;
int dp[1001][1001];
int fun(int i, int j) {
    if (i == s.size() || j == t.size())return 0;
    int& ret = dp[i][j];
    if (~ret)return ret;
    if (s[i] == t[j]) {
        return ret = fun(i + 1, j + 1) + 1;
    }
    return  ret = max({ ret, fun(i + 1, j),fun(i,j + 1) });
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (getline(cin, s) && getline(cin, t)) {
        memset(dp, -1, sizeof dp);
        cout << fun(0, 0) << el;
    }
    return 0;
}
//
