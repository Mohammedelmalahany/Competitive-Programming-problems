#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
//try to find the contribution of each point in a with the prev points in a (the contr is the intersection with lines draw by prev points)
// or with b
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    int i = 1;
    while (cin >> a >> b && a && b) {
        cout << "Case " << i << ": " << ((1ll * b * (b - 1) * a * (a - 1)) / 4) << el;
        i++;
    }
    return 0;
}
//