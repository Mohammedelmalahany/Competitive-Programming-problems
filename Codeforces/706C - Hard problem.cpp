#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long
#define ll long long

const int INF = INT32_MAX;
const ll MOD = 1000000007;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int n;
vector<int>c;
vector<string> str;
vector<string> reversed;
int dp[100001][2];
int rec(int i, bool stbef) {
    if (i == n)return 0;
    int& ret = dp[i][stbef];
    if (~ret)return ret;
    string par = !stbef ? str[i - 1] : reversed[i - 1];
    ret = 1e18;
    if (str[i] >= par) {
        ret = min(rec(i + 1, 0), ret);
    }
    if (reversed[i] >= par) {
        ret = min(ret, rec(i + 1, 1) + c[i]);
    }
    return ret;
}
void solve() {
    cin >> n;
    c.resize(n + 1);
    str.resize(n + 1);
    reversed.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        reversed[i] = str[i];
        reverse(reversed[i].begin(), reversed[i].end());
    }
    for (int i = 0; i < n; i++) {
        memset(dp[i], -1, sizeof dp[i]);
    }
    int ret = min(rec(1, 1) + c[0], rec(1, 0));
    ret = (ret == 1e18) ? -1 : ret;
    cout << ret << el;
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


