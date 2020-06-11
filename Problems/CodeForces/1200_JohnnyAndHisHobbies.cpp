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
		int n, s;
		cin >> n;
		vector<int> nums(1024);
		int max = -1;
		for (int i = 0; i < n; i++) {
			cin >> s;
			nums[s]++;
			max = std::max(s, max);
		}
		bool found = false;
		for (int i = 1; i <= 1024; i++) {
			vector<int> newSet(max+1);
			for (int j = 0; j <= max; j++) {
				if (nums[j] > 0) {
					int num = j ^ i;
					if (num > max) {
						break;
					}
					newSet[num] += nums[j];
				}
			}
			bool works = true;
			for (int j = 0; j <= max; j++) {
				if (nums[j] != newSet[j]) {
					works = false;
				}
			}
			if (works) {
				cout << i << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "-1" << endl;
		}
	}
	return 0;
}
