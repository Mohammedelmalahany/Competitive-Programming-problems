#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

void solve(int c) {
    string v;
    string ans;
    int n = 0;
    for (int i = 0; i < 52; i++) {
        cin >> v;
        if (i == 32) {
            ans = v;
        }
    }
    cout << "Case " << c << ": ";
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    int i = 1;
    while (t--) {
        solve(i);
        i++;
    }
}
//



