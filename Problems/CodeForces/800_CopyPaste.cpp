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
		int n, k; cin >> n >> k;
		
		vector<int> vals(n);
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			
		}
		int ans = 0;
		while (true) {
			int min = INF;
			int index = -1;
			bool found = false;
			for (int j = 0; j < n; j++) {
				if (vals[j] < min) index = j;
				min = std::min(vals[j], min);
			}
			for (int j = 0; j < n; j++) {
				if  (j == index) continue;
				int times = (k - vals[j]) / min;
				ans += times;
				if (times > 0) found = true;
				vals[j] += times * min;
			}
			if (!found) break;
		}
		cout << ans << endl;
	}
	return 0;
}
