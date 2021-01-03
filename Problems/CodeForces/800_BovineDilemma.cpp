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
		int cnt = 0;
		vector<int> vals(n);
		set<double> as;
		for (int i = 0; i < n; i++) cin >> vals[i];
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				double a = abs(vals[i] - vals[j]);
				double b = sqrt(vals[i]*vals[i] + 1);
				double c = sqrt(vals[j]*vals[j] + 1);
				if (a + b > c && b + c > a && a + c > b) {
					as.insert(0.5 * a);
				}
					
			}
		}
		printf("%d\n", as.size());
	}
	return 0;
}
