#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
const int INF = 0x3f3f3f3f;
const int LLINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1000000007;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<tuple<int, int, int> > v(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b;
        v[i] = make_tuple(a, b, i);
    }
    sort(all(v));
    vector<int> ans(n, -1);
    int m; cin >> m;
    int co = 0;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        int l = 0, r = n - 1, mid = l + r >> 1;
        while (l <= r) {
            mid = l + r >> 1;
            auto& [a, b, c] = v[mid];
            if (a > x) {
                r = mid - 1;
            }
            else if (a < x) {
                l = mid + 1;
            }
            else break;
        }
        auto [a, b, c] = v[mid];
        int ab = abs(a - x);
        if (y * y + ab * ab <= b * b && ans[c] == -1)ans[c] = i + 1, co++;
        if (mid < n - 1) {
            auto& [a1, b1, c1] = v[mid + 1];
            ab = abs(a1 - x);
            if (y * y + ab * ab <= b1 * b1 && ans[c1] == -1)ans[c1] = i + 1, co++;
        }
        if (mid > 0) {
            auto& [a2, b2, c2] = v[mid - 1];
            ab = abs(a2 - x);
            if (y * y + ab * ab <= b2 * b2 && ans[c2] == -1)ans[c2] = i + 1, co++;
        }

    }
    cout << co << el;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}

//
