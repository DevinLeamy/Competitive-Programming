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
	int n; cin >> n;
	ll sum = 0;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) cin >> vals[i];
	for (ll val : vals) sum += val;
	sort(vals.begin(), vals.end());
	cout << max(vals[n-1], (ll) ceil((double)sum/(double)(n-1))) << endl;
	return 0;
}
