#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 1000000007;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'

//nice impelementation & greedy one

int n, p;
string s;
int ans = 0;
int bl = -1, al = -1;
void  befr(int st) {
    for (int i = st; i >= bl; i--) {
        if (s[i] != s[n - i - 1]) {
            char cm, cx;
            if (s[i] > s[n - i - 1])cm = s[n - i - 1], cx = s[i];
            else cx = s[n - i - 1], cm = s[i];
            ans += abs(min((cx - cm), (('z' - cx) + (cm - 'a') + 1)));
            s[i] = s[n - i - 1];
        }
        ans += (i != st);
    }
}
void aftr(int st) {
    for (int i = st; i <= al; i++) {
        if (s[i] != s[n - i - 1]) {
            char cm, cx;
            if (s[i] > s[n - i - 1])cm = s[n - i - 1], cx = s[i];
            else cx = s[n - i - 1], cm = s[i];
            ans += abs(min((cx - cm), (('z' - cx) + (cm - 'a') + 1)));
            s[i] = s[n - i - 1];
        }
        ans += (i != st);
    }
}
void solve() {
    cin >> n >> p;
    cin >> s;
    p--;
    if (p >= (n + 1) / 2) {
        p = n - p - 1;
    }
    bool b = 0, a = 0;
    for (int i = p; i < (n + 1) / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            a = 1;
            al = i;
        }
    }
    for (int i = p; i >= 0; i--) {
        if (s[i] != s[n - i - 1]) {
            b = 1;
            bl = i;
        }
    }
    if (a && b) {
        if (abs(p - al) > abs(p - bl)) {
            befr(p);
            aftr(bl);
        }
        else {
            aftr(p);
            befr(al);
        }
    }
    else if (b) {
        befr(p);
    }
    else aftr(p);
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

//



