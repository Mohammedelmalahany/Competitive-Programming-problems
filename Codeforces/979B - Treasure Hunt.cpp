#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int i = 3;
    vector<int> mx(4);
    unordered_map<int, string> ma = { {0,"Kuro"},{1,"Shiro"},{2,"Katie"} };
    int m = 0;
    string ans;
    while (i--) {
        string s; cin >> s;
        vector<int> l(26);
        vector<int> u(26);
        for (int c = 0; c < s.size(); c++) {
            if (s[c] >= 'a' and s[c] <= 'z') {
                l[s[c] - 'a']++, mx[2 - i] = max(l[s[c] - 'a'], mx[2 - i]);
            }
            else {
                u[s[c] - 'A']++, mx[2 - i] = max(u[s[c] - 'A'], mx[2 - i]);
            }
        }
        if (n == 1 && mx[2 - i] == (int)s.size())s.pop_back();
        mx[2 - i] = min(mx[2 - i] + n, (int)s.size());
        if (mx[2 - i] > m)m = mx[2 - i], ans = ma[2 - i];
    }
    i = 0;
    if (mx[0] == m)i++;
    if (mx[1] == m)i++;
    if (mx[2] == m)i++;
    if (i > 1)cout << "Draw";
    else cout << ans;

    return 0;
}
//
