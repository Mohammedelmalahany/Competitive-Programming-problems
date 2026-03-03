#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if (n <= 2) {
        cout << 1;
        return 0;
    }
    else if (n <= 4) {
        cout << 2;
        return 0;
    }
    int gn = n;
    int ans = 2;
    n -= 3;
    unordered_map<int, int> m;
    m[0] = 1;
    m[1] = 2;
    m[2] = 3;
    while (n > 0) {
        int x = n;
        n -= m[ans - 1];
        if (n >= 0) {
            ans++;
        }
        else break;
        m[ans] = m[ans - 1] + m[ans - 2];
    }
    cout << ans;
    return 0;
}

//
