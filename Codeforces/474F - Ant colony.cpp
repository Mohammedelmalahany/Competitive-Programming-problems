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

struct SegmentTree {
#define mid ((l + r) >> 1)
    struct Node {
        int gc = 0, cnt = 0;
        Node(int g = 0, int c = 0) : gc(g), cnt(c) {}
    };

    vector<Node> tree;
    int n;

    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, {});
        build(0, n - 1, 1);
    }

    Node merge(const Node& n1, const Node& n2) {
        if (n1.gc == 0) return n2;
        if (n2.gc == 0) return n1;
        int g = gcd(n1.gc, n2.gc);
        int c = 0;
        if (g == n1.gc) c += n1.cnt;
        if (g == n2.gc) c += n2.cnt;
        return Node(g, c);
    }

    void build(int l, int r, int node) {
        if (l == r) {
            tree[node].gc = arr[l];
            tree[node].cnt = 1;
            return;
        }
        build(l, mid, 2 * node);
        build(mid + 1, r, 2 * node + 1);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int ql, int qr, int l, int r, int node) {
        if (qr < l || ql > r) {
            return Node(0, 0);
        }
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        Node leftNode = query(ql, qr, l, mid, 2 * node);
        Node rightNode = query(ql, qr, mid + 1, r, 2 * node + 1);
        return merge(leftNode, rightNode);
    }
};

void solve() {
    int n; cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree seg(n);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        --a; --b;
        cout << (b - a + 1) - seg.query(a, b, 0, n - 1, 1).cnt << "\n";
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





