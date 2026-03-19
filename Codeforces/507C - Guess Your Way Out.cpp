#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
#define int long long
const int INF = 0x3f3f3f3f;
const int LLINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = LLINF;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int h, n; cin >> h >> n;
    //0  for left 1 for right
    int s = 0;
    int ans = 0;
    for (int i = h; i > 0; i--) {
        if (!s) {
            if (n > (1ll << (i - 1))) {
                for (int j = i - 1; j >= 0; j--)ans += (1ll << (j));
                ans++;
                n -= (1ll << (i - 1));
            }
            else {
                ans++;
                s ^= 1;
            }
        }
        else {
            if (n < ((1ll << (i - 1))) + 1) {
                for (int j = i - 1; j >= 0; j--)ans += (1ll << (j));
                ans++;
            }
            else {
                n -= (1ll << (i - 1));
                ans++;
                s ^= 1;
            }
        }
    }
    cout << ans;
    return 0;
}

//
