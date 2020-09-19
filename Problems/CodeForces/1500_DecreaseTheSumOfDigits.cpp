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
		unsigned long long n; int s; cin >> n >> s;
		string num = to_string(n);
		int keep = 0;
		int sum = 0;
		for (int i = 0; i < num.length(); i++) {
			int digit = num[i] - '0';
			if ((i == num.length() - 1 && sum + digit == s) || sum + digit < s) {
				keep++;
				sum += digit;
			} else {
				break;
			}
		}
		sum = 0;
		for (int i = 0; i < num.length(); i++) {
			sum += num[i] - '0';
		}
		string ans;
		if (sum <= s) {
			cout << 0 << endl;
			continue;
		}
		if (keep == 0) {
			ans = "1";
			for (int i = 0; i < num.length(); i++) {
				ans += '0';
			}
		} else {
			ans = to_string(stoull(num.substr(0, keep)) + 1);
			while (ans.length() < num.length()) {
				ans += '0';
			}
		}
		ll newVal = stoull(ans);
		if (newVal < n) {
			newVal = stoull(to_string(newVal) + "0");
		}
		cout << newVal - n << endl;

	}
	return 0;
}
