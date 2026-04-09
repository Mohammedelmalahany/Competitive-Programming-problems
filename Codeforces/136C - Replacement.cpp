#include <bits/stdc++.h>

using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
//#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > v[mx])mx = i;
    }
    if (v[mx] != 1)
        v[mx] = 1;
    else v[mx] = 2;
    sort(all(v));
    for (int i = 0; i < n; i++)cout << v[i] << ' ';
    return 0;
}//