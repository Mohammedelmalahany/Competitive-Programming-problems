#include <bits/stdc++.h>

using namespace std;

#define int long long
#define el '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

const int MOD = 1e9 + 7;
const int OFFSET = 250;
const int N = 200;
int n;
vector<int> v;
bool can(int p) {
    priority_queue<int> q;
    for (int i = 0; i < v.size(); i++)q.push(v[i]);
    vector<vector<int>>pls(p);
    while (true) {
        for (int i = 0; i < p; i++) {
            if (q.empty())
                return 1;
            bool b = 1;
            for (int j = 0; j < pls[i].size(); j++) {
                if (pls[i].size() - j <= pls[i][j])continue;
                return 0;
                break;
            }
            pls[i].push_back(q.top());
            q.pop();
        }
    }
}
signed main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(allr(v));
    int st = 1, en = n;
    int ans = n;
    while (st <= en) {
        int m = st + en >> 1;
        if (can(m)) {
            ans = m;
            en = m - 1;
        }
        else st = m + 1;
    }
    cout << ans;
    return 0;
}
//