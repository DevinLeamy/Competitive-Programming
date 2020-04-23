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
		int n, x, a;
		cin >> n >> x;
		vector<ll> nums;
		for (int i = 0; i < n; i++) {
			cin >> a;
			nums.pb(a);
		}
		sort(nums.rbegin(), nums.rend());
		
		double total = nums[0];
		int count = 1;
		while (total / (double) count >= x && count != n) {
			total += nums[count];
			count++;
		}
		if (total / (double) count < x) {
			count--;
		}
		cout << count << "\n";
	}
	return 0;
}
