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
    struct Node {
        ll val = 0;
        ll cnt = 0;
    };
    Node skip;
    vector<Node> tree;
    SegmentTree(int n) {
        this->n = n;
        skip.val = 0;
        skip.cnt = 0;
        tree.resize(n << 2);
    }
    Node single(int x) {
        Node r;
        r.val += x;
        r.cnt++;
        return r;
    }
    Node merge(Node a, Node b) {
        Node ret;
        ret.val = a.val + b.val;
        ret.cnt = a.cnt + b.cnt;
        return ret;
    }
    void build(int u, int st, int en, vector<int>& a) {
        if (st == en) return void(tree[u] = single(a[st]));
        int mid = st + en >> 1;
        build(u << 1, st, mid, a);
        build((u << 1) | 1, mid + 1, en, a);
        tree[u] = merge(tree[u << 1], tree[(u << 1) | 1]);
    }
    void update(int u, int st, int en, int idx, int val) {
        if (idx > en || idx < st) return;
        if (st == en) {
            tree[u].cnt++, tree[u].val += val;
            return;
        }
        int mid = st + en >> 1;
        update(u << 1, st, mid, idx, val);
        update((u << 1) | 1, mid + 1, en, idx, val);
        tree[u] = merge(tree[u << 1], tree[(u << 1) | 1]);
    }
    Node query(int u, int st, int en, int l, int r) {
        if (st >= l && en <= r) return tree[u];
        if (st > r || en < l) return skip;
        int mid = st + en >> 1;
        return merge(query(u << 1, st, mid, l, r), query((u << 1) | 1, mid + 1, en, l, r));
    }
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    Node query(int l, int r) {
        --l, --r;
        return query(1, 0, n - 1, l, r);
    }
};
int n;
void solve() {
    cin >> n;  vector<ll> A(n), mdi;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        mdi.push_back(A[i]);
    }
    sort(mdi.begin(), mdi.end());
    mdi.erase(unique(mdi.begin(), mdi.end()), mdi.end());
    SegmentTree st(mdi.size());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(mdi.begin(), mdi.end(), A[i]) - mdi.begin();
        auto res = st.query(1, idx);
        ans += res.cnt * A[i] - res.val;
        st.update(idx, A[i]);
    }
    cout << ans << "\n";
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