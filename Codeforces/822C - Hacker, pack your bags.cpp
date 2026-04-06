#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long
//you could simply search for l only and it is valid too 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<vector<int>> days(n, vector<int>(3));
    int s = 2e5 + 1;
    vector<vector<pair<int, int>>> lsor(s);
    vector<vector<pair<int, int>>> rsor(s);
    vector<vector<int>> sufl(s);
    vector<vector<int>> sufr(s);

    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        int len = r - l + 1;
        if (len < s) {
            lsor[len].push_back({ l, c });
            rsor[len].push_back({ r, c });
        }
        days[i][0] = l; days[i][1] = r; days[i][2] = c;
    }
    for (int i = 1; i < s; i++) {
        if (lsor[i].empty()) continue;
        sort(all(lsor[i]));
        sort(all(rsor[i]), greater<pair<int, int>>());
        int sz = lsor[i].size();
        sufl[i].resize(sz);
        sufr[i].resize(sz);
        sufl[i][sz - 1] = lsor[i][sz - 1].second;
        sufr[i][sz - 1] = rsor[i][sz - 1].second;
        for (int j = sz - 2; j >= 0; j--) {
            sufl[i][j] = min(sufl[i][j + 1], lsor[i][j].second);
            sufr[i][j] = min(sufr[i][j + 1], rsor[i][j].second);
        }
    }
    int ans = 1e13;
    for (int i = 0; i < n; i++) {
        int len = days[i][1] - days[i][0] + 1;
        int idx = x - len;
        if (idx == 0) {
            continue;
        }
        if (idx < 0 || lsor[idx].empty()) continue;
        auto it = lower_bound(all(lsor[idx]), make_pair(days[i][1] + 1, -1LL));
        if (it != lsor[idx].end()) {
            int pos = distance(lsor[idx].begin(), it);
            ans = min(ans, days[i][2] + sufl[idx][pos]);
        }
        auto it2 = lower_bound(all(rsor[idx]), make_pair(days[i][0] - 1, 1e13), greater<pair<int, int>>());
        if (it2 != rsor[idx].end()) {
            int pos2 = distance(rsor[idx].begin(), it2);
            ans = min(ans, days[i][2] + sufr[idx][pos2]);
        }
    }
    if (ans != 1e13) {
        cout << ans << el;
    }
    else {
        cout << -1 << el;
    }

    return 0;
}//
