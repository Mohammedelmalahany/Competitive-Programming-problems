#include <bits/stdc++.h>

using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
const int MOD = 998244353;
const int N = 2e5 + 2;
int n;
vector<int> lin(105);
bool is(int r, int c) {
    if (r < 1 || r > n + 1 || c < 0) {
        return 0;
    }
    return 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> lin[i];
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    c1--;
    c2--;
    int r3 = r1, r4 = r2;
    bool b = 0;

    if (r4 < r3) b = 1;
    int ans = 1e10;
    if (b) {
        int mn = c1;
        for (int i = r1 - 1; i >= r2; i--) {
            mn = min(mn, lin[i]);
        }
        for (int k = r1; k <= n; k++) {
            int st = abs(k - r2) + abs(r1 - k);
            mn = min(mn, k == r1 ? c1 : lin[k]);
            int cur = mn;
            ans = min(ans, st + abs(c2 - mn));
            for (int i = r2 - 1; i >= 1; i--) {
                cur = min(cur, lin[i]);
                ans = min(ans, abs(cur - c2) + 2 * abs(i - r2) + st);
            }
        }
    }
    else {
        int mn = c1;
        for (int i = r1 + 1; i <= r2; i++) {
            mn = min(mn, lin[i]);
        }
        for (int k = r1; k >= 1; k--) {
            int st = abs(k - r2) + abs(r1 - k);
            mn = min(mn, k == r1 ? c1 : lin[k]);
            int cur = mn;
            ans = min(ans, st + abs(c2 - mn));
            for (int i = r2 + 1; i <= n; i++) {
                cur = min(cur, lin[i]);
                ans = min(ans, abs(cur - c2) + 2 * abs(i - r2) + st);
            }
        }
    }
    cout << ans;
}

