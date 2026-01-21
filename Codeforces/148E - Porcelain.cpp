#include <bits/stdc++.h>


using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

int dp[101][10001];
int n, m;
vector<vector<int>> v;
vector<vector<int>> calc;
int rec(int i, int rem) {
    if (rem == 0)return 0;
    if (i == n)return 0;
    int& ret = dp[i][rem];
    if (~ret)return ret;
    for (int l = 0; l < calc[i].size(); l++) {
        if (l <= rem)
            ret = max(ret, rec(i + 1, rem - l) + calc[i][l]);
    }
    return ret;
}

void solve(int c) {
    cin >> n >> m;
    int ls1 = 0;
    v = vector<vector<int>>(n);
    calc = vector<vector<int>>(n);

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = 0; j < a; j++) {
            int k; cin >> k;
            v[i].push_back(k);
        }
        vector<int> pre(a);
        vector<int > suf(a);
        pre[0] = v[i][0];
        for (int l = 1; l < a; l++)pre[l] = pre[l - 1] + v[i][l];
        suf[a - 1] = v[i][a - 1];
        for (int l = a - 2; l >= 0; l--)suf[l] = suf[l + 1] + v[i][l];
        calc[i].resize(a + 1);
        for (int t = 1; t <= a; t++) {
            calc[i][t] = max(pre[t - 1], suf[a - t]);
            for (int tt = 1; tt < t; tt++) {
                calc[i][t] = max(calc[i][t],
                    pre[tt - 1] + suf[a - ((t - tt))]);
            }
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << rec(0, m);
}



int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        solve(i);
        i++;
    }
}
//





