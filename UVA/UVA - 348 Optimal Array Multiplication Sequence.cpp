#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
const int INF = 0x3f3f3f3f;
const int LLINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1000000007;
int n;
int dp[11][11];
int rows[11], cols[11];
int rec(int i, int j) {
    if (i >= j)return 0;
    int& ret = dp[i][j];
    if (~ret)return ret;
    ret = INF;
    for (int k = i; k < j; k++) {
        ret = min(ret, rec(i, k) + rec(k + 1, j) + (rows[i] * cols[i] * cols[j]));
    }
    return ret;
}
string build(int i, int j) {
    if (i == j)return "A" + to_string(i + 1);
    int& ret = dp[i][j];
    int mn = INF;
    int nk = i;
    for (int k = i; k < j; k++) {
        int call = rec(i, k) + rec(k + 1, j) + (rows[i] * cols[i] * cols[j]);
        if (call < mn) {
            mn = call;
            nk = k;
        }
    }
    string s = "(";
    s += build(i, nk);
    s += " x ";
    s += build(nk + 1, j);
    s += ")";
    return s;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (cin >> n) {
        if (!n)return 0;
        for (int i = 0; i < n; i++)cin >> rows[i] >> cols[i];
        memset(dp, -1, sizeof dp);
        rec(0, n - 1);
        cout << "Case " << t << ": " << build(0, n - 1) << el;
        t++;
    }

    return 0;
}

//
