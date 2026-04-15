#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7, N = 2e5 + 3;
const int inv = 500000004;
int n;
int k, d;
int dp[N];
vector<vector<int>>v;
int func(int i) {
    if (i == n)return 0;
    int& ret = dp[i];
    if (~ret)return ret;
    ret = 0;
    int st = i + 1, en = n - 1;
    int bs = n;
    while (st <= en) {
        int mid = st + en >> 1;
        if (v[mid][0] > v[i][1])bs = mid, en = mid - 1;
        else st = mid + 1;
    }
    return ret = max(func(i + 1), func(bs) + v[i][2]);
}
bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}
signed main() {

    int t = 1; //cin >> t;
    memset(dp, -1, sizeof dp);
    cin >> n;
    v.assign(n, vector<int>(4));
    for (int i = 0; i < n; i++)for (int j = 0; j < 3; j++)cin >> v[i][j];

    sort(all(v), cmp);
    cout << func(0);

    return 0;
}
//
