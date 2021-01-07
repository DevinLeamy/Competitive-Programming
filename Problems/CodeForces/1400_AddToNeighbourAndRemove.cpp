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
		int n; cin >> n;
		vector<ll> vals(n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			sum += vals[i];
		}
		
		int ans = INF;
		for (int i = 1; i <= ceil(sqrt(sum)); i++) {
			if (sum % i != 0) continue;
			ll val = sum / i;
			int cnt = 0;
			int total = 0;
			int cur = 0;
			bool works = true;
			for (int j = 0; j < n; j++) {
				total += vals[j];
				cur++;
				if (total > val) {
					works = false;
					break;
				} else if (total == val) {
					cnt += cur - 1;
					cur = 0;
					total = 0;
				}
			}
			if (works)
				ans = min(ans, cnt);
			
			if (sum % (sum / i) != 0) continue;
			val = sum / (sum / i);
			cnt = 0;
			total = 0;
			cur = 0;
			works = true;
			for (int j = 0; j < n; j++) {
				total += vals[j];
				cur++;
				if (total > val) {
					works = false;
					break;
				} else if (total == val) {
					cnt += cur - 1;
					cur = 0;
					total = 0;
				}
			}
			if (works)
				ans = min(ans, cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}
