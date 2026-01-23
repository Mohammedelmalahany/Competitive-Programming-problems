#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

unordered_map<int, vector<int>> um;
vector<vector<int>> adj(2 * 100002);
int total = 0;
map < pair<int, int>, bool> ro;
vector<int >ans(2 * 100002);
int mi = INF;
void rec(int i, int p) {
    if (ro[{i, p}])total++;
    for (int t : adj[i]) {
        if (t != p) {
            rec(t, i);
        }
    }
}
void solve(int i, int p, int up1, int dis) {
    if (ro[{i, p}])up1++;
    ans[i] = (total - up1) + (dis - up1);
    um[ans[i]].push_back(i);
    mi = min(mi, ans[i]);
    for (auto t : adj[i]) {
        if (t != p) {
            solve(t, i, up1, dis + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            ro[{a, b}] = 1;
        }
        rec(1, 0);
        solve(1, 0, 0, 0);
        cout << mi << el;
        sort(um[mi].begin(), um[mi].end());
        for (auto t : um[mi])cout << t << " ";
    }
}







