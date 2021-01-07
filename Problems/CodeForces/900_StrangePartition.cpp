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
		double x; cin >> x;
		vector<double> vals(n);
		double sum = 0;
		ll max = 0;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			sum += vals[i];
			max += ceil(vals[i] / x);
		}
		ll min = ceil(sum / x);
		printf("%lld %lld\n", min, max);
		
	}
	return 0;
}
