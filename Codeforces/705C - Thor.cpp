#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long
#define ll long long

const int INF = INT32_MAX;
const ll MOD = 1000000007;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'


int ad(int a, int b) { a += b; if (a >= MOD)a -= MOD; if (a < 0)a += MOD; return a; }
int ml(int a, int b) { return (ll)a * b % MOD; }
int pw(int a, int b) { if (!b) return 1; int r = pw(a, b >> 1); r = ml(r, r); if (b & 1) r = ml(r, a); return r; }
int dv(int a, int b) { return ml(a, pw(b, MOD - 2)); }

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> appnt(n + 1);
    vector<int> order;
    vector<bool> read;
    int unread = 0;
    int ptr = 0;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            order.push_back(x);
            read.push_back(false);
            appnt[x].push_back(order.size() - 1);
            unread++;
        }
        else if (type == 2) {
            int x;
            cin >> x;
            for (int idx : appnt[x]) {
                if (!read[idx]) {
                    read[idx] = true;
                    unread--;
                }
            }
            appnt[x].clear();
        }
        else {
            int t;
            cin >> t;
            while (ptr < t) {
                if (!read[ptr]) {
                    read[ptr] = true;
                    unread--;
                }
                ptr++;
            }
        }
        cout << unread << el;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

//



