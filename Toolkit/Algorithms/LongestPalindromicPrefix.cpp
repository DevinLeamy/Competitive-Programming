// KMP Algorithm for Longest Palindromic Prefix
#include <string>
#include <vector>

using namespace std;

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
	string test = "abccbagg";
	int result = long_pal_pre(test);
	assert(test.substr(0, result) == "abccba");
}
