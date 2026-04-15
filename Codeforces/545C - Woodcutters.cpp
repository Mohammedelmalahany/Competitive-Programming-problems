#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define all(v) v.begin(), v.end()
const int mod = 1e9 + 7, N = 1e5 + 3;
const int inv = 500000004;
int n;
int c;
int dp[N][2];
int v[N], h[N];
int func(int i, int b) {
    if (i == n + 1)return 0;
    int& ret = dp[i][b];
    if (~ret)return ret;
    int ls = v[i - 1];
    if (b)ls += h[i - 1];
    //left
    if (v[i] - h[i] > ls)ret = max(ret, func(i + 1, 0) + 1);
    //right 
    if (v[i] + h[i] < v[i + 1])ret = max(ret, func(i + 1, 1) + 1);
    ret = max(ret, func(i + 1, 0));
    return ret;
}
signed main() {

    int t = 1; //cin >> t;
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> v[i] >> h[i];
    v[0] = -1e18, v[n + 1] = 1e18;
    cout << func(1, 0);
    return 0;
}
//