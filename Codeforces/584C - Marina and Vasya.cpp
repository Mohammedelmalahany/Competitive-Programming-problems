#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d; cin >> n >> d;
    int m = n - d;
    string s1; cin >> s1;
    string s2; cin >> s2;
    vector<char>ans(n);
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i] && m) {
            ans[i] = s1[i];
            m--;
        }
    }
    int m1 = m, m2 = m;
    int d1 = 0, d2 = 0;

    for (int i = 0; i < n; i++) {
        if ((int)ans[i])continue;
        if (s1[i] != s2[i] && m1) {
            ans[i] = s1[i];
            m1--;
            d2 += (s2[i] != ans[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if ((int)ans[i]) {
            continue;
        }
        if (s2[i] != s1[i] && m2) {
            ans[i] = s2[i];
            m2--;
            d1 += (ans[i] != s1[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if ((int)ans[i])continue;
        for (int c = 0; c < 26; c++) {
            if ('a' + c != s1[i] && c + 'a' != s2[i]) {
                ans[i] = 'a' + c;
                d1++, d2++;
                break;
            }
        }
    }
    if (d1 > d || d2 > d) {
        cout << -1;
        return 0;
    }
    for (char a : ans)cout << a;

    return 0;
}
//