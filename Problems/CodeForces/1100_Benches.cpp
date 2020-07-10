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
	int n, m, a; cin >> n >> m;
	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
		max = std::max(a, max);
	}
	int ans1 = (sum + m)/n + (((sum + m) % n == 0)? 0: 1);
	int ans2 = max + m;
	cout << std::max(ans1, max) << " " << ans2 << endl;
	return 0;
}
