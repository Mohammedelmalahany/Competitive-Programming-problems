#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'



struct SegmentTree {
    int n;
    struct Node {
        ll g;
    };

    Node skip;
    vector<Node> tree;

    SegmentTree(int n, vector<ll>& v) {
        this->n = n;
        tree.resize(n << 2);
        skip.g = 0;
        build(1, 0, n - 1, v);
    }

    Node single(ll x) {
        return { x };
    }

    Node merge(Node a, Node b) {
        return { std::gcd(a.g, b.g) };
    }

    void build(int u, int st, int en, vector<ll>& a) {
        if (st == en) {
            tree[u] = single(a[st]);
            return;
        }
        int mid = (st + en) >> 1;
        build(u << 1, st, mid, a);
        build(u << 1 | 1, mid + 1, en, a);
        tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
    }

    Node query(int u, int st, int en, int l, int r) {
        if (st > r || en < l) return skip;
        if (l <= st && en <= r) return tree[u];
        int mid = (st + en) >> 1;
        return merge(
            query(u << 1, st, mid, l, r),
            query(u << 1 | 1, mid + 1, en, l, r)
        );
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r).g;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    vector<ll> d(n - 1);
    for (int i = 0; i + 1 < n; i++)
        d[i] = llabs(a[i + 1] - a[i]);

    SegmentTree st(n - 1, d);

    int ans = 1;

    for (int i = 0; i < n - 1; i++) {
        int l = i, r = n - 2, ch = -1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (st.query(i, mid) > 1) {
                ch = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        if (ch != -1) {
            ans = max(ans, ch - i + 2); // +1 for using diff array
        }
    }

    cout << ans << '\n';
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





