#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define all(v) v.begin(), v.end()
#define el '\n'
bool cmp(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second)return a.first < b.first;
    return a.second > b.second;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string me; cin >> me;
    int n; cin >> n;
    unordered_map<string, int > actions;
    actions["posted"] = 15, actions["likes"] = 5, actions["commented"] = 10;
    unordered_map<string, int> m;
    while (n--) {
        string s1; cin >> s1;
        string a; cin >> a;
        if (a != "likes") {
            string l; cin >> l;
        }
        string s2; cin >> s2;
        s2 = s2.substr(0, s2.size() - 2);
        string t; cin >> t;
        if (s1 == me || s2 == me) {
            m[s1] += (s1 != me ? actions[a] : 0);
            m[s2] += (s2 != me ? actions[a] : 0);
        }
        else {
            m[s1] += 0;
            m[s2] += 0;
        }
    }
    vector<pair<string, int>> v;
    for (auto& a : m) {
        v.push_back({ a.first,a.second });
    }
    sort(all(v), cmp);
    for (auto a : v)if (a.first != me)cout << a.first << el;

    return 0;
}
//