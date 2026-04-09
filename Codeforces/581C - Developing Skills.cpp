#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector<vector<int>> rem(11);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        rem[10 - (a % 10)].push_back(a);
    }
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (auto a : rem[i]) {
            if (k >= i) {
                v.push_back(a + i);
                k -= i;
            }
            else v.push_back(a);
        }
    }
    for (auto a : rem[10])v.push_back(a);
    int s = 0;
    for (int i = 0; i < n; i++) {
        int p = min(100 - v[i], k);
        v[i] += p;
        k -= p;
        s += (v[i] / 10);
    }
    cout << s;
    return 0;
}//