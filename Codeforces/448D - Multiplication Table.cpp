#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'


ll solve(ll n, ll m, ll r) {
    r--;
    ll an = 0;
    for (int i = 1; i <= n; i++) {
        an += min(m, r / i);
    }
    return an;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {

        ll n, m, k;
        cin >> n >> m >> k;
        ll st = 1, en = 250000000000;
        while (st <= en) {
            ll mid = (st + en) >> 1;
            ll r = solve(n, m, mid);
            if (r < k)st = mid + 1;
            else en = mid - 1;
        }
        cout << en;
    }

}
//






