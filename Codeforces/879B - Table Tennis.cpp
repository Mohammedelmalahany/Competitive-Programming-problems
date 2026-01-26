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
    ll k; cin >> k;
    ll t = k;
    vector <int> v(n);
    int cw; cin >> cw;
    v[0] = cw;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {
        if (cw > v[i])t--;
        if (t == 0)break;
        if (v[i] > cw)cw = v[i], t = k - 1;
    }
    cout << cw;

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




