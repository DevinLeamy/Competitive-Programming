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

ll mod = 1000000007ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int x; string s; cin >> x >> s;
		vector<int> next;
		ll cur_len = (int) s.length();
		for (int i = 0; i < (int) s.length(); i++)
			next.pb(s[i] - '0');
		for (ll mark = 1; mark <= x; mark++) {
			ll rem = (cur_len - mark + mod) % mod;
			if (mark - 1 >= next.size()) // This is guaranteed to always be false
				break;
			ll added = next[mark - 1] - 1;
			for (ll idx = 0; idx < min((ll)x, (added * rem) % mod); idx++) {
				if (next.size() >= x)
					break;
				next.pb(next[mark + idx % rem]);
			}
			cur_len = (cur_len + (rem * added) % mod) % mod;
		}
		cout << cur_len << endl;
	}
	return 0;
}
