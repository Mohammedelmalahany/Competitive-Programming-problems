#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int n, m;
bool cmp(pair<int, int>a, pair<int, int>b) {
    if (a.first != b.first)return a.first < b.first;
    if (abs(a.second) % 2 != abs(b.second) % 2) {
        return abs(a.second) % 2 == 1;
    }
    if (abs(a.second) % 2 == 1) {
        return a.second > b.second;
    }
    return a.second < b.second;
}
void solve() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            cout << 0 << ' ' << 0 << el;
            break;
        }
        vector<int> v(n);
        vector<pair<int, int>>ans(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ans[i] = { v[i] % m, v[i] };
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << n << ' ' << m << el;
        for (int i = 0; i < n; i++) {
            cout << ans[i].second << el;
        }
    }
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


