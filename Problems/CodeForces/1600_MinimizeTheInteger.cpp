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
		string n; cin >> n;
		queue<int> even, odd;
		for (int i = 0; i < (int) n.length(); i++) {
			int digit = n[i] - '0';
			if (digit % 2 == 0) even.push(digit);
			else odd.push(digit);
		}
		string ans = "";
		while (!even.empty()) {
			if (odd.empty() || even.front() < odd.front()) {
				ans += to_string(even.front());
				even.pop();
			} else {
				ans += to_string(odd.front());
				odd.pop();
			}
		}
		
		while (!odd.empty()) {
			ans += to_string(odd.front());
			odd.pop();
		}
		
		cout << ans << "\n";
	}
	return 0;
}
