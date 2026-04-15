#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
string s, t;
int n;
int dp[3001][3001];
int fun(int i, int j) {
    if (i == s.size() || j == t.size())return 0;
    int& ret = dp[i][j];
    if (~ret)return ret;
    if (s[i] == t[j]) {
        return ret = max(ret, fun(i + 1, j + 1) + 1);
    }
    return  ret = max({ ret, fun(i + 1, j),fun(i,j + 1) });
}
void build(int i, int j) {
    if (i == s.size() || j == t.size())return;

    if (s[i] == t[j]) {
        cout << s[i];
        build(i + 1, j + 1);
        return;
    }
    if (dp[i + 1][j] > dp[i][j + 1]) {
        build(i + 1, j);
    }
    else build(i, j + 1);
    return;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    fun(0, 0);

    build(0, 0);
    return 0;
}
//