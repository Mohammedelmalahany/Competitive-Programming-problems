#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 998244353;
const int N = 2e5 + 2;
int add(int a, int b, int MOD = 1e17) {
    return (a + b) % MOD;
}
int sub(int a, int b, int MOD = 1e17) {
    return (a - b + MOD) % MOD;
}
int mul(int a, int b, int MOD = 1e17) {
    return (a * b) % MOD;
}
int fp(int a, int pw, int MOD = 1e17) {
    if (!pw)return 1;
    int ret = fp(a, pw >> 1, MOD);
    ret = mul(ret, ret, MOD);
    if (pw & 1)ret = mul(ret, a, MOD);
    return ret;
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int n;
vector<bool> lin(100003);
int dp[100003][3][2];
int rec(int i, int state, bool prv) {
    if (i == n)return 0;
    int& ret = dp[i][state][prv];
    if (~ret)return ret;
    if (state == 0) {
        ret = max(ret, rec(i + 1, 0, (prv == lin[i]) ? prv : lin[i]) + (prv != lin[i]));
        ret = max(ret, rec(i, 1, prv));
    }
    else if (state == 1) {
        ret = max(ret, rec(i + 1, 1, (prv == !lin[i]) ? prv : !lin[i]) + (prv != !lin[i]));
        ret = max(ret, rec(i, 2, prv));
    }
    else {
        ret = max(ret, rec(i + 1, 2, (prv == lin[i]) ? prv : lin[i]) + (prv != lin[i]));
    }
    return ret;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        lin[i] = c - '0';
    }

    memset(dp, -1, sizeof dp);
    cout << max(rec(0, 0, 1), rec(0, 0, 0));

}

//
