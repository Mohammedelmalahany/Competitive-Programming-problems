#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int x, y;
int n, m;
vector<string> mat;
int ans = 0;
void no_dfs(int s, int ss) {
    int r = x, c = y;
    while ((s + r) >= 0 && (s + r) < n && (c + ss) >= 0 && (c + ss) < m) {
        r += s, c += ss;
        if (mat[r][c] == '#')return;
        ans++;
    }
}
void solve() {
    cin >> n >> m;
    cin >> x >> y;
    mat.resize(n);
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    --x, --y;
    no_dfs(1, 0);
    no_dfs(-1, 0);
    no_dfs(0, 1);
    no_dfs(0, -1);
    cout << ++ans;

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