#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll add(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subtract(ll a, ll b) { return (a % MOD - b % MOD + MOD) % MOD; }
ll fastPower(ll base, ll power) {
    if (!power) return 1;
    ll hp = fastPower(base, power / 2);
    ll fullPower = mul(hp, hp);
    if (power % 2)
        fullPower = mul(base, fullPower);
    return fullPower;
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll inv(ll a) { return fastPower(a, MOD - 2); }
ll divi(ll a, ll b) { return mul(a, inv(b)); }

void solve() {

}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        int n; cin >> n;
        int x; cin >> x;
        vector<int> a(n);
        bool f = 0;

        for (int i = 0; i < n; i++)cin >> a[i];
        if (n == 0)f = x == 0 ? 1 : 0;
        if (n == 1)
            if (a[0] == x)f = 1;
        if (n > 1) {
            int s = accumulate(a.begin(), a.end(), 0);
            if (s + (n - 1) == x)f = 1;
        }
        if (f)cout << "YES\n";
        else cout << "NO\n";

    }

}







