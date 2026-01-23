#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

//idea we consider the number of odds and evens remain and last parity then the recursion do the work
int dp[101][51][51][3];
int n;
vector<int > v(101);
int rec(int i, int n1, int n2, int k2) {
    if (i == n)return 0;
    int& ret = dp[i][n1][n2][k2];
    if (~ret)return ret;
    ret = 0;
    if (v[i]) {
        int cur = v[i] & 1;
        ret = rec(i + 1, n1, n2, (v[i] % 2));
        if (k2 == 1 && !(v[i] & 1))ret += 1;
        if (!k2 && (v[i] & 1))ret += 1;
    }
    else {
        if (n1 > 0 && n2 > 0) {
            ret = min(rec(i + 1, n1, n2 - 1, 1) + (k2 == 0),
                rec(i + 1, n1 - 1, n2, 0) + (k2 == 1));
        }
        else if (n1 <= 0 && n2 > 0) {
            ret = rec(i + 1, n1, n2 - 1, 1) + (k2 == 0);
        }
        else if (n1 > 0 && n2 <= 0) {
            ret = rec(i + 1, n1 - 1, n2, 0) + (k2 == 1);
        }
    }
    return ret;
}


void solve(int c) {
    cin >> n;
    int odd = ((n + 1) / 2), even = (n / 2);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (!v[i])continue;
        if (v[i] % 2 == 1)odd--;
        else even--;
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, even, odd, 2);
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




