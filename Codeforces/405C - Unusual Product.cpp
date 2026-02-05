#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define int long long
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 1000000007;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'
//idea the only effect on the dot product of a binary square matrix is the diagonal, so XOR do the work
//or you can simply make parity and not parity
void solve() {
    int n; cin >> n;
    int pr = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            if (i == j) pr ^= a;
        }
    int q; cin >> q;
    string s = "";
    while (q--) {
        int t; cin >> t;
        if (t != 3)cin >> t, pr ^= 1;
        else s.push_back(char('0' + pr));
    }
    cout << s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

//



