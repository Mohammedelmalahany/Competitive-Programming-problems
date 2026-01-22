#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

int n;
int dp[201][201][201];
string s;
string t;
int rec(int i, int ts, int r) {


    if (r == 0) {
        if (i == n)return 0;
        return(ts * (s[i] == t[1])) + rec(i + 1, s[i] == t[0] ? ts + 1 : ts, r);
    }
    if (i == n)return 0;
    int& ret = dp[i][ts][r];
    if (~ret)return ret;
    int pt1 = 0;
    int pt2 = 0;
    int nth = 0;
    int pl = 0;
    if (s[i] == t[1])pl += ts;
    int c = ts;
    if (s[i] == t[0])c++;

    if (s[i] == t[0]) pt1 = pl + rec(i + 1, ts + 1, r);
    else pt1 = rec(i + 1, ts + 1, r - 1);

    if (s[i] == t[1]) pt2 = ts + rec(i + 1, ts, r);
    else {
        pt2 = ts + rec(i + 1, t[0] == t[1] ? ts + 1 : ts, r - 1);
    }

    if (s[i] == t[0] && s[i] == t[1]) {
        ret = max(ret, ts + rec(i + 1, ts + 1, r));
    }
    if (s[i] != t[0] && s[i] != t[1]) {
        nth = rec(i + 1, ts, r);
    }
    return ret = max(pt1, max(pt2, nth));
}

void solve(int c) {
    int k; cin >> n >> k;
    cin >> s >> t;

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, k);
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






