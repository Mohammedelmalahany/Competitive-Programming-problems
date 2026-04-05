#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
#define int long long
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    int i = 1;
    while (cin >> a >> b) {
        bool an = 1;
        if (b == 0) {
            cout << b << " does not divide " << a << "!" << el;
            continue;
        }
        int ff = a;
        a = max(1ll, a);
        int t = b;
        vector<pair<int, int>> fac;
        for (int i = 2; i * i <= t; i++) {
            int fr = 0;
            while (t % i == 0) {
                fr++;
                t /= i;
            }
            if (fr)fac.push_back({ i,fr });
        }
        if (t > 1)fac.push_back({ t,1 });
        for (int i = 0; i < fac.size(); i++) {
            auto p = fac[i];
            int pow = p.first;
            while (p.second > 0) {
                if (pow > a) { an = 0; break; }
                p.second -= a / pow;
                pow *= p.first;
            }
            if (!an)break;
        }
        if (an)
            cout << b << " divides " << ff << "!" << endl;
        else cout << b << " does not divide " << ff << "!" << el;
    }
    return 0;
}
//
