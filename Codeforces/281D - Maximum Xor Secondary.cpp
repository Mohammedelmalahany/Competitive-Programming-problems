#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

int n;
int no_sparce_table(vector<int>& v) {
    int ret = -1;
    vector<int> sst;
    for (int i = 0; i < n; i++) {
        while (!sst.empty() && sst.back() < v[i])sst.pop_back();
        sst.push_back(v[i]);
        if (sst.size() >= 2) ret = max(ret, sst[sst.size() - 1] ^ sst[sst.size() - 2]);
    }
    return ret;
}
void solve() {
    cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    int ans = no_sparce_table(v);
    reverse(v.begin(), v.end());
    ans = max(ans, no_sparce_table(v));
    cout << ans;
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

//there is another solution for this problem using sparse table 
// by getting the closest max element to an element from its left and right
// by using binary search and update your mx element throw bs this cost (n * 2 * log(n)) and it is very risky to use segtre here 