#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'



struct Trie {
    bool end;
    Trie* child[10];

    Trie() {
        end = false;
        memset(child, 0, sizeof(child));
    }
};

bool insert(Trie* root, const string& s) {
    Trie* cur = root;

    for (char c : s) {
        int d = c - '0';

        if (!cur->child[d])
            cur->child[d] = new Trie();

        cur = cur->child[d];

        if (cur->end)
            return false;
    }

    for (int i = 0; i < 10; i++) {
        if (cur->child[i])
            return false;
    }

    cur->end = true;
    return true;
}

void solve(int c) {
    int n;
    cin >> n;

    Trie* trie = new Trie();
    bool b = true;

    while (n--) {
        string s;
        cin >> s;

        if (b) {
            if (!insert(trie, s))
                b = false;
        }
    }

    if (b)
        cout << "YES\n";
    else cout << "NO\n";

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




