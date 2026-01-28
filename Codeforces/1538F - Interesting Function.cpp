#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

void solve() {
    ll r, l; cin >> l >> r;
    ll sum = 0;
    int mul = 1;
    for (int i = 10; i <= r; i *= 10) {
        sum += ((r / i) - (l / i)) * 1;
        mul++;
    }

    cout << (r - l) + sum << el;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
//





