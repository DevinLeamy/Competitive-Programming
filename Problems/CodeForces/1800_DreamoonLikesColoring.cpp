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
	int n, m; cin >> n >> m;
	vector<int> vals(m);
	for (int i = 0; i < m; i++) cin >> vals[i];
	
	bool valid = true;
	ll sum = 0;
	
	for (int i = 0; i < m; i++) {
		sum += vals[i];
		if (n - vals[i] < i)
			valid = false;
	}
	if (sum < n)
		valid = false;
	
	if (!valid) {
		printf("-1");
		return 0;
	}
	
	vector<int> ans(m);
	ans[m-1] = n - vals[m-1] + 1;
	
	int cur = ans[m-1] - 1;
	for (int i = m-2; i >= 0; i--) {
		if (cur > i + 1) {
			int diff = cur - (i + 1);
			int take = min(diff, vals[i] - 1);
			cur -= take;
		}
		ans[i] = cur;
		cur--;
	}
	for (int val : ans)
		printf("%d ", val);
	return 0;
}
