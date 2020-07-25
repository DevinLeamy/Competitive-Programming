#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
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
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		int a;
		vector<int> vals;
		for (int i = 0; i < n; i++) { cin >> a; vals.pb(a); }
		
		vector<string> ans;
		ans.pb("");
		for (int j = 0; j < 50; j++) {
			ans[0] += 'a';
		}
		for (int i = 0; i < n; i++) {
			string next = ans[i];
			ans.pb(next.substr(0, vals[i]));
			if (next[vals[i]] == 'a') {
				ans[i+1] += 'b';
			} else {
				ans[i+1] += 'a';
			}
			for (int j = 0; j < 50; j++) {
				ans[i+1] += 'a';
			}
		}
		for (string val : ans) {
			cout << val << endl;
		}
	}
	return 0;
}
