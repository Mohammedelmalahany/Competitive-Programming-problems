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

    int n; cin >> n;
    vector<ld> a(n), b(n);
    ld tt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        tt += a[i] / b[i];
    }
    ld mt = tt / 2.0;
    ld ans = 0;
    for (int i = 0; i < n; i++) {
        ld cur_t = a[i] / b[i];
        if (mt >= cur_t) {
            ans += a[i];
            mt -= cur_t;
        }
        else {
            ans += mt * b[i];
            break;
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
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