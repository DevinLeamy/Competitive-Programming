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
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<bool> has(26);
	for (int i = 0; i < k; i++) {
		char c; cin >> c;
		has[c - 'a'] = true;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll cnt = 0;
		while (i != n && has[s[i] - 'a']) {
			cnt++;
			i++;
		}
		ans += cnt * (cnt + 1) / 2;
	}
	cout << ans << endl;
	return 0;
}
