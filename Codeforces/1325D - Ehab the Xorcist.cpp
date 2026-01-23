#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'



int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        ll u, v; cin >> u >> v;
        if (v < u || ((v & 1) != (u & 1))) {
            cout << -1; break;
        }
        if (u == 0 && v == 0) {
            cout << 0;
            break;
        }
        if (u == v) {
            cout << 1 << el << u;
            break;
        }
        //v (a1 + a2) = u (a1 XOR a2) + 2 * ((v - u) / 2) (a1 & a2)
        //which means we can get u from two nums only when ((a1 & a2) & u) = 0
        if (!(((v - u) >> 1) & u)) {
            cout << 2 << el;
            cout << ((v - u) >> 1) << ' ' << ((v - u) >> 1) + u;
            break;
        }
        cout << 3 << el;
        cout << u << ' ' << ((v - u) >> 1) << " " << ((v - u) >> 1);
    }
}