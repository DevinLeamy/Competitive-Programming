#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n, p, c;
		vector<PI> nums;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p >> c;
			nums.pb({p, c});
		}
		PI last = {0, 0};
		bool valid = true;
		for (int j = 0; j < n; j++) {
			PI newS = nums[j];
			if (newS.second - last.second > newS.first - last.first) {
				valid = false;
				break;
			} else if (newS.first < last.first) {
				valid = false;
				break;
			} else if (newS.second < last.second) {
				valid = false;
				break;
			}
			last = newS;
		}
		if (valid) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
