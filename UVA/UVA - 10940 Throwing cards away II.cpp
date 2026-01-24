#include <bits/stdc++.h>


using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    int i = 1;
    while (t--) {
        vector<int> v(500020);
        v[1] = 1;
        v[2] = 2;
        int j = 2;
        for (int i = 3; i <= 500000; i++) {
            if (i < j) j = 2;
            v[i] = j;
            j += 2;
        }
        int n;
        while (cin >> n) {
            if (n == 0)break;
            cout << v[n] << el;
        }

    }
}
//





