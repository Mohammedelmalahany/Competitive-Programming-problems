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
    int n;
    cin >> n;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                ll v1 = (y[j] - y[i]) * (x[k] - x[j]);
                ll v2 = (y[k] - y[j]) * (x[j] - x[i]);

                if (v1 != v2) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
//





