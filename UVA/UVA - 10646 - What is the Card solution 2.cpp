#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

int value(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    return 10;
}

void solve(int c) {
    vector<string> v(52);
    for (int i = 0; i < 52; i++) cin >> v[i];


    int top = 51;
    vector<string> hand;

    for (int i = 0; i < 25; i++) {
        hand.push_back(v[top--]);
    }

    int Y = 0;

    for (int i = 0; i < 3; i++) {
        int X = value(v[top][0]);
        Y += X;
        top -= (10 - X + 1);
    }

    for (int i = hand.size() - 1; i >= 0; i--) {
        v[++top] = hand[i];
    }

    cout << "Case " << tc << ": " << v[Y - 1] << "\n";


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