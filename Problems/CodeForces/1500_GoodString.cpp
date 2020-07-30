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
		string s; cin >> s;
		if (s.length() == 2) {
			cout << 0 << endl;
			continue;
		}
		vector<int> vals(10);
		int best = (int) s.length() - 2;
		for (int i = 0; i < s.length(); i++) {
			vals[s[i] - '0']++;
			best = min(best, (int)s.length() - vals[s[i] - '0']);
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == j) continue;
				bool iNext1 = true;
				bool iNext2 = false;
				int count1 = 0;
				int count2 = 0;
				for (int k = 0; k < s.length(); k++) {
					int val = s[k] - '0';
					if (s[k] - '0' == i) {
						if (iNext1) {
							iNext1 = !iNext1;
							count1++;
						}
						if (iNext2) {
							iNext2 = !iNext2;
							count2++;
						}
					} else if (s[k] - '0' == j) {
						if (!iNext1) {
							iNext1 = !iNext1;
							count1++;
						}
						if (!iNext2) {
							iNext2 = !iNext2;
							count2++;
						}
					}
				}
				if (!iNext1)
					count1--;
				if (iNext2)
					count2--;
				best = min(best, (int)s.length() - max(count1, count2));
			}
		}
		cout << best << endl;
	}
	return 0;
}
