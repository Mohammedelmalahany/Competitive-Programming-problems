#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define int  long long
#define all(v) v.begin(), v.end()
const int MOD = 998244353;
const int N = 1e5 + 2;
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
vector<int> pri;
bool a[N];
void get_primes(int st) {
    for (int i = 2; i <= st; i++) {
        if (a[i] == 0)pri.push_back(i);
        else continue;
        for (int j = i * i; j <= st; j += i) {
            a[j] = 1;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n) {
        if (!n)return 0;
        int ans = 1;
        int x = abs(n);
        int sq = sqrtl(x);
        for (int i = -sq; i <= sq; i++) {
            for (int j = ans; j <= 33; j++) {
                int f = fp(i, j);
                if (f > (1ll << 32))break;
                if (f == n)ans = j;
            }
        }
        cout << ans << el;
    }
}

//
