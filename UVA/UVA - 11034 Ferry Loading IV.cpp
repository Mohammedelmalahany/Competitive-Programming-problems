#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define ll long long
const int INF = INT32_MAX;
const ll MOD = 998244353;
const int MAX = 1e7 + 1;
#define ull unsigned ll
#define el '\n'


void solve() {
	double l, m; cin >> l >> m;
	queue<double> lf;
	queue<double>ri;
	for (int i = 0; i < m; i++) {
		double a; cin >> a;
		a /= 100;
		string s; cin >> s;
		if (s == "left") {
			lf.push(a);
		}
		else ri.push(a);
	}
	bool f = 1;
	int times = 0;
	while (!(lf.empty()) || !(ri.empty())) {
		double lo = l;
		if (f) {
			while (!(lf.empty())) {
				double t = lf.front();
				if (t > lo)break;
				lo -= t;
				lf.pop();
			}
			f = 0;
			times++;
		}
		else {
			while (!(ri.empty())) {
				double t = ri.front();
				if (t > lo)break;
				lo -= t;
				ri.pop();
			}
			f = 1;
			times++;
		}
	}
	cout << times << el;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
//






