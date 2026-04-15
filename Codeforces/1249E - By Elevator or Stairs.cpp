#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define all(v) v.begin(), v.end()
const int mod = 1e9 + 7, N = 2e5 + 3;
const int inv = 500000004;
int n;
int c;
int dp[N][2];
int a[N], e[N];
int func(int i, int b) {
    if (i == 0) {
        return 0;
    }
    int& ret = dp[i][b];
    if (~ret) return ret;
    ret = min(func(i - 1, 0) + a[i], func(i - 1, 1) + e[i] + ((b ^ 1) * c));
    return ret;
}
signed main() {

    int t = 1; //cin >> t;
    cin >> n >> c;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> e[i];
    }
    memset(dp, -1, sizeof dp);
    func(n - 1, 0);
    dp[0][0] = 0, dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        cout << max(dp[i][0], dp[i][1]) << ' ';
    }
    return 0;
}
//