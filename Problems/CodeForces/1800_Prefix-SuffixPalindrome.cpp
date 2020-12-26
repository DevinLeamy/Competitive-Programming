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

int long_pal_pre(string s) {
	string _s = s; reverse(_s.begin(), _s.end());
	string s2 = s + "?" + _s;
	int n = (int) s2.length();
	vector<int> lps(n);
	for (int i = 1; i < n; i++) {
		int len = lps[i-1];
		while (len > 0 && s2[len] != s2[i]) {
			len = lps[len - 1];
		}
		if (s2[i] == s2[len]) len++;
		lps[i] = len;
	}
	return lps.back();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		string s; cin >> s;
		string _s = s; reverse(s.begin(), s.end());
		if (s == _s) {
			cout << s << "\n";
			continue;
		}
		int n = (int) s.size();
		string ans = "";
		int lp = 0;
		int rp = n-1;
		int k = 0;
		while (lp < rp && s[lp] == s[rp]) {
			k++;
			lp++;
			rp--;
		}
		string left_sub = s.substr(k, n-2*k);
		string right_sub = left_sub; reverse(left_sub.begin(), left_sub.end());
		
		string pre = s.substr(0, k);
		string suf = pre; reverse(suf.begin(), suf.end());
		
		string ans1 = pre + left_sub.substr(0, long_pal_pre(left_sub)) + suf;
		string ans2 = pre + right_sub.substr(0, long_pal_pre(right_sub)) + suf;
	
		if (ans1.length() > ans2.length()) cout << ans1 << "\n";
		else cout << ans2 << "\n";
	}
	return 0;
}
