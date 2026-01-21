#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

ll dp[2 * 100001][4];
int n;
vector<int> a;
vector<int>b;
ll rec(int i, int p) {
    if (i == n)return 1;
    ll& ret = dp[i][p];
    if (~ret)return ret;
    ret = 0;
    if (p == 0) {
        int pre = a[i - 1];
        if (a[i] != pre)
            ret += rec(i + 1, 0) % MOD;
        if (b[i] != pre)
            ret += rec(i + 1, 1) % MOD;
    }
    else if (p == 1) {
        int pre = b[i - 1];
        if (a[i] != pre)
            ret += rec(i + 1, 0) % MOD;
        if (b[i] != pre)
            ret += rec(i + 1, 1) % MOD;
    }
    else ret += rec(i + 1, 0) % MOD + rec(i + 1, 1) % MOD;
    return ret % MOD;
}

void solve(int c) {
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
    cout << rec(0, 2);
}



int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        solve(i);
        i++;
    }
}




