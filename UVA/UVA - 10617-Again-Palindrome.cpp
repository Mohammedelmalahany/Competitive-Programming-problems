#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'
string S;

ll dp[61][61];
ll AgainPalindrome(int i, int j) {
    if (i == j)return 1;
    if (i + 1 == j)return 2 + (S[i] == S[j]);
    ll& ret = dp[i][j];
    if (~ret)return ret;
    ret = 0;
    if (S[i] == S[j])
        ret += AgainPalindrome(i + 1, j - 1) + 1;
    ret += AgainPalindrome(i + 1, j);
    ret += AgainPalindrome(i, j - 1);
    ret -= AgainPalindrome(i + 1, j - 1);//called twice in last two calls
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    int i = 1;
    while (t--) {
        cin >> S;
        memset(dp, -1, sizeof(dp));
        cout << AgainPalindrome(0, S.size() - 1) << el;        i++;
    }
    return 0;
}




