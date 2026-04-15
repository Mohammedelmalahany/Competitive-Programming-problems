#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
int v[1001];
int dp[101][3];
int n;
int fun(int i, int b) {
    if (i == n)return 0;
    int& ret = dp[i][b];
    if (~ret)return ret;
    ret = fun(i + 1, 0) + 1;
    if (b == 1) {
        if (v[i] == 1 || v[i] == 3)
            ret = min(ret, fun(i + 1, 2));
    }
    else if (b == 2) {
        if (v[i] == 2 || v[i] == 3)
            ret = min(ret, fun(i + 1, 1));
    }
    else {
        if (v[i] == 3)ret = min({ ret, fun(i + 1, 2) ,fun(i + 1, 1) });
        if (v[i] == 1)ret = min(ret, fun(i + 1, 2));
        if (v[i] == 2)ret = min(ret, fun(i + 1, 1));

    }
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)cin >> v[i];
    memset(dp, -1, sizeof dp);
    cout << fun(0, 0);
    return 0;
}
//