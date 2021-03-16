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
		vector<int> cnt(101);
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			cnt[a]++;
		}
		int max = 0;
		for (int val : cnt)
			max = std::max(max, val);
		cout << max << endl;
	}
	return 0;
}
