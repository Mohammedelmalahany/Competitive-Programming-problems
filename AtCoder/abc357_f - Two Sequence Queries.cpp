#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

struct Node {
    ll suma, sumb, sumab;
    int len;
    Node(ll a = 0, ll b = 0, ll ab = 0, int l = 0) : suma(a), sumb(b), sumab(ab), len(l) {}
};

struct Lazy {
    ll adda, addb;
    Lazy(ll a = 0, ll b = 0) : adda(a), addb(b) {}
};

struct SegTree {
    int n;
    vector<Node> seg;
    vector<Lazy> lazy;
    SegTree(vector<ll>& A, vector<ll>& B) {
        n = (int)A.size();
        seg.assign(4 * n, Node());
        lazy.assign(4 * n, Lazy());
        build(1, 0, n - 1, A, B);
    }
    Node merge(Node L, Node R) {
        return Node(
            (L.suma + R.suma) % MOD,
            (L.sumb + R.sumb) % MOD,
            (L.sumab + R.sumab) % MOD,
            L.len + R.len
        );
    }
    void apply(int idx, Lazy v) {
        ll adda = v.adda % MOD;
        ll addb = v.addb % MOD;
        Node& nd = seg[idx];
        ll newab = (nd.sumab + adda * nd.sumb % MOD + addb * nd.suma % MOD + (1LL * nd.len * adda % MOD) * addb % MOD) % MOD;
        ll newa = (nd.suma + 1LL * nd.len * adda) % MOD;
        ll newb = (nd.sumb + 1LL * nd.len * addb) % MOD;
        nd.sumab = newab;
        nd.suma = newa;
        nd.sumb = newb;
        lazy[idx].adda = (lazy[idx].adda + adda) % MOD;
        lazy[idx].addb = (lazy[idx].addb + addb) % MOD;
    }
    void push(int idx) {
        if (lazy[idx].adda != 0 || lazy[idx].addb != 0) {
            apply(idx * 2, lazy[idx]);
            apply(idx * 2 + 1, lazy[idx]);
            lazy[idx] = Lazy();
        }
    }
    void build(int idx, int l, int r, vector<ll>& a, vector<ll>& b) {
        if (l == r) {
            seg[idx] = Node(a[l] % MOD, b[l] % MOD, (a[l] % MOD * b[l]) % MOD, 1);
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid, a, b);
        build(idx * 2 + 1, mid + 1, r, a, b);
        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }
    void update(int idx, int l, int r, int ql, int qr, Lazy v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(idx, v);
            return;
        }
        push(idx);
        int mid = (l + r) / 2;
        update(idx * 2, l, mid, ql, qr, v);
        update(idx * 2 + 1, mid + 1, r, ql, qr, v);
        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }
    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return Node(0, 0, 0, 0);
        if (ql <= l && r <= qr) return seg[idx];
        push(idx);
        int mid = (l + r) / 2;
        return merge(query(idx * 2, l, mid, ql, qr),
            query(idx * 2 + 1, mid + 1, r, ql, qr));
    }
    void update(int l, int r, ll adda, ll addb) {
        update(1, 0, n - 1, l, r, Lazy(adda, addb));
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r).sumab % MOD;
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    SegTree st(a, b);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; ll x;
            cin >> l >> r >> x;
            --l; --r;
            st.update(l, r, x, 0);
        }
        else if (t == 2) {
            int l, r; ll x;
            cin >> l >> r >> x;
            --l; --r;
            st.update(l, r, 0, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << st.query(l, r) << "\n";
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