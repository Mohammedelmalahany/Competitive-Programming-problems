#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'
int dp[100001];
int n;
vector<int>v;
bool rec(int k) {
    if (k <= 0)return 0;
    int& ret = dp[k];
    if (~ret)return ret;
    for (int i = 0; i < n; i++) {
        if (v[i] <= k) {
            if (!rec(k - v[i])) {
                return ret = 1;
            }
        }
    }
    return ret = 0;
}

void solve(int c) {
    int k;
    cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++)cin >> v[i];
    memset(dp, -1, sizeof(dp));
    if (rec(k)) {
        cout << "First\n";
    }
    else cout << "Second\n";

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




