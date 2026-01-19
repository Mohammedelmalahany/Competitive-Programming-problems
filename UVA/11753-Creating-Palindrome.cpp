#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

vector <int > v;
int k;
int generalrangestyle(int i, int j, int s) {
    if (s > k)return s;
    if (i >= j) {
        return s;
    }

    if (v[i] == v[j]) {
        return generalrangestyle(i + 1, j - 1, s);
    }
    return min(generalrangestyle(i, j - 1, s + 1), generalrangestyle(i + 1, j, s + 1));

}

void solve(int c) {
    int n; cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ou = generalrangestyle(0, n - 1, 0);
    if (ou > k)cout << "Case " << c << ": Too difficult" << el;
    else if (ou == 0)cout << "Case " << c << ": Too easy" << el;
    else cout << "Case " << c << ": " << ou << el;
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




