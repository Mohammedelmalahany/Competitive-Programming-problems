#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'


vector<int> arr;
int divisors[1000005];
void sieve() {

    for (int i = 2; i < 1000005; i++) {
        divisors[i]++;
        for (ll j = 1ll * i * i; j < 1000005; j += i) {
            divisors[j]++;
            divisors[j] += (j == (1ll * i * i) ? 0 : 1);
        }
    }
    for (int i = 1; i < 1000005; i++) {
        divisors[i]++;

    }
}

struct SegmentTree {
    struct Node {
        ll mx = 0;
        ll sum = 0;
    };
    Node skip;
    vector<Node> tree;
    vector<int> lazy;
    int n;
    SegmentTree() {}
    SegmentTree(int m, vector<int>& a) {
        n = m;
        tree.resize(n << 2);
        lazy.resize(n << 2, 0);
        build(1, 0, n - 1, a);
    }

    // base case
    Node single(int x) {
        Node ret;
        ret.mx = x;
        ret.sum = x;
        return ret;
    }
    Node merge(Node a, Node b) {
        Node ret;
        ret.mx = max(a.mx, b.mx);
        ret.sum = a.sum + b.sum;
        return ret;
    }
    void build(int u, int st, int en, vector<int>& a) {
        if (st == en) {
            tree[u] = single(a[st]);
            return;
        }
        int mid = st + en >> 1;
        build(u << 1, st, mid, a);
        build((u << 1) | 1, mid + 1, en, a);
        tree[u] = merge(tree[u << 1], tree[(u << 1) | 1]);
    }
    void prop(int u, int st, int en) {
        if (!lazy[u]) return;

        // update the node value
        //tree[u].f += lazy[u];

        // move the lazy to my children
        if (st != en) {
            lazy[u << 1] += lazy[u];
            lazy[(u << 1) | 1] += lazy[u];
        }

        lazy[u] = 0;
    }
    void update(int u, int st, int en, int idx, int delta) {
        prop(u, st, en);
        if (idx > en || idx < st) return;
        if (st == en) {
            tree[u] = single(delta);
            return;
        }
        int mid = st + en >> 1;
        update(u << 1, st, mid, idx, delta);
        update((u << 1) | 1, mid + 1, en, idx, delta);
        tree[u] = merge(tree[u << 1], tree[(u << 1) | 1]);
    }
    void update_range(int u, int st, int en, int lx, int rx, int delta) {
        prop(u, st, en);
        if (st > rx || en < lx) return;
        if (st >= lx && en <= rx) {
            lazy[u] += delta;
            prop(u, st, en);
            return;
        }
        int mid = st + en >> 1;
        update_range(u << 1, st, mid, lx, rx, delta);
        update_range((u << 1) | 1, mid + 1, en, lx, rx, delta);
        tree[u] = merge(tree[u << 1], tree[(u << 1) | 1]);
    }
    Node query(int u, int st, int en, int lx, int rx) {
        prop(u, st, en);
        if (st > rx || en < lx) return skip;
        if (st >= lx && en <= rx) return tree[u];
        int mid = st + en >> 1;
        return merge(query(u << 1, st, mid, lx, rx),
            query((u << 1) | 1, mid + 1, en, lx, rx));
    }
    void kill_TLE(int u, int st, int en, int l, int r) {
        if (st > r || en < l) return;
        if (tree[u].mx <= 2) return;
        if (st == en) {
            tree[u].mx = divisors[tree[u].mx];
            tree[u].sum = tree[u].mx;
            return;
        }
        int mid = (st + en) >> 1;
        kill_TLE(u << 1, st, mid, l, r);
        kill_TLE((u << 1) | 1, mid + 1, en, l, r);
        tree[u] = merge(tree[u << 1], tree[(u << 1) | 1]);
    }

    ll query(int lx, int rx, char ask) {
        --lx, --rx;
        if (ask == 'm')
            return query(1, 0, n - 1, lx, rx).mx;
        else return query(1, 0, n - 1, lx, rx).sum;
    }
    void update(int idx, int delta) {
        --idx;
        update(1, 0, n - 1, idx, delta);
    }
    void update_range(int lx, int rx, int delta) {
        --lx, --rx;
        update_range(1, 0, n - 1, lx, rx, delta);
    }
};
void solve() {
    sieve();
    int n, m; cin >> n >> m;
    vector<int > v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    SegmentTree tre(n, v);
    while (m--) {
        int a; cin >> a;
        int l, r; cin >> l >> r;
        if (a == 1) {
            tre.kill_TLE(1, 0, n - 1, --l, --r);
        }
        else {
            cout << tre.query(l, r, 's') << el;
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





