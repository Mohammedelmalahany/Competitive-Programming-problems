#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

double dp[3000][3000];
int n;
vector<double> v;
double rec(int i, int heads) {
    if (i == n) {
        if (heads > (n / 2))return 1;
        else return 0;
    }
    double& ret = dp[i][heads];
    if (ret != -1)return ret;
    ret = v[i] * rec(i + 1, heads + 1) +
        (1 - v[i]) * rec(i + 1, heads);
    return ret;
}

void solve(int c) {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1.0;
    for (int i = 0; i < n; i++)cin >> v[i];
    cout << fixed << setprecision(10) << rec(0, 0);
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




