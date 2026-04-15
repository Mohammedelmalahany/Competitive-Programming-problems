#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;
int n, W;
vector<int> w;
vector<int> v;
int dp[200001][3];
int fun(int i = 0, int r = 1) {
    if (i == n)return 0;
    int& ret = dp[i][r];
    if (~ret)return ret;
    return ret = max(fun(i + 1, r), fun(i + 1, r ^ 1) + ((1 + (r ^ 1)) * v[i]));
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.resize(n);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << fun();
    return 0;
}
//