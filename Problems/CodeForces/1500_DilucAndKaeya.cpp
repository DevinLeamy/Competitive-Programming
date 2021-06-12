#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) while(h--)
#define view(h) cout<<"DEBUG: " << h << endl
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int n;
vector<int> ans(500001);
void solve() {
	cin >> n;
	string s; cin >> s;
	int k = 0, d = 0;
	vector<PL> presum;
	map<PI, int> cnts;
	presum.pb({0, 0});
	for (int i = 0; i < n; i++) {
		if (s[i] == 'K')
			k++;
		else
			d++;
		presum.pb({k, d});
		int g = gcd(k, d);
		ll new_k = (d == 0)? 1 : k / g;
		ll new_d = (k == 0)? 1 : d / g;
		cnts[{new_k, new_d}] += 1;
		ans[i] = cnts[{new_k, new_d}];
		
//		ll len = new_k + new_d;
//		if (len == 1) {
//			ans[i] = i + 1;
//			continue;
//		}
//		if ((i + 1) % len != 0 || len == i + 1) {
//			ans[i] = 1;
//			continue;
//		}
//		ll cur_k = 0;
//		ll cur_d = 0;
//		int cnt = 0;
//		int last = 0;
//		for (int j = (int) len; j <= i + 1; j += len) {
//			cur_k += presum[j].first - presum[last].first;
//			cur_d += presum[j].second - presum[last].second;
//			if (cur_k * new_d == cur_d * new_k) {
//				cnt++;
//				cur_k = 0;
//				cur_d = 0;
//			}
//			last = j;
//		}
//		ans[i] = max(1, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		solve();
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
