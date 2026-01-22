#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'



void solve(int c) {
    ll n, k; cin >> n >> k;
    if (k == 0 || k == n) {
        cout << 0 << ' ' << 0;
        return;
    }
    cout << (k > 0 && k < n ? 1 : 0) << ' ';
    ll r = n % 3;
    ll m = (n / 3) + (r == 2);
    ll mx = (n / 3) * 2 + (r == 2);
    ll ans = 0;
    if (k * 3 < n) {
        cout << k * 2;
    }
    else {
        if (n % 3 == 0)
            cout << mx - (k - n / 3);
        else cout << mx - (k - 1 - (n / 3));
    }

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






