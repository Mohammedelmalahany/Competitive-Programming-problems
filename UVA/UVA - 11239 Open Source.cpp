#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'


bool cmp(pair<string, int> a, pair < string, int>b) {
    if (a.second != b.second)return a.second > b.second;
    return a.first < b.first;
}
void solve() {
    while (true) {
        string sh;
        string sd;
        string in;
        unordered_map <string, int>shee;
        unordered_map <string, bool> words;
        unordered_map <string, string>sign;
        string psh;

        while (true) {
            getline(cin, in);
            if (in == "1" || in == "0")break;
            if (in[0] < 'a') {
                shee[in] = 0;
                psh = in;
                continue;
            }
            if (sign[in] != "") {
                if (psh != sign[in] && words[in] == 0) {
                    shee[sign[in]]--;
                    words[in] = 1;
                }
            }
            else {
                sign[in] = psh;
                shee[psh]++;
            }
        }
        vector<pair<string, int>> out;
        for (auto& a : shee) {
            out.push_back({ a.first, a.second });
        }
        sort(out.begin(), out.end(), cmp);
        for (auto& a : out) {
            cout << a.first << ' ' << a.second << el;
        }
        if (in == "0")break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
//



