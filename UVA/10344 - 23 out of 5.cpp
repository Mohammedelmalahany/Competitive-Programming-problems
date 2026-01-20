#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX; const ll MOD = 1000000007;
const int MAX = 10001;
#define ull unsigned ll
#define el '\n'

vector<int> v(6);
vector<bool> vis(5);
vector<int> arr;
bool flag = 0;
bool _23outof5(int i, int num) {
    if (i == 4) {
        return (num == 23);
    }
    return _23outof5(i + 1, num + arr[i + 1]) ||
        _23outof5(i + 1, num - arr[i + 1]) ||
        _23outof5(i + 1, num * arr[i + 1]);
}
void createarr(int i) {

    if (i == 5) {
        flag = _23outof5(0, arr[0]);
        return;
    }
    for (int j = 0; j < 5; j++) {
        if (!vis[j]) {
            arr.push_back(v[j]);
            vis[j] = 1;
            createarr(i + 1);
            if (flag)return;
            arr.pop_back();
            vis[j] = 0;
        }
    }
}

void solve(int c) {
    while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4]) {
        if (v[0] == 0 && v[1] == 0 && v[2] == 0 && v[3] == 0 && v[4] == 0) {
            return;
        }
        arr.clear();
        fill(vis.begin(), vis.end(), 0);
        flag = 0;
        createarr(0);
        if (flag) {
            cout << "Possible\n";
        }
        else cout << "Impossible\n";
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



