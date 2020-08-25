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
		vector<bool> vals(n);
		string s; cin >> s;
		bool right = false;
		bool left = false;
		for (int i = 0; i < n; i++) {
			vals[i] = s[i] == 'R';
			if (vals[i] == true) right = true;
			else left = true;
		}
		if (!right || !left) {
			cout << ceil(n/3.0) << endl;
			continue;
		}
		int ans = 0;
		bool last = vals[0];
		int index = 0;
		while (vals[index] == last) {
			index++;
		}
		last = vals[index];
		int num = 0;
		for (int i = 0; i < n; i++) {
			if (vals[index] == last) {
				num++;
			} else {
				ans += num/3;
				num = 1;
			}
			last = vals[index];
			index = (index + 1)%n;
		}
		ans += num/3;
		cout << ans << endl;
	}
	return 0;
}
