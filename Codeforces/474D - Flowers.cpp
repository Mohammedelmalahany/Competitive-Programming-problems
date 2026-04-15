#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 1e9 + 7;
const int inv = 500000004;

int k;
int dp[100005];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t >> k;

    dp[0] = 1;

    for (int i = 1; i <= 1e5; i++) {
        dp[i] = (dp[i - 1] + (i - k < 0 ? 0 : dp[i - k])) % MOD;
    }

    for (int i = 1; i <= 1e5; i++) {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }

    while (t--) {
        int a, b;
        cin >> a >> b;

        cout << (dp[b] - dp[a - 1] + MOD) % MOD << el;
    }

    return 0;
}
//