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
    int n, k; cin >> n >> k;
    int nn = n;
    int s = 1;
    map<int, bool >m;
    int i = 2;
    cout << 1 << ' ';
    m[1] = 1;
    bool b = 0;
    int ls = 1;
    while (k > 1) {
        if (b) {
            m[i] = 1;
            ls = i;
            cout << i++ << ' ';
            b = 0;
        }
        else {
            m[n] = 1;
            ls = n;
            cout << n-- << ' ';
            b = 1;
        }
        k--;
    }

    while (m[ls - 1] == 0 || m[ls + 1] == 0) {
        if (m[ls + 1] == 0 && ls + 1 <= n)cout << ++ls << ' ';
        if (m[ls - 1] == 0 && ls - 1 > 0)cout << --ls << ' ';
        if (ls + 1 > nn || ls - 1 <= 0)return;
        m[ls] = 1;
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






