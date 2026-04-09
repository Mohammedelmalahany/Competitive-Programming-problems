#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
//#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<bool>v(n + 1);
    int cur = 1;
    v[1] = 1;
    vector<int> ans;
    ans.push_back(1);
    for (int i = k; i > 0; i--) {
        if (cur <= i) {
            if (!v[cur + i]) {
                v[cur + i] = 1;
                ans.push_back(cur + i);
                cur = cur + i;
            }

        }
        else {
            if (!v[cur - i]) {
                v[cur - i] = 1;
                ans.push_back(cur - i);
                cur = cur - i;
            }
            else if (!v[cur + i]) {
                v[cur + i] = 1;
                ans.push_back(cur + i);
                cur += i;
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        if (!v[i])ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ';
    return 0;
}//