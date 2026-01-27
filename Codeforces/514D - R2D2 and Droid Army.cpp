#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
#define all(v) ((v).begin()), ((v).end())

using arr5 = array<int, 5>;
vector<arr5> arr;

struct SegmentTree {
#define mid ((l + r) >> 1)
    int n, m;
    vector<arr5> seg;

    SegmentTree(int n, int m) : n(n), m(m) {
        seg.assign(4 * n, arr5{});
        build(0, n - 1, 1);
    }

    arr5 merge(const arr5& v1, const arr5& v2) {
        arr5 v{};
        for (int i = 0; i < m; i++)
            v[i] = max(v1[i], v2[i]);
        return v;
    }

    void build(int l, int r, int node) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }
        build(l, mid, 2 * node);
        build(mid + 1, r, 2 * node + 1);
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    arr5 query(int l, int r, int node, int ql, int qr) {
        if (r < ql || l > qr) return arr5{};
        if (l >= ql && r <= qr) return seg[node];
        arr5 v1 = query(l, mid, 2 * node, ql, qr);
        arr5 v2 = query(mid + 1, r, 2 * node + 1, ql, qr);
        return merge(v1, v2);
    }
#undef mid
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    arr.resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    SegmentTree segtree(n, m);

    arr5 ans{};
    int len = 0;

    for (int l = 0; l < n; l++) {
        arr5 st = segtree.query(0, n - 1, 1, l, l);
        int sum = 0;
        for (int j = 0; j < m; j++) sum += st[j];
        if (sum > k) continue;

        if (len < 1) {
            len = 1;
            ans = st;
        }

        int start = l, end = n - 1, mi;
        while (start <= end) {
            mi = (start + end) >> 1;
            arr5 v = segtree.query(0, n - 1, 1, l, mi);
            sum = 0;
            for (int j = 0; j < m; j++) sum += v[j];
            if (sum > k) {
                end = mi - 1;
            }
            else {
                if (len < (mi - l + 1)) {
                    len = (mi - l + 1);
                    ans = v;
                }
                start = mi + 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
