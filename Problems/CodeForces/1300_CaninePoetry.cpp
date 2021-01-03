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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		string s; cin >> s;
		int n = (int) s.length();
//		vector<int> dp(n+1);
//		for (int i = 1; i < n; i++) {
//			if (s[i] == s[i-1]) {
//				dp[
//			}
//		}
		int min = 0;
		for (int i = 0; i < n-1; i++) {
			if (i + 2 < n && s[i] == s[i+2] && s[i] != '#' && s[i+2] != '#') {
				s[i+2] = '#';
				min++;
			}
			if (s[i] == s[i+1] && s[i] != '#' && s[i+1] != '#') {
				min++;
				s[i+1] = '#';
			}
		}
		printf("%d\n", min);
	}
	return 0;
}
