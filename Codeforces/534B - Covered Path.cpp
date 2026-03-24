#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, vv; cin >> v >> vv;
    int t, d; cin >> t >> d;
    if (v > vv)swap(v, vv);
    int pr = v;
    int ans = v;
    t--;
    while (t) {
        bool b = 0;
        for (int i = d; ~i; i--) {
            if (abs((pr + i) - vv) <= abs((t - 1) * d)) {
                ans += pr + i;
                pr += i;
                b = 1;
                t--;
                break;
            }
        }
        if (!b) {
            for (int i = 0; i <= d; i++) {
                if (abs((pr - i) - vv) <= abs((t - 1) * d)) {
                    ans += pr - i;
                    pr -= i;
                    t--;
                    break;
                }
            }
        }

    }
    cout << ans;
    return 0;
}
//
