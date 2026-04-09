#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m; cin >> m;
    int mn = 1e12;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        mn = min(q, mn);
    }

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    if (n <= mn) {
        cout << a[n - 1];
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i += (mn + 2)) {
        int p = min(i + mn - 1, n - 1);
        if (i == 0) {
            ans += a[p];
        }
        else {
            ans += a[p] - a[i - 1];
        }
    }

    cout << ans << el;
    return 0;
}//
