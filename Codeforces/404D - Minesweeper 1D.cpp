#include <bits/stdc++.h>


using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 1000000007;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'
int n;
ll dp[1000001][6];
string v;
ll rec(int i, int state) {
    if (i == n) {
        if (state == 0 || state == 1 || state == 4) {
            return 1;
        }
        return 0;
    }
    ll& ret = dp[i][state];

    if (~ret)return ret;
    ret = 0;
    if (state == 0) {
        if (v[i] == '?')
            ret += rec(i + 1, 2) + rec(i + 1, 0);
        else if (v[i] == '1')ret += rec(i + 1, 2);
        else if (v[i] == '0')ret += rec(i + 1, 0);
    }
    else if (state == 1) {
        if (v[i] == '?') {
            ret += (rec(i + 1, 0) + rec(i + 1, 2));
        }
        else if (v[i] == '0')ret += rec(i + 1, 0);
        else if (v[i] == '1')ret += rec(i + 1, 2);
    }
    else if (state == 2) {
        if (v[i] == '?' || v[i] == '*') {
            ret += rec(i + 1, 4);
        }
    }
    else if (state == 3) {
        if (v[i] == '?' || v[i] == '*')
            ret += rec(i + 1, 4);
    }
    else if (state == 4) {
        if (v[i] == '?')ret += (rec(i + 1, 1) + rec(i + 1, 3) + rec(i + 1, 4));
        else if (v[i] == '1')ret += rec(i + 1, 1);
        else if (v[i] == '2')ret += rec(i + 1, 3);
        else if (v[i] == '*')ret += rec(i + 1, 4);
    }
    else if (state == 5) {
        if (v[0] == '?') {
            ret += rec(1, 0) + rec(1, 2) + rec(1, 4);
        }
        else if (v[i] == '0') ret += (rec(i + 1, 0));
        else if (v[i] == '1')ret += rec(i + 1, 2);
        else if (v[i] == '*')ret += rec(i + 1, 4);
    }
    return ret %= MOD;
}
void solve() {
    cin >> v;
    n = v.size();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 5);

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




