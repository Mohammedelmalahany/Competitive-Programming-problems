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


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        vector<vector<int>> v(5, vector<int>(5));
        bool b = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> v[i][j];
            }
            v[i][3] *= 3;
            int s = accumulate(v[i].begin(), v[i].end(), 0);
            if (s > 3)b = 1;
        }

        if ((v[0][3] && v[1][0]) || (v[0][3] && v[3][2]) || (v[0][3] && v[2][1])) {
            b = 1;
        }
        else if ((v[0][0] && v[3][3]) || (v[3][3] && v[2][2]) || (v[1][3] && v[3][1]))b = 1;
        else if ((v[1][3] && v[0][2]) || (v[1][3] && v[2][0]) || (v[2][3] && v[0][1]))b = 1;
        else if ((v[2][3] && v[3][0]) || (v[2][3] && v[1][2]) || (v[3][3] && v[1][1]))b = 1;
        if (b)cout << "YES\n";
        else cout << "NO\n";
    }

}
//






