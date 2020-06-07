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

int n;
vector<int> ans;
bool backtrack(int pos, int last, vector<bool> taken, vector<int> nums) {
	if (pos == n) {
		ans = nums;
		return true;
	}
	for (int i = max(1, last-4); i <= min(n, last+4); i++) {
		if (!taken[i] && abs(last-i) != 1) {
			taken[i] = true;
			nums[pos] = i;
			if (backtrack(pos+1, i, taken, nums)) {
				return true;
			}
			taken[i] = false;
			nums[pos] = 0;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		cin >> n;
		if (backtrack(0, n, vector<bool>(n+1), vector<int>(n))) {
			for (int num : ans) { cout << num << " "; }
			cout << "\n";
		} else { cout << "-1" << endl; }
	}
	return 0;
}
