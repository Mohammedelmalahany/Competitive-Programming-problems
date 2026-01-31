#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'
int n, m;
bool isvalid(int i, int j) {
    return ((i >= 0 && i < n) && (j >= 0 && j < m));
}
void solve() {
    while (cin >> n >> m) {
        if (m == 0 && n == 0)break;
        char sky[102][102];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> sky[i][j];
            }
        int ans = 0;
        int r[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
        int c[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (sky[i][j] == '.')continue;
                bool b = 0;
                for (int k = 0; k < 8; k++) {
                    int ro = i + r[k], cl = c[k] + j;
                    if (isvalid(ro, cl)) {
                        if (sky[ro][cl] == '*')b = 1;
                    }
                }
                ans += (!b);
            }
        cout << ans << el;
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



