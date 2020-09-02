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
	int a, b, c, d; cin >> a >> b >> c >> d;
	vector<ll> preSum(1500002);
	ll ans = 0;
	for (int i = a; i <= b; i++) {
		preSum[i + b]++;
		preSum[i + c + 1]--;
	}
	for (int i = 1; i <= 1500000; i++) {
		preSum[i] += preSum[i - 1];
	}
	for (int i = 1500000; i >= 0; i--) {
		preSum[i] += preSum[i + 1];
	}
	for (int i = c; i <= d; i++) {
		ans += preSum[i+1];
	}
	cout << ans << endl;
	return 0;
}
