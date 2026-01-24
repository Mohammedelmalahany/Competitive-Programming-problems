#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'
//idea is the maximum value we can obtain is i * n
//ans min is n-1 * n - k * (2n) 
//so i must be greater than or equal n-2k to be a value larger than min of n-1 * n 

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    int i = 1;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int > v(n);
        for (auto& a : v)cin >> a;
        ll ans = -INF;
        for (int i = max(0, n - 200); i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = max(ans, (1ll * (i + 1) * (j + 1)) - (k * (v[i] | v[j])));
        cout << ans << el;
    }
}
//






