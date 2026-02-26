#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define int unsigned long long
#define all(v) v.begin(), v.end()
const int MOD = 998244353;

int add(int a, int b, int MOD = 1e20) {
    return (a + b) % MOD;
}
int sub(int a, int b, int MOD = 1e20) {
    return (a - b + MOD) % MOD;
}
int mul(int a, int b, int MOD = 1e20) {
    return (a * b) % MOD;
}
int fp(int a, int pw, int MOD = 1e20) {
    if (!pw)return 1;
    int ret = fp(a, pw >> 1, MOD);
    ret = mul(ret, ret, MOD);
    if (pw & 1)ret = mul(ret, a, MOD);
    return ret;
}
//mersenne primes
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool arr[34] = {};
    arr[2] = 1;
    arr[3] = 1, arr[5] = 1, arr[7] = 1, arr[13] = 1, arr[17] = 1, arr[19] = 1, arr[31] = 1;
    int n;
    while (cin >> n) {
        if (!n)return 0;
        if (arr[n]) {
            cout << "Perfect: " << mul(fp(2, n - 1), (add(fp(2, n), -1))) << '!' << el;
        }
        else if (n == 11 || n == 23 || n == 29) {
            cout << "Given number is prime. But, NO perfect number is available." << el;
        }
        else {
            cout << "Given number is NOT prime! NO perfect number is available." << el;
        }
    }
}

//