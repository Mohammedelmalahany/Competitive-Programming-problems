#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n, vector<int>& v) {
        this->n = n;
        tree.resize(4 * n);
        build(1, 0, n - 1, v);
    }

    void build(int u, int st, int en, vector<int>& a) {
        if (st == en) {
            tree[u] = a[st];
            return;
        }
        int mid = (st + en) / 2;
        build(2 * u, st, mid, a);
        build(2 * u + 1, mid + 1, en, a);
        tree[u] = gcd(tree[2 * u], tree[2 * u + 1]);
    }
    int query(int u, int st, int en, int l, int r) {
        if (st > r || en < l) return 0; 
        if (st >= l && en <= r) return tree[u];
        int mid = (st + en) / 2;
        return gcd(query(2 * u, st, mid, l, r), query(2 * u + 1, mid + 1, en, l, r));
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
void solve() {
    int n; cin >> n;
    vector<int > v(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        g = gcd(g, v[i]);
    }
    for (int i = 0; i < n; i++) {
        v[i] /= g;
    }
    for (int i = 0; i < n; i++) {
        v.push_back(v[i]);
    }

    SegmentTree tre(2 * n, v);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1)continue;
        int q;
        int f = i;
        int st = i, en = n + i - 1;
        while (st <= en) {
            int mid = st + en >> 1;
            q = tre.query(i, mid);
            if (q <= 1) {
                en = mid - 1;
            }
            else st = mid + 1, f = mid;
        }
        ans = max(f - i + 1, ans);
    }
    cout << ans << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
//


