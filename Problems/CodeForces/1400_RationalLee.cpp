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
	int t; cin >> t;
	loop(t) {
		int n, k; cin >> n >> k;
		ll a;
		vector<ll> vals;
		vector<ll> fri;
		for (int i = 0; i < n; i++) { cin >> a; vals.pb(a); }
		for (int i = 0; i < k; i++) { cin >> a; fri.pb(a); }
		sort(vals.begin(), vals.end());
		sort(fri.begin(), fri.end());
		ll total = 0;
		int index = n-1;
		int bottom = 0;
		int l = 0;
		while(l != k && fri[l] == 1) {
			total += vals[index] * 2;
			index--;
			l++;
		}
		for (int i = k-1; i >= 0; i--) {
			if (fri[i] != 1) {
				total += vals[index] + vals[bottom];
				bottom += fri[i] - 1;
				index--;
			}
		}
		cout << total << endl;
	}
	return 0;
}
