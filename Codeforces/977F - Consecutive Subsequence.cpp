#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 998244353;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

int n;
void rec(int i, vector<int>& s) {


}

void solve(int c) {
    cin >> n;
    map<int, int> dp;
    vector<int >v(n);
    int le = 0;
    int la = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        dp[v[i]] = dp[v[i] - 1] + 1;
        if (dp[v[i]] > le) {
            le = dp[v[i]];
            la = v[i];
        }
    }
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == la) {
            s.push(i);
            la--;
        }
    }
    cout << s.size() << el;
    int l = s.size();
    for (int i = 0; i < l; i++) {
        int a = s.top(); s.pop();
        cout << a + 1 << " ";
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





