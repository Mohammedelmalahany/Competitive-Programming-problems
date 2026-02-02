#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long
#define ll long long

const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int n, c;
vector<vector<int>> mat;
vector<int >gold;
int dp[200005][2];

int rec(int i = 1, int pt = 0, int pr = 0) {

    int& ret = dp[i][pt];
    if (~ret)return ret;
    ret = 0;
    int cs = 0;

    int take = gold[i];
    {
        cs = pt ? 2 * c : 0;
        for (auto& a : mat[i]) {
            if (a == pr)continue;
            take += rec(a, 1, i);
        }
        take -= cs;
    }
    int le = 0;
    {
        for (auto& a : mat[i]) {
            if (a == pr)continue;
            le += rec(a, 0, i);
        }
    }
    ret = max(take, le);
    return ret;
}


void solve() {
    cin >> n >> c;
    gold.clear();
    mat.clear();
    gold.resize(n + 1);
    mat.resize(n + 1);
    for (int i = 1; i <= n; i++)cin >> gold[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        memset(dp[i], -1, sizeof dp[i]);
    }

    cout << rec() << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
//



