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
    int n;
    struct Node {
        int mx, rt, lf;
    };
    Node skip;
    vector<Node> tree;
    SegmentTree(int n, string& s) {
        this->n = n;
        tree.resize(n << 2);
        skip = { 0, 0, 0 };
        build(1, 0, n - 1, s);
    }
    Node single(char c) {
        if (c == '(') return { 0, 1, 0 };
        else return { 0, 0, 1 };
    }
    Node merge(Node a, Node b) {
        Node ret;
        int match = min(a.rt, b.lf);
        ret.mx = a.mx + b.mx + 2 * match;
        ret.rt = a.rt + b.rt - match;
        ret.lf = a.lf + b.lf - match;
        return ret;
    }
    void build(int u, int st, int en, string& s) {
        if (st == en) {
            tree[u] = single(s[st]);
            return;
        }
        int mid = (st + en) >> 1;
        build(u << 1, st, mid, s);
        build(u << 1 | 1, mid + 1, en, s);
        tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
    }
    Node query(int u, int st, int en, int l, int r) {
        if (st > r || en < l) return skip;
        if (st >= l && en <= r) return tree[u];
        int mid = (st + en) >> 1;
        return merge(
            query(u << 1, st, mid, l, r),
            query(u << 1 | 1, mid + 1, en, l, r)
        );
    }
    int query(int l, int r) {
        --l; --r;
        return query(1, 0, n - 1, l, r).mx;
    }
};
void solve() {
    string s;
    cin >> s;
    int n = s.size();

    SegmentTree st(n, s);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
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





