#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
int n, k;
vector<int> w;
vector<int> v;
int dp[100001];
int fun(int i = 0) {
    if (i >= n - 1)return 0;
    int& ret = dp[i];
    if (~ret)return ret;
    ret = 1e18;
    for (int j = 1; j <= k; j++) {
        ret = min(ret, fun(i + j) + abs(v[i] - v[min(n - 1, i + j)]));
    }
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    v.resize(n);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << fun();
    return 0;
}
//