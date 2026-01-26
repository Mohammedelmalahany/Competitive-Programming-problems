#include <bits/stdc++.h>


using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'




void solve() {

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<vector<int>> adjr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x) {
                adj[i].push_back(j);
                adjr[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> dis(n, -1);
        queue<int> q;
        dis[i] = adjr[i][i];
        if (dis[i]) {
            cout << dis[i] << el;
            continue;
        }
        q.push(i);
        int ans = INF;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& a : adj[u]) {
                if (dis[a] == -1) {
                    dis[a] = dis[u] + 1;
                    if (adjr[i][a])
                        ans = min(ans, dis[a] + 1);
                    q.push(a);
                }
            }
        }
        if (ans == INF)
            cout << "NO WAY\n";
        else
            cout << ans << "\n";

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



