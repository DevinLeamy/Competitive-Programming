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
		ll n; cin >> n;
		set<ll> ans;
		ans.insert(0);
		for (ll i = 1; i * i <= n; i++) {
			ans.insert(n/i);
			ans.insert(i);
		}
		cout << ans.size() << "\n";
		for (auto itr = ans.begin(); itr != ans.end(); itr++) {
			cout << *itr << " ";
		}
		cout << "\n";
	}
	return 0;
}
