#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int n, m;

void solve() {
    cin >> n;
    for (int a = 0; a * a <= n; ++a) {
        for (int b = a; b * b <= n; ++b) {
            int rem = n - a * a - b * b;
            int c = sqrt(rem);
            if (c * c == rem) {
                cout << a << " " << b << " " << c << el;
                return;
            }
        }
    }
    cout << -1 << '\n';
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



