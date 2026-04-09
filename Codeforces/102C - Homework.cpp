#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define all(v) v.begin(), v.end()
//#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string ss; cin >> ss;
    int k; cin >> k;
    vector<int> s;
    for (int i = 0; i < ss.size(); i++)
        s.push_back(ss[i] - 'a' + 1);
    vector<pair<int, int>> ch(27);
    for (int i = 0; i < s.size(); i++) {
        ch[s[i]].first++;
        ch[s[i]].second = s[i];
    }
    sort(all(ch));
    vector<int> re;
    int dis = 0;
    for (int i = 0; i < 27; i++) {
        if (ch[i].second)dis++;
        if (k >= ch[i].first && ch[i].second) {
            k -= ch[i].first;
            re.push_back(ch[i].second);
        }
    }

    cout << dis - (int)re.size() << el;
    for (int i = 0; i < s.size(); i++) {
        bool b = 0;
        for (int j = 0; j < re.size(); j++)if (re[j] == s[i])b = 1;
        if (!b) {
            cout << (char)('a' + s[i] - 1);
        }
    }
    return 0;
}//