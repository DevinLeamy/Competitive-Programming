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
		vector<int> cnt(10);
		for (int i = 0; i < 10; i++) cin >> cnt[i];
		int min = cnt[0] + 1;
		int val = 0;
		for (int i = 9; i >= 1; i--) {
			if (cnt[i] + 1 <= min) {
				min = cnt[i] + 1;
				val = i;
			}
		}
		string ans = (val == 0)? "1" : "";
		for (int i = 0; i < min; i++) ans += to_string(val);
		cout << ans << "\n";
	}
	return 0;
}
