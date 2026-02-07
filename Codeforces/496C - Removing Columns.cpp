#include <bits/stdc++.h>

using namespace std;
//just brute force dont try greedy
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<string>v(n + 1);
    for (int i = 0; i < n; i++)cin >> v[i];
    map<int, bool>ma;
    int ans = 0;
    bool b = 0;
    for (int i = 0; i < n - 1; i = b ? 0 : i + 1) {
        b = 0;
        for (int j = 0; j < m; j++) {
            if (ma[j])continue;
            if (v[i][j] == v[i + 1][j])continue;
            if (v[i][j] < v[i + 1][j])break;
            ma[j] = 1;
            b = 1;
            ans++;
            break;
        }
    }
    cout << ans;
    return 0;
}


//



