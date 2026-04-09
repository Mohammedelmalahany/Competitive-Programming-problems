#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    vector<int> s = v;
    sort(all(s));
    int c = -1;
    int g = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != v[i]) {
            int idx = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == v[j]) {
                    idx = j;
                }
            }
            swap(v[idx], v[i]);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != v[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}//