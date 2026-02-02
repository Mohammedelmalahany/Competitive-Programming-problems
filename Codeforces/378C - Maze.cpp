#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define ll long long
#define int long long

const int INF = INT32_MAX;
const ll MOD = 1e9 + 7;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'
int n, m, k;
vector<vector<bool>> vis;
vector<vector<bool>> taken;
vector<string> v;
int r[4] = { 0, 0, 1, -1 };
int c[4] = { 1, -1, 0, 0 };
bool isvalid(int i, int j) {
    return ((i >= 0 && i < n) && (j >= 0 && j < m));
}
void dfs(int i, int j, int& ret) {
    if (vis[i][j] || v[i][j] != '.')return;
    vis[i][j] = 1;
    ret++;
    for (int rr = 0; rr < 8; rr++) {
        if (isvalid(i + r[rr], j + c[rr])) {
            dfs(i + r[rr], j + c[rr], ret);
        }
    }
}
void dfs2(int i, int j) {
    if (taken[i][j] || v[i][j] != '.')return;
    if (k == 0)return;
    taken[i][j] = 1;
    k--;
    for (int rr = 0; rr < 4; rr++) {
        if (isvalid(i + r[rr], j + c[rr])) {
            dfs2(i + r[rr], j + c[rr]);
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    v.resize(n);
    vis.resize(n, vector<bool>(m));
    taken.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
        cin >> v[i];
    map<pair<int, int>, int>nodes;
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ret = 0;
            dfs(i, j, ret);
            if (ret)nodes[{i, j}] = ret, total += ret;
        }
    }
    k = total - k;
    set< pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>> > par;
    for (auto& a : nodes) {
        par.insert({ a.second,{a.first} });
    }
    for (auto& a : par) {
        int i = a.second.first;
        int j = a.second.second;
        dfs2(i, j);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!taken[i][j] && v[i][j] == '.')cout << 'X';
            else cout << v[i][j];
        }
        cout << el;
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



