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

string alp = "abcdefghijklmnopqrstuvwxyz";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n, k, cur = 0; cin >> n >> k;
		string s; cin >> s;
		vector<int> val(26); vector<string> ans(k); vector<string> ans1(k);
		for (int i = 0; i < n; i++) { val[s[i] - 'a']++; }
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < val[i]; j++) {
				if (ans1[cur].length() > 0) { ans1[0] += alp[i]; }
				else { ans1[cur] += alp[i]; }
				ans[cur] += alp[i];
				cur = (cur + 1)%k;
			}
		}
		sort(ans.begin(), ans.end());
		sort(ans1.begin(), ans1.end());
		cout << std::min(ans[k-1], ans1[k-1]) << endl;
	}
	return 0;
}
