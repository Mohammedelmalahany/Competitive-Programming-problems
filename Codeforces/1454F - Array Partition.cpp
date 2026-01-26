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
        int mn, mx;
    };

    Node skip;
    vector<Node> tree;
    SegmentTree(int n, vector<int>& v) {
        this->n = n;
        tree.resize(n << 2);
        skip.mn = INT_MAX;
        skip.mx = INT_MIN;
        build(1, 0, n - 1, v);
    }
    Node single(int x) {
        return { x, x };
    }
    Node merge(Node a, Node b) {
        Node ret;
        ret.mn = min(a.mn, b.mn);
        ret.mx = max(a.mx, b.mx);
        return ret;
    }
    void build(int u, int st, int en, vector<int>& a) {
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
            query(u << 1 | 1, mid + 1, en, l, r));
    }
    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree st(n, a);
    bool flag = false;

    for (int x = 0; x < n - 2 && !flag; x++) {
        int val = st.query(0, x).mx;

        int l = x + 1, r = n - 2, y = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int mn = st.query(x + 1, mid).mn;

            if (mn == val) {
                y = mid;
                int mx = st.query(y + 1, n - 1).mx;
                if (mx == mn) {
                    break;
                }
                else if (mx < mn) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if (mn > val) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        if (y == -1) continue;

        if (st.query(y + 1, n - 1).mx == val) {
            cout << "YES\n";
            cout << x + 1 << " " << y - x << " " << n - y - 1 << "\n";
            flag = true;
        }
    }

    if (!flag) cout << "NO\n";
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






