#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        int pa = a * ax + b * ay + c;
        pa = pa > 0 ? 1 : -1;
        int pb = a * bx + b * by + c;
        pb = pb > 0 ? 1 : -1;
        if (pa != pb)
            ans++;
    }
    cout << ans;
}