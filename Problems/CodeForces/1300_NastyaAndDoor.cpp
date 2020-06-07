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
		int n, k, a;
		vector<ll> nums;
		vector<bool> peak;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a;
			nums.push_back(a);
			peak.push_back(false);
		}
		nums.push_back(LINF);
		
		int count = 0;
		for (int i = 1; i < k; i++) {
			if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
				peak[i] = true;
				if (i < k-1) {
					count++;
				}
			}
		}
		int best = count;
		int left = 0;
		for (int i = k; i < n; i++) {
			if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
				peak[i] = true;
			}
			if (peak[i-1]) {
				count++;
			}
			if (peak[i-k+1]) {
				count--;
			}
			if (count > best) {
				left = i - k + 1;
				best = count;
			}
		}
		cout << best + 1 << " " << left + 1 << "\n";
	}
	return 0;
}
