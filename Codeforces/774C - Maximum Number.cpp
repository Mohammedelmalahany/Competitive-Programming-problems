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

void solve(int i, int p, int up1, int dis) {

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        int n; cin >> n;
        vector<int> v(10);
        v[1] = 0, v[2] = 1, v[3] = 7, v[4] = 4, v[5] = 5, v[6] = 9;
        string s = "";
        int i = 2;
        int f = n;
        while (n >= 2) {
            n -= i;
            s = char('0' + v[i]) + s;
        }
        if (f & 1)s[0] = '7';

        cout << s;
    }
}
//






