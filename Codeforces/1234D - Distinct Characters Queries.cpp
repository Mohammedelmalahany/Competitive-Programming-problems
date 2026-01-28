#include <bits/stdc++.h>


using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 1000000007;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'
struct SegmentTree {
    struct Node {
        int mask = 0;
    };
    Node skip;
    vector<Node> tree;
    vector<int> lazy;
    int n;
    SegmentTree() {}
    SegmentTree(int m, string& a) {
        n = m;
        tree.resize(n << 2);
        lazy.resize(n << 2, 0);
        build(1, 0, n - 1, a);
    }
    // base case
    Node single(char c) {
        Node ret;
        ret.mask = 1 << (c - 'a');
        return ret;
    }
    Node merge(Node a, Node b) {
        Node ret;
        ret.mask = a.mask | b.mask;
        return ret;
    }
    void build(int u, int st, int en, string& a) {
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
        tree[u].mask += lazy[u];

        // move the lazy to my children
        if (st != en) {
            lazy[u << 1] += lazy[u];
            lazy[(u << 1) | 1] += lazy[u];
        }

        lazy[u] = 0;
    }
    void update(int u, int st, int en, int idx, char delta) {
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

    int query(int lx, int rx) {
        --lx, --rx;
        return __builtin_popcount(query(1, 0, n - 1, lx, rx).mask);
    }
    void update(int idx, char delta) {
        --idx;
        update(1, 0, n - 1, idx, delta);
    }
    void update_range(int lx, int rx, int delta) {
        --lx, --rx;
        update_range(1, 0, n - 1, lx, rx, delta);
    }
};
void solve() {
    string s;
    cin >> s;
    SegmentTree tre((int)s.size(), s);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        if (a == 1) {
            int idx; cin >> idx;
            char c; cin >> c;
            tre.update(idx, c);
        }
        else {
            int l, r; cin >> l >> r;
            cout << tre.query(l, r) << el;
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




