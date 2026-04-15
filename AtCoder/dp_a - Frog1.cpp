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
int dp[100001];
int fun(int i = 0) {
    if (i >= n - 1)return 0;
    int& ret = dp[i];
    if (~ret)return ret;
    return ret = min(fun(i + 1) + abs(v[i] - v[i + 1]), fun(i + 2) + abs(v[i] - v[min(n - 1, i + 2)]));
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