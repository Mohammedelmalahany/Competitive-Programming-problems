#include <bits/stdc++.h>


using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 1000000007;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int n, k;
string ans;
string in;
int dp[1001][1001][4];
int rec(int i, int dif, int state, string& s) {
    if (i == n) {
        if (dif == k) {
            ans = s;
            return 1;
        }
        return 0;
    }

    int& ret = dp[i][dif][state];
    if (~ret)return ret;
    if (dif == k)return ret = 0;
    ret = 0;
    //state 0 for w, 1 for l, 2 for drow
    //try win
    {
        if (in[i] == '?' || in[i] == 'W') {
            string t = s + 'W';
            bool w = 0;
            if (state == 1) {
                if (dif - 1 > 0)w |= rec(i + 1, dif - 1, 1, t);
                else if (dif - 1 == 0)w |= rec(i + 1, dif - 1, 2, t);
                else w |= rec(i + 1, 1, 0, t);
            }
            else {
                w |= rec(i + 1, dif + 1, 0, t);
            }
            if (in[i] == 'W')return ret = w;
            ret |= w;
        }
    }
    //try lose
    {
        if (in[i] == '?' || in[i] == 'L') {
            string t = s + 'L';
            bool l = 0;
            if (state == 0) {
                if (dif - 1 > 0)l |= rec(i + 1, dif - 1, 0, t);
                else if (dif - 1 == 0)l |= rec(i + 1, dif - 1, 2, t);
                else l |= rec(i + 1, 1, 1, t);
            }
            else l |= rec(i + 1, dif + 1, 1, t);
            if (in[i] == 'L')return ret = l;
            ret |= l;
        }
    }
    //try drow
    {
        if (in[i] == '?' || in[i] == 'D') {
            bool d = 0;
            string t = s + 'D';
            d |= rec(i + 1, dif, state, t);
            if (in[i] == 'D')return ret = d;
            ret |= d;
        }
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    cin >> in;
    memset(dp, -1, sizeof(dp));
    string s = "";
    int ret = rec(0, 0, 2, s);
    if (ret == 0)cout << "NO";
    else cout << ans;
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




