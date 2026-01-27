#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

const int MAXN = 100000 + 5;
const int LOG = 20;

int arr[MAXN];
int st[MAXN][LOG];
int lg2_[MAXN];


void build(int n) {
    for (int i = 0; i < n; i++) st[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int j = lg2_[R - L + 1];
    return gcd(st[L][j], st[R - (1 << j) + 1][j]);
}


void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    lg2_[1] = 0;
    for (int i = 2; i <= n; i++) lg2_[i] = lg2_[i / 2] + 1;

    build(n);

    unordered_map<int, ll> ma;

    for (int l = 0; l < n; l++) {
        int r = l;
        while (r < n) {
            int g = query(l, r);
            int lo = r, hi = n - 1, ans = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (query(l, mid) == g) {
                    ans = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            ma[g] += (ans - r + 1);
            r = ans + 1;
        }
    }


    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        cout << ma[a] << el;
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





