#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

int n;
vector < vector<int >> adj;
vector<int > lis;
vector<int>a;
vector<int> ans;
void solve(int i, int p) {
    int pos = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
    int ov = (pos < lis.size() ? lis[pos] : -1);
    bool b = 0;
    if (ov == -1) {
        lis.push_back(a[i]);
        b = 1;
    }
    else lis[pos] = a[i];
    ans[i] = lis.size();
    for (int t : adj[i]) {
        if (t != p)solve(t, i);
    }
    if (ov == -1)lis.pop_back();
    else lis[pos] = ov;
}



int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        cin >> n;
        a.assign(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            cin >> a[i];
        }
        adj.assign(n + 1, vector<int>(3, 0));
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans.assign(n + 1, 0);
        solve(1, 1);
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << el;
        i++;
    }
}
//






